#if ! defined ( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Tabuleiro
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		1.00   irf	 31/04/2019  Cria��o do m�dulo Tabuleiro e algumas fun��es.
*
*  $ED Descri��o do m�dulo
*	M�dulo que representa o tabuleiro e todos os seus componentes.
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
*  $TC Tipo de dados: TAB Condi��es de retorno
*
*
***********************************************************************/

   typedef enum {

        TAB_CondRetOK = 0,
               /* Concluiu corretamente */

        TAB_CondRetFaltouMemoria = 1,
			   /* Faltou Memoria */

		TAB_CondRetTrianguloBloqueado = 2,
			   /* Tri�ngulo j� possui pelo menos duas pe�as de outra cor nele */

		TAB_CondRetPecaNaoEncontrada = 3,
			   /* N�o existe pe�a da cor especificada no tri�ngulo */

		TAB_CondRetJogadorPretoVenceu = 4,
			   /* Jogador que manipula as pe�as pretas ganhou o jogo */

		TAB_CondRetJogadorVermelhoVenceu = 5,
			   /* Jogador que manipula as pe�as vermelhas ganhou o jogo */

		TAB_CondRetJogoNaoAcabou = 6,
			   /* Jogo ainda n�o acabou */

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
*  $FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Move a pe�a da casa inicial para a casa de destino.
*	
*  $EP Par�metros:
*     $P casaInicial - � o n�mero da casa que a pe�a se encontra no come�o do turno.
*     $P casaDestino - � o n�mero da casa que vai receber a pe�a movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam n�meros entre 1 e 24.
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
*  $FC Fun��o: TAB Monta Tabuleiro
*
*  $ED Descri��o da fun��o
*     Monta o tabuleiro com todas as casa, todos os tri�ngulos e todas as pe�as na posi��o inicial de jogo.
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
*  $FC Fun��o: TAB Destr�i Tabuleiro
*
*  $ED Descri��o da fun��o
*     Libera a mem�ria alocada para a estrutura tabuleiro.
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
*  $FC Fun��o: TAB Verifica Fim do Jogo
*
*  $ED Descri��o da fun��o
*     Verifica se o jogo j� acabou e denomina um vencedor.
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
*  $FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Move a pe�a da casa inicial para a casa de destino.
*	
*  $EP Par�metros:
*     $P casaInicial - � o n�mero da casa que a pe�a se encontra no come�o do turno.
*     $P casaDestino - � o n�mero da casa que vai receber a pe�a movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam n�meros entre 1 e 24.
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
*  $FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Move a pe�a da casa inicial para a casa de destino.
*	
*  $EP Par�metros:
*     $P casaInicial - � o n�mero da casa que a pe�a se encontra no come�o do turno.
*     $P casaDestino - � o n�mero da casa que vai receber a pe�a movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam n�meros entre 1 e 24.
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
*  $FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Move a pe�a da casa inicial para a casa de destino.
*	
*  $EP Par�metros:
*     $P casaInicial - � o n�mero da casa que a pe�a se encontra no come�o do turno.
*     $P casaDestino - � o n�mero da casa que vai receber a pe�a movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam n�meros entre 1 e 24.
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
*  $FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Move a pe�a da casa inicial para a casa de destino.
*	
*  $EP Par�metros:
*     $P casaInicial - � o n�mero da casa que a pe�a se encontra no come�o do turno.
*     $P casaDestino - � o n�mero da casa que vai receber a pe�a movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam n�meros entre 1 e 24.
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
*  $FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Move a pe�a da casa inicial para a casa de destino.
*	
*  $EP Par�metros:
*     $P casaInicial - � o n�mero da casa que a pe�a se encontra no come�o do turno.
*     $P casaDestino - � o n�mero da casa que vai receber a pe�a movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam n�meros entre 1 e 24.
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
*  $FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Move a pe�a da casa inicial para a casa de destino.
*	
*  $EP Par�metros:
*     $P casaInicial - � o n�mero da casa que a pe�a se encontra no come�o do turno.
*     $P casaDestino - � o n�mero da casa que vai receber a pe�a movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam n�meros entre 1 e 24.
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
*  $FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Move a pe�a da casa inicial para a casa de destino.
*	
*  $EP Par�metros:
*     $P casaInicial - � o n�mero da casa que a pe�a se encontra no come�o do turno.
*     $P casaDestino - � o n�mero da casa que vai receber a pe�a movida.
*
*  $EAE Assertivas de entradas esperadas
*     casaInicial e casaDestino sejam n�meros entre 1 e 24.
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


/********** Fim do m�dulo de defini��o: M�dulo Tabuleiro **********/


#else
#endif