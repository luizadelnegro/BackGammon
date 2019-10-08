#if ! defined ( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Tabuleiro
*  Arquivo gerado:              TABULEIRO.H
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: irf	- Iago Ribeiro Farroco
*			ldn - Luiza Del Negro
*			dwl - Daniel Weil Lins
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		1.00   irf	 31/04/2019  Criação do módulo Tabuleiro e algumas funções.
*
*  $ED Descrição do módulo
*	Módulo que representa o tabuleiro e todos os seus componentes.
*	
*
*
*
*
***************************************************************************/

#if defined( TABULEIRO_OWN )
#define TABULEIRO_EXT
#else
#define TABULEIRO_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condições de retorno
*
*
***********************************************************************/

   typedef enum {

        TAB_CondRetOK = 0,
               /* Concluiu corretamente */

        TAB_CondRetFaltouMemoria = 1,
			   /* Faltou Memoria */

		TAB_CondRetTrianguloBloqueado = 2,
			   /* Triângulo já possui pelo menos duas peças de outra cor nele */

		TAB_CondRetPecaNaoEncontrada = 3,
			   /* Não existe peça da cor especificada no triângulo */

		TAB_CondRetJogadorPretoVenceu = 4,
			   /* Jogador que manipula as peças pretas ganhou o jogo */

		TAB_CondRetJogadorVermelhoVenceu = 5,
			   /* Jogador que manipula as peças vermelhas ganhou o jogo */

		TAB_CondRetJogoNaoAcabou = 6,
			   /* Jogo ainda não acabou */

		TAB_CondRetNumeroDaCasaInvalido = 7,

		TAB_CondRetAindaExistePecaNaBarra = 8,

		TAB_CondRetNaoJogadorNaoPossuiPecaNaBarra = 9,

		TAB_CondRetNemTodasAsPecasEstaoNoQuadranteFinal = 10,

   } TAB_tpCondRet ;


/**************************************************************************

	Apelido para a estrutura casa

***************************************************************************/
  
   typedef struct casa Casa ;

/**************************************************************************

	Apelido para a estrutura tabuleiro

***************************************************************************/
   
   typedef struct tabuleiro Tabuleiro ;


/*************************************************************************
*
*  $FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Move a peça da casa inicial para a casa de destino.
*	
*  $EP Parâmetros:
*     $P casaInicial - é o número da casa que a peça se encontra no começo do turno.
*     $P casaDestino - é o número da casa que vai receber a peça movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam números entre 1 e 24.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet movePeca( int casaInicial, int casaDestino ) ;

/*************************************************************************
*
*  $FC Função: TAB Monta Tabuleiro
*
*  $ED Descrição da função
*     Monta o tabuleiro com todas as casa, todos os triângulos e todas as peças na posição inicial de jogo.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet montaTabuleiro( ) ;

/*************************************************************************
*
*  $FC Função: TAB Destrói Tabuleiro
*
*  $ED Descrição da função
*     Libera a memória alocada para a estrutura tabuleiro.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet destroiTabuleiro( ) ;

/*************************************************************************
*
*  $FC Função: TAB Verifica Fim do Jogo
*
*  $ED Descrição da função
*     Verifica se o jogo já acabou e denomina um vencedor.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet fimDoJogo( ) ;









/*************************************************************************
*
*  $FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Move a peça da casa inicial para a casa de destino.
*	
*  $EP Parâmetros:
*     $P casaInicial - é o número da casa que a peça se encontra no começo do turno.
*     $P casaDestino - é o número da casa que vai receber a peça movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam números entre 1 e 24.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet qtdPecaTabuleiro( int nCasa, int* qtdPreto, int* qtdVermelho ) ;

/*************************************************************************
*
*  $FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Move a peça da casa inicial para a casa de destino.
*	
*  $EP Parâmetros:
*     $P casaInicial - é o número da casa que a peça se encontra no começo do turno.
*     $P casaDestino - é o número da casa que vai receber a peça movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam números entre 1 e 24.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet qtdPecaBarra( int* qtdPreto, int* qtdVermelho );

/*************************************************************************
*
*  $FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Move a peça da casa inicial para a casa de destino.
*	
*  $EP Parâmetros:
*     $P casaInicial - é o número da casa que a peça se encontra no começo do turno.
*     $P casaDestino - é o número da casa que vai receber a peça movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam números entre 1 e 24.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet qtdPecaFinalizadas( int* qtdPreto, int* qtdVermelho );

/*************************************************************************
*
*  $FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Move a peça da casa inicial para a casa de destino.
*	
*  $EP Parâmetros:
*     $P casaInicial - é o número da casa que a peça se encontra no começo do turno.
*     $P casaDestino - é o número da casa que vai receber a peça movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam números entre 1 e 24.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet criaTabuleiro();

/*************************************************************************
*
*  $FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Move a peça da casa inicial para a casa de destino.
*	
*  $EP Parâmetros:
*     $P casaInicial - é o número da casa que a peça se encontra no começo do turno.
*     $P casaDestino - é o número da casa que vai receber a peça movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam números entre 1 e 24.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/
   
   TAB_tpCondRet addPeca(int numeroCasa, int cor);

/*************************************************************************
*
*  $FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Move a peça da casa inicial para a casa de destino.
*	
*  $EP Parâmetros:
*     $P casaInicial - é o número da casa que a peça se encontra no começo do turno.
*     $P casaDestino - é o número da casa que vai receber a peça movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam números entre 1 e 24.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/
   
   void addCasaComTriangulo();

/*************************************************************************
*
*  $FC Função: TAB Move Peça
*
*  $ED Descrição da função
*     Move a peça da casa inicial para a casa de destino.
*	
*  $EP Parâmetros:
*     $P casaInicial - é o número da casa que a peça se encontra no começo do turno.
*     $P casaDestino - é o número da casa que vai receber a peça movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam números entre 1 e 24.
*
*  $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   void qtdPecaCasa(int nCasa, int*qtd, int* cor);

#undef TABULEIRO_EXT


/********** Fim do módulo de definição: Módulo Tabuleiro **********/


#else
#endif