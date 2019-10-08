#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <Windows.h>
#include <locale.h>
#include <time.h>

#include "TABULEIRO.h"
#include "LISTA.H"
#include "dado.h"
#include "dadopontos.h"
#include "BARRA.H"
#include "PECAS_FINALIZADAS.H"

#define JOGO_OWN
#undef JOGO_OWN

#ifdef _WIN32
#define clear() system("cls")
#elif defined __unix__
#define clear() system("clear")
#elif defined __APPLE__
#define clear() puts("\x1b[H\x1b[2J")
#endif

#define NEW_GAME 0
#define LOAD_GAME 1
#define EXIT 2

#define ENTER_KEY 13

void newGame();
void game(int jogadorInicial, int dadoUm, int dadoDois);
void printBoard();
void SalvarPartida(char* jogadorAtual);
void CarregarPartida(void);

void resetColor(){
    printf("\033[0m");
}

void printRed(){
    printf("\033[1;31m");
}

void printBlue(){
    printf("\033[0;36m");
}

void printHomeScreen(int selectedOption, int optionIndex, char* optionText){
    if(selectedOption == optionIndex) printRed();
    printf("%s", optionText);
    resetColor();
}
void homeScreen(){
    int inputKey = -1;
	int actualKey = -1;
    int selectedOption = 0;
    while(inputKey != ENTER_KEY){
        printf("Gamao\n");
        printHomeScreen(selectedOption, NEW_GAME, "Novo Jogo\n");
        printHomeScreen(selectedOption, LOAD_GAME, "Continuar Jogo\n");
        printHomeScreen(selectedOption, EXIT, "Sair\n");
        inputKey = getch();
        clear();
        if(inputKey == 0xE0){
            actualKey = getch();
            if(actualKey == 80) selectedOption++;
            else if(actualKey == 72) selectedOption--;          
        }
        if(selectedOption == 3) selectedOption = 0;
        else if(selectedOption == -1) selectedOption = 2;
        
    }
    switch (selectedOption)
    {
        case NEW_GAME: newGame(); break;
        case LOAD_GAME: CarregarPartida(); break; //loadGame();
        case EXIT: exit(0); 
    }
}

void newGame(){
    int inicio = 1;
    TAB_tpCondRet cond;
    DD_tpCondRet condDado;
    PTS_tpCondRet condDadosPontos;
    int jogadorUm, jogadorDois;
    int jogadorInicial;

	condDadosPontos = PTS_CriaDadoPontos();

	if (condDadosPontos != 0) return;
    
	jogadorUm = 0;
	jogadorDois = 0;

    clear();
    while(jogadorUm == jogadorDois){
        printf("Aperte qualquer tecla para jogar os dados e decidir quem comecar.\n");
        getch();
        clear();
        condDado = DD_DadoSimples(&jogadorUm, &jogadorDois);
        if (condDado == 1){
            printf("Os dados empataram com o valor: %d.\n", jogadorUm);
        }
        else if (condDado != 0) return;
        else if(jogadorUm > jogadorDois){
            printf("Os valores dos dados foram %d, e %d. O jogador com as pecas vermelhas comecara a partida.\n", jogadorUm, jogadorDois);
            jogadorInicial = 1;
        }
        else{
            printf("Os valores dos dados foram %d e %d. O jogador com as pecas azuis comecara a partida.\n", jogadorUm, jogadorDois);
            jogadorInicial = 2;
        }
    }
    printf("Aperte qualquer tecla para iniciar o jogo.");
    getch();
    clear();
	
    cond = montaTabuleiro();
    if(cond != 0) {
        printf("Erro ao montar o tabuleiro");
        return;
    }
    game(jogadorInicial, jogadorUm, jogadorDois, inicio);
}


char* switchPlayer(char* player){
    if(strcmp(player, "Vermelho") == 0){
        return "Azul";
    }
    else{
        return "Vermelho";
    }
}

