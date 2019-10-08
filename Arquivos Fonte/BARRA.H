#if ! defined ( BARRA_ )
#define BARRA_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Barra
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		1.00   irf	 30/05/2019  Criação do módulo Barra e algumas funções.
*
*  $ED Descrição do módulo
*	Módulo que representa a barra e todos os seus componentes.
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


/********** Fim do módulo de definição: Módulo Tabuleiro **********/


#else
#endif