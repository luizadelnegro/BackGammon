#if ! defined ( PECAS_FINALIZADAS_ )
#define PECAS_FINALIZADAS_

/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Pecas Finalizadas
*  Arquivo gerado:              PECAS_FINALIZADAS.H
*  Letras identificadoras:      FIM
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
*		1.00   irf	 30/05/2019  Cria��o do m�dulo Pecas Finalizadas e algumas fun��es.
*
*  $ED Descri��o do m�dulo
*	M�dulo que representa as pecas finalizadas e todos os seus componentes.
*	
*
*
*
*
***************************************************************************/

#if defined( PECAS_FINALIZADAS_OWN )
#define PECAS_FINALIZADAS_EXT
#else
#define PECAS_FINALIZADAS_EXT extern
#endif

   typedef enum {

        FIM_CondRetOK = 0,
               /* Concluiu corretamente */

        FIM_CondRetFaltouMemoria = 1,
			   /* Faltou Memoria */

		FIM_CondRetPecasFinalizadasNaoExiste = 2,

   } FIM_tpCondRet ;

   typedef struct cabeca_finalizadas cabecaFinalizadas;

   typedef struct no_finalizadas noFinalizadas;

   FIM_tpCondRet criaFinalizadas();

   FIM_tpCondRet adicionaPecaFinalizadas(int corPeca);

   FIM_tpCondRet qtdPecasFinalizadasJogador(int* qtdPreto, int* qtdVermelho);

   FIM_tpCondRet destroiFinalizadas();

#undef PECAS_FINALIZADAS_EXT


/********** Fim do m�dulo de defini��o: M�dulo Tabuleiro **********/


#else
#endif