void game(int jogadorInicial, int dadoUm, int dadoDois, int inicio){
    int cond, cond2;
    int condDado;
    int condDadoPontos;
    int jogoAcabou;
	int pontuacao;
    char* corJogador;
	int ultimaDobra;
    char respostaDobra, respostaSalva;
    int destinySpot;
    int qtdPecaAzul, qtdPecaVermelha; 
    int chosenDice, otherDice, chosenSpot, qtdBarraV, qtdBarraA, contador;
    
	condDado = -1;

	jogoAcabou = 6;

	corJogador = jogadorInicial == 1 ? "Vermelho" : "Azul";
    
	while(jogoAcabou == 6){
        cond = -1, cond2 = -1;
        chosenDice = 0, otherDice = 0, chosenSpot = 0;
        printBoard();
        qtdCadaJogadorBarra(&qtdBarraA, &qtdBarraV);
        if(inicio != 1){
            printf("Voce deseja salvar a partida? (S/N)");
            setbuf(stdin, NULL);
            scanf("%c", &respostaSalva);
            if(respostaSalva == 'S' || respostaSalva == 's'){
                SalvarPartida(corJogador);
                printf("Seu jogo foi salvo.");
                system("pause");
            }
            
			PTS_QuemDobra(&ultimaDobra);
            if (strcmp(corJogador, "Azul") == 0 && ultimaDobra != 0){
                printf("Voce deseja dobrar o valor da partida? (S/N).\n");
                setbuf(stdin, NULL);
                scanf("%c", &respostaDobra);
                if(respostaDobra == 'S' || respostaDobra == 's'){
                    condDadoPontos = PTS_DobraDadoPontos(0);
                    PTS_ObtemPontos(&pontuacao);
					if (condDadoPontos == 0){
                        printf("A partida agora esta valendo %d ponto(s).\n", pontuacao);
                    }
                    else if (condDadoPontos == 3){
                        printf("A partida nao pode ser dobrada pois ja esta com o valor maximo.\n", pontuacao);
                    }
                    system("pause");
                }
                clear();
                printBoard();
            }
            
            else if (strcmp(corJogador, "Vermelho") == 0 && ultimaDobra != 1){
                printf("Voce deseja dobrar o valor da partida? (S/N).\n");
                setbuf(stdin, NULL);
                scanf("%c", &respostaDobra);
                if(respostaDobra == 'S' || respostaDobra == 's'){
                    condDadoPontos = PTS_DobraDadoPontos(1);
					PTS_ObtemPontos(&pontuacao);
                    if (condDadoPontos == 0){
                        printf("A partida agora esta valendo %d ponto(s).\n", pontuacao);
                    }
                    else if (condDadoPontos == 3){
                        printf("A partida nao pode ser dobrada pois ja esta com o valor maximo.\n", pontuacao);
                    }
                    system("pause");
                }
                clear();
                printBoard();
            }
            clear();
            printBoard();
            printf("Aperte qualquer tecla para sortear os dados.\n");
            getch();
            clear();
            printBoard();
            condDado = DD_DadoSimples(&dadoUm, &dadoDois);
            if(condDado == 1){
                printf("Seus dados empataram com o valor: %d. Agora eles valem o dobro do valor em cada dado.\n", dadoUm);
                dadoUm = 2*dadoUm;
                dadoDois = 2*dadoDois;
            } 
            dadosNovos:
            if(condDado != 0 && condDado != 1) return;
            else if(((strcmp(corJogador, "Azul") == 0) && qtdBarraA > 0) || ((strcmp(corJogador, "Vermelho") == 0) && qtdBarraV > 0)){
                printf("Jogador %s, voce possui peca(s) na barra. Você deve andar com ela(s) primeiro.\n", corJogador);
                printf("Jogador %s, seus dados sao %d e %d. Escolha qual o valor do dado que quer comecar.\n", corJogador, dadoUm, dadoDois);
            }
            else{
                printf("Jogador %s, seus dados sao %d e %d. Escolha qual o valor do dado que quer comecar.\n", corJogador, dadoUm, dadoDois);            
            }   
        }
        else if(condDado == 1){}
        else{
            clear();
            printBoard();
            printf("Jogador %s, seus dados sao %d e %d. Escolha qual o valor do dado que quer comecar.\n", corJogador, dadoUm, dadoDois);            
        }
        while(1){
            if(condDado != 1){
                setbuf(stdin, NULL);
                scanf("%d", &chosenDice);
                if(chosenDice != dadoUm && chosenDice != dadoDois){
                    printf("Valor escolhido nao corresponde aos valores dos dados sorteados.\n");
                }
                else{
                    if(chosenDice == dadoUm){
                        otherDice = dadoDois;
                    }
                    else{
                        otherDice = dadoUm;
                    }
                    break;
                }
            }
            else{
                chosenDice = dadoUm;
                otherDice = dadoDois;
                system("pause");
                break;
            }
        }
        while(cond != 0){
            clear();
            printBoard();
            Escolha:
            setbuf(stdin, NULL);            
            if(((strcmp(corJogador, "Azul") == 0) && qtdBarraA > 0) || ((strcmp(corJogador, "Vermelho") == 0) && qtdBarraV > 0)){
                printf("Jogador %s, aperte qualquer tecla + Enter para andar com uma peca da barra (Aperte -1 para escolher novamente o dado ou -2 para passar a vez.\n", corJogador);
                scanf("%d", &chosenSpot);
                if(chosenSpot == -1){
                    clear();
                    printBoard();
                    goto dadosNovos;
                }
                if(chosenSpot == -2) goto pularVez;
                
                if(strcmp(corJogador, "Azul") == 0){
                    chosenSpot = 25;
                }
                else{
                    chosenSpot = 0;
                }
            }
            else{
                if(condDado == 1){
                    printf("Jogador %s, escolha o numero da casa para andar %d vezes \ncom uma peca e aperte a tecla Enter. (Aperte -2 para pular\n sua vez)\n", corJogador, chosenDice);
                    scanf("%d", &chosenSpot);
                    if(chosenSpot == -2) goto pularVez;   
                }
                else{
                    printf("Jogador %s, escolha o numero da casa para andar %d vezes \ncom uma peca e aperte a tecla Enter. (Aperte -1 para \nescolher o dado novamente ou -2 para pular sua vez)\n", corJogador, chosenDice);
                    scanf("%d", &chosenSpot);
                    if(chosenSpot == -1) goto dadosNovos;
                    if(chosenSpot == -2) goto pularVez;                    
                }
            }
            if(strcmp(corJogador, "Vermelho") == 0){
                destinySpot = chosenSpot + chosenDice;
            }
            else{
                destinySpot = chosenSpot - chosenDice;
            }
            
            if (destinySpot > 24 || destinySpot < 1) destinySpot = 26;
            cond = movePeca(chosenSpot, destinySpot);
            
            if (cond == 0 && chosenSpot == 0){
                qtdBarraV--;
            }
            else if(cond == 0 && chosenSpot == 25){
                qtdBarraA--;
            }
            if(cond == 7){
                printf("Numero da casa invalido.\n");
                system("pause");
            }
            else if(cond == 2){
                printf("Casa destino bloqueada.\n");
                system("pause");
            }
            else if(cond == 3){
                printf("Peca nao encontrada.\n");
                system("pause");
            }
         }
        while(cond2 != 0){
            clear();
            printBoard();
            Escolha2:
            jogoAcabou = fimDoJogo();
            if (jogoAcabou == 4 || jogoAcabou == 5) goto final;
            setbuf(stdin, NULL);
            if(((strcmp(corJogador, "Azul") == 0) && qtdBarraA > 0) || ((strcmp(corJogador, "Vermelho") == 0) && qtdBarraV > 0)){
                printf("Jogador %s, aperte qualquer tecla + Enter para andar com uma peca da barra. (Aperte -2 para pular sua vez.\n", corJogador);
                scanf("%d", &chosenSpot);
                if(chosenSpot == -2) goto pularVez;
                
                if (cond == 0 && chosenSpot == 0){
                    qtdBarraV--;
                }
                else if(cond == 0 && chosenSpot == 25){
                    qtdBarraA--;
                }
                
                if(strcmp(corJogador, "Azul") == 0){
                    chosenSpot = 25;
                }
                else{
                    chosenSpot = 0;
                }
            }
            else{
                printf("Jogador %s, escolha o numero da casa para andar %d vezes \ncom uma peca e aperte a tecla Enter. (Aperte -2 para pular\n sua vez)\n", corJogador, otherDice);
                scanf("%d", &chosenSpot);
                if(chosenSpot == -2) goto pularVez;
            }  
            if(strcmp(corJogador, "Vermelho") == 0){
                destinySpot = chosenSpot + otherDice;
            }
            else{
                destinySpot = chosenSpot - otherDice;
            }
            if (destinySpot > 24) destinySpot = 27;
            else if (destinySpot < 1) destinySpot = 26;
           
            cond2 = movePeca(chosenSpot, destinySpot);
            printf("%d", cond2);
            
            if(cond2 == 7){
                printf("Numero da casa invalido.");
                system("pause");
            }
            else if(cond2 == 2){
                printf("Casa destino bloqueada.");
                system("pause");
            }
            else if(cond2 == 3){
                printf("Peca nao encontrada.");
                system("pause");
            }
        }
        pularVez:
        corJogador = switchPlayer(corJogador);
        clear();
        printBoard();
        printf("A sua vez acabou. %s, aperte qualquer tecla para comecar a sua vez.\n", corJogador);
        getch();
        inicio = 0;
        jogoAcabou = fimDoJogo();
        clear();
    }
    final:
    if (jogoAcabou == 4) printf("O jogador Preto venceu.\n");
    else if (jogoAcabou == 5) printf("O jogador Vermelho venceu. \n");
}

