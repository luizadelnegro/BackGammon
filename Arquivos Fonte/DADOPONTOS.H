#if ! defined ( DADOPTS_ )
#define DADOPTS_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Dado Pontos
*  Arquivo gerado:              DADOPONTOS.H
*  Letras identificadoras:      PTS
*
*  Nome da base de software:    jogo de gamao
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: ldn	- Luiza Del Negro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		1.00   ldn	 26/04/2019 Inicio e fim do desenvolvimento do modulo dado pontos.
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para simular 
*     a representacao de um dado de pontos, o jogador que dobra os pontos e a pontuacao do jogo.. 
*	  O dado eh multiplicado quando o jogador desejar, o mesmo jogados nao pode dobrar o valor 
*	  dos dados vezes seguidas. Armazenamos o valor atual da partida e a pontuacao de cada jogador.
*
***************************************************************************/
#if defined( DADOPTS_OWN )
#define DADOPTS_EXT
#else
#define DADOPTS_EXT extern
#endif


typedef struct tgDadoPontos tpDadoPontos;


/***********************************************************************
*
*  $TC Tipo de dados: PTS Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

      PTS_CondRetOK ,
            /* Executou correto */
      PTS_CondRetErro ,
            /* Ocorreu um erro */

      PTS_CondRetRepetiu ,
            /* Jogador tentou repetir a dobra */
 
      PTS_CondRetDobraMaxima,
            /* Jogo atingiu valor maximo */

      PTS_CondRetFaltouMemoria ,
            /* Faltou memória ao alocar dados */

   } PTS_tpCondRet ;

   /***********************************************************************
*
*  $FC Função: PTS CriaDado Pontos
*
*  $ED Descrição da função
*     Cria um struct para dado pontos
*
*  $EP Parâmetros
*	Ponteiro de ponteiro para um struct de dado de pontos
*
*  $FV Valor retornado
*	DD_CondRetOK 
*	DD_CondRetFaltouMemoria 
*
*  $AE Assertivas de entrada
*     É necessário que exista um struct de dado e que a funcao receba um ponteiro para ele.
*
*  $AS Assertivas de saida
*	Se PTS_CondRetOK : Struct criado com sucesso
*	Se PTS_CondRetFaltouMemoria : Nao ha espaco suficiente

*
***********************************************************************/

PTS_tpCondRet PTS_CriaDadoPontos( );
/***********************************************************************
*
*  $FC Função: PTS  Destroi Dado Pontos
*
*  $ED Descrição da função
*     Deleta um struct para dado de pontos(fim de partida)
*
*  $EP Parâmetros
*	Ponteiro de ponteiro para um struct de dado de pontos
*
*  $FV Valor retornado
*
*	$AE Assertivas de entrada
*		O struct a ser excluido tem que existir 
*
*	$AS	Assertivas de saida
*		Funcao ocorreu conforme esperado
*
***********************************************************************/


void PTS_DestroiDadoPontos( );

/***********************************************************************
*
*  $FC Função: PTS  Dobra Dado Pontos
*
*  $ED Descrição da função
*     Se for possivel, sobra o valor do dado, o que altera o valor da partida.
*
*  $EP Parâmetros 
*	ponteiro de ponteiro para uma struct de dados pontos, caracter
*
*  $FV Valor retornado
*	PTS_CondRetOK 
*	PTs_CondRetErro
*     PTS_CondRetRepetiu
*     PTS_CondRetDobraMaxima
*
*  $AE Assertivas de entrada
*	O struct a ser utilizado tem que existir
*	A funcao tambem deve receber na forma de um char quem esta dobrando
*
*  $AS  Assertivas de saida
*     Se PTS_CondRetOK : Funcao ocorreu conforme esperado. Valor do dado foi dobrado, valor da partida foi alterado e 
*                        o jogador que dobrou na vez foi alterado
*     Se PTS_CondRetRepetiu  : Alteracoes nao foram feitas pois o mesmo jogador nao pode dobrar o dado vezes seguidas
*     Se PTS_CondRetDobraMaxima : Alteracoes nao foram feitas uma vez que se atingiu o valor maximo da partida
*
*	Se PTs_CondRetErro : Nao havia struct a ser utilizado
***********************************************************************/

PTS_tpCondRet PTS_DobraDadoPontos( int quemdobra );


/***********************************************************************
*
*  $FC Função: PTS Obtem Pontos de Dado Pontos
*
*  $ED Descrição da função
*     Se for possivel, obtem o valor de pontos da partida.
*
*
*  $EP Parâmetros
*	Ponteiro para ponteiro de uma struct de Dado pontos e ponteiro para um inteiro.
*
*  $FV Valor retornado
*	PTS_CondRetOK 
*	PTs_CondRetErro
*
*  $AE Assertivas de entrada
*	O struct a ser utilizado tem que existir e nao ser vazio.
*	O ponteiro para inteiro em que o valor da partida sera armazenado tem que existir.
*
*  $AS  Assertivas de saida
*     Se PTS_CondRetOK : Funcao ocorreu conforme esperado.O valor da partida foi resgatado.
*	Se PTs_CondRetErro : Nao havia struct a ser utilizado
*
***********************************************************************/

PTS_tpCondRet PTS_ObtemPontos( int* Pontuacao );


/***********************************************************************
*
*  $FC Função:  PTS Quem dobra
*
*  $ED Descrição da função
*     Se for possivel, obtem quem dobrou da ultima vez.
*
*
*  $EP Parâmetros
*	Ponteiro para ponteiro de uma struct de Dado pontos e ponteiro para um char.
*
*  $FV Valor retornado
*	PTS_CondRetOK 
*	PTs_CondRetErro
*
*  $AE Assertivas de entrada
*	O struct a ser utilizado tem que existir e nao ser vazio.
*	O ponteiro para char em que o ultimo jogador sera armazenado tem que existir.
*
*  $AS  Assertivas de saida
*     Se PTS_CondRetOK : Funcao ocorreu conforme esperado.O ultimo jogador que dobrou foi resgatado.
*	Se PTs_CondRetErro : Nao havia struct a ser utilizado
*
***********************************************************************/

PTS_tpCondRet PTS_QuemDobra( int * quemdobra );


void PTS_InsereValores(int cor, int valor);


#undef DADOPTS_EXT

/********** Fim do módulo de definição: PTS  Dado Pontos **********/

#else
#endif