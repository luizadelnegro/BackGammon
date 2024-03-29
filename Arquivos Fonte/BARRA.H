#if ! defined ( BARRA_ )
#define BARRA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Barra
*  Arquivo gerado:              BARRA.H
*  Letras identificadoras:      BAR
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
*		1.00   irf	 30/05/2019  Cria��o do m�dulo Barra e algumas fun��es.
*
*  $ED Descri��o do m�dulo
*	M�dulo que representa a barra e todos os seus componentes.
*	
*
*
*
*
***************************************************************************/

#if defined( BARRA_OWN )
#define BARRA_EXT
#else
#define BARRA_EXT extern
#endif


   typedef enum {

        BAR_CondRetOK = 0,
               /* Concluiu corretamente */

        BAR_CondRetFaltouMemoria = 1,
			   /* Faltou Memoria */

		BAR_CondRetBarraNaoExiste = 2,

   } BAR_tpCondRet ;


   typedef struct cabeca_barra cabecaBarra;


   typedef struct no_barra noBarra;


   BAR_tpCondRet criaBarra();

   BAR_tpCondRet tiraPeca(int corPeca);

   BAR_tpCondRet adicionaPecaBarra(int corPeca);

   BAR_tpCondRet qtdCadaJogadorBarra(int* qtdPreto, int* qtdVermelho);

   BAR_tpCondRet destroiBarra();


#undef BARRA_EXT


/********** Fim do m�dulo de defini��o: M�dulo Tabuleiro **********/


#else
#endif