void printLevelWithPiece(char color){
    printf("|");
    if (color == 'r') printRed();
    else printBlue();
    printf("o");
    resetColor();
    printf("| ");
}
void printLevelWithoutPiece(){
    printf("| | ");
}

void printEachLevel(int level, int nCasa){
    int bluePieces;
    int redPieces;
    int sum;
	char color;

    TAB_tpCondRet cond = qtdPecaTabuleiro(nCasa, &bluePieces, &redPieces);
    if (cond != 0) return;
	color = bluePieces > redPieces ? 'b' : 'r';
    sum = bluePieces + redPieces;
    if (sum > 5 && sum < 10){
        printf("|");
        if (color == 'b') printBlue();
        else printRed();        
        printf("%d", sum);
        resetColor();
        printf("| ");
    }
    else if (sum >= 10){
        printf("|");
        if (color == 'b') printBlue();
        else printRed();        
        printf("%d", sum);
        resetColor();
        printf("|");
    }
    else if (sum >=level){
        printLevelWithPiece(color);
    }
    else{
        printLevelWithoutPiece();
    }

}

void printBoard(){
    int i, level, nCasa, qtdBarraA, qtdBarraV, qtdFinalizadaA, qtdFinalizadaV, pontuacao;
    wchar_t overline;

    qtdCadaJogadorBarra(&qtdBarraA, &qtdBarraV);
    qtdPecasFinalizadasJogador(&qtdFinalizadaA, &qtdFinalizadaV);
    printf("/-------------------------------------------------------\\    Pecas Azuis Finalizadas: %d\n", qtdFinalizadaA);
    printf("| ");
    for(i = 13; i<19;i++){
      printf("%d  ", i);
    }
    printf("|   |");
    for(i = 19; i<25;i++){
      printf("  %d", i);
    }
    printf(" ");
    printf("|    Pecas Vermelhas Finalizadas: %d\n", qtdFinalizadaV);
	PTS_ObtemPontos(&pontuacao);
    printf("|-------------------------------------------------------|    Partida esta valendo: %d Pontos\n", pontuacao);
    
    printf("|  _   _   _   _   _   _         _   _   _   _   _   _  |\n");
    for(level = 1; level < 6; level++){
        for(nCasa = 13; nCasa < 19; nCasa++){
            if (nCasa == 13) printf("| ");
            printEachLevel(level, nCasa);
        }
        printf("=   = ");
        for(nCasa = 19; nCasa < 25; nCasa++){
            printEachLevel(level, nCasa);
        }
        printf("|\n");
    }
    printf("|                         |");
        
    if(qtdBarraA == 0){
        printf("   ");
    }
    else if(qtdBarraA == 1){
        printBlue();
        printf(" o ");
        resetColor();
    }
    else if(qtdBarraA == 2){
        printBlue();
        printf("oo ");
        resetColor();
    }
    else if(qtdBarraA == 3){
        printBlue();
        printf("ooo");
        resetColor();
    }
    else{
        printBlue();
        printf(" %d ", qtdBarraA);
        resetColor();
    }
    
    printf("|                         |\n");
    
    printf("|                         |");
        
    if(qtdBarraV == 0){
        printf("   ");
    }
    else if(qtdBarraV == 1){
        printRed();
        printf(" o ");
        resetColor();
    }
    else if(qtdBarraV == 2){
        printRed();
        printf("oo ");
        resetColor();
    }
    else if(qtdBarraV == 3){
        printRed();
        printf("ooo");
        resetColor();
    }
    else{
        printRed();
        printf(" %d ", qtdBarraV);
        resetColor();
    }
    
    printf("|                         |\n");

    for(level = 5; level > 0; level--){
        for(nCasa = 12; nCasa > 6; nCasa--){
            if (nCasa == 12) printf("| ");
            printEachLevel(level, nCasa);
        }
        printf("=   = ");
        for(nCasa = 6; nCasa > 0; nCasa--){
            printEachLevel(level, nCasa);
        }
        printf("|\n");
    }
    
    setlocale(LC_CTYPE, "");
    overline = 0x00AF;
    printf("|");
    for(i = 0; i < 6; i++){
        wprintf(L" %lc%lc%lc", overline, overline, overline);
    }
    printf("      ");
    for(i = 0; i < 6; i++){
        wprintf(L" %lc%lc%lc", overline, overline, overline);
    }
    printf(" |");
    printf("\n");
    printf("|-------------------------------------------------------|\n");
    printf("| ");
    for(i = 12; i > 6; i--){
      printf("%02d  ", i);
    }
    printf("|   |");
    for(i = 6; i > 0;i--){
      printf("  %02d", i);
    }
    printf(" ");
    printf("|\n");
    printf("\\-------------------------------------------------------/\n");
}

void SalvarPartida(char* jogadorAtual)
{
    int jogadorInicio;
	int  pontos;
	int quemdobra;
	int i;
	int f_qtdP=0;
	int f_qtdV=0;
	int b_qtdP = 0;
	int b_qtdV = 0;
	FILE * file = fopen("partida.txt", "w");

	if (file == NULL) {
		printf("Não foi possível criar o arquivo!\n");
		return;
	} /* if */
    
    /* Salva quem foi o ultimo jogador a jogar*/
    jogadorInicio = strcmp(jogadorAtual, "Vermelho") == 0 ? 1 : 2;
    fprintf(file, "%d\n", jogadorInicio);
    
	/* Salva pontuacao da partida e ultimo que dobrou*/
	PTS_ObtemPontos(&pontos);
	fprintf(file, "%d\n", pontos);
	PTS_QuemDobra(&quemdobra);
	fprintf(file, "%c\n", quemdobra);

	/* Grava a quantidade de peças finalizadas de cada jogador */

	qtdPecasFinalizadasJogador(&f_qtdP, &f_qtdV);
	fprintf(file, "%d\n%d\n", f_qtdV, f_qtdP);

	/* Grava a quantidade de peças na barra de cada jogador */

	qtdCadaJogadorBarra(&b_qtdP, &b_qtdV);
	fprintf(file, "%d\n%d\n", b_qtdP, b_qtdV);

	/* Quantidade de peças no tabuleiro */
	for (i = 1; i <= 24; i++) {
	   int quantidade;
       int cor;
       int qtdCorA;
       int qtdCorV;
       qtdPecaTabuleiro(i, &qtdCorA, &qtdCorV);
       if (qtdCorA == 0 && qtdCorV == 0) {
           cor = 2;
           quantidade = 0;
       }
       else if (qtdCorA == 0){
            cor = 1;
            quantidade = qtdCorV;
       }
       else if (qtdCorV == 0){
            cor = 0;
            quantidade = qtdCorA;
       }
	   fprintf(file, "%d\n", i);
	   fprintf(file, "%d\n", cor);
	   fprintf(file, "%d\n", quantidade);
	} 


	fclose(file);

} /* Fim função: JOGO Salvar partida */

void CarregarPartida(void)
{
    int dadosNaoUsados = 0;
    int inicio = 0;
    int jogadorInicial;
	int i, j;
/*Para DadoPontos*/
	int pontos;
	char ultimoquedobrou;
    char newLine;
/*Para Pecas Finalizadas*/
	int f_qtdP = 0;
	int f_qtdV = 0;
/*Para Pecas na barra*/
	int b_qtdP = 0;
	int b_qtdV = 0;
/*Para inicializar funcao de criaTabuleiro*/
	int condRet=0; 
/*Para o Tabuleiro*/

	int ncasa=0;
	int cor=2;
	int t_qtd = 1;
	int t_qtdP = 0;
	int t_qtdV = 0;


	FILE * f = fopen("partida.txt", "r");//abre arquivo para ler

	if (f == NULL) {
		printf("Não foi possível abrir o arquivo!\n");
		return;
	} /* if */
    
    /*le o quem foi o ultimo a jogar*/
    if (fscanf_s(f, "%d\n", &jogadorInicial, &newLine) != 1) {
		printf("erro na leitura \n");
    }

	PTS_CriaDadoPontos();
    /*le o valor da partida e o ultimo que dobrou*/
    if (fscanf_s(f, "%d\n%c\n", &pontos, &ultimoquedobrou) != 2) {
		printf("erro na leitura \n");
    }
	/*insere valores em dado pontos*/
	PTS_InsereValores(ultimoquedobrou, pontos);


	/* Criando o tabuleiro*/
	condRet=criaTabuleiro();// cria um novo Tabuleiro
	criaBarra();
	criaFinalizadas();

	if (condRet == 1){//verifica se o tabuleiro foi criado corretamente
		return ;
	}

	///* recupera a quantidade de peças finalizadas de cada jogador */
	if (fscanf_s(f, "%d\n%d\n", &f_qtdV, &f_qtdP) != 2) {
		printf("erro na leitura \n");
	
			}
	////COMO COLOCAR AS PEÇAS FINALIZADAS?
	for (i = 0; i < f_qtdV; i++) {
		adicionaPecaFinalizadas(1);
	}
	for (i = 0; i < f_qtdP; i++) {
		adicionaPecaFinalizadas(0);
	}

	/* recupera a quantidade de peças na barra de cada jogador */
	if (fscanf_s(f, "%d\n%d\n", &b_qtdP, &b_qtdV) != 2) {
		printf("erro na leitura \n");
	}
	////COMO COLOCAR AS PEÇAS NA BARRA?
	for (i = 0; i < b_qtdV; i++) {
		adicionaPecaBarra(1);
	}
	for (i = 0; i < f_qtdP; i++) {
		adicionaPecaBarra(0);
	}

	/* recupera a quantidade de peças no tabuleiro */
/* Lê a quantidade de peças e a cor de cada posição do tabuleiro */

	for (i = 0; i < 24; i++) {
		addCasaComTriangulo();
	}
	for (j = 0; j < 24; j++) {
		if (fscanf_s(f, "%d \n %d \n %d \n", &ncasa, &cor, &t_qtd) != 3) {
			printf("erro na leitura \n");
		}
		if(cor==1) {
			for (i = 0; i < t_qtd;i++) {
				condRet=addPeca(ncasa, 1);
		
			}
		}
		if (cor == 0) {
			for (i = 0; i < t_qtd; i++) {
				condRet = addPeca(ncasa, 0);
			}
		}
	}
	
		/* Todos os dados foram lidos sem erro, altera os parâmetros do jogo */
    printf("Aperte qualquer tecla para iniciar o jogo.");
    getch();
    clear();
    game(jogadorInicial, dadosNaoUsados, dadosNaoUsados, inicio);
	 /* Fim função: JOG Carregar partida */
}