/***************************************************************************
*  $MCI Módulo de implementação: Módulo Dado Pontos
*
*  Arquivo gerado:              DADOPONTOS.C
*  Letras identificadoras:      PTS
*
*  Nome da base de software:	gamao
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores:
*			ldn	- Luiza Del Negro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		1.00   ldn	 26/04/2019  Inicio do desenvolvimento do modulo dado.
***************************************************************************/

#include   <stdlib.h>
#include   <stdio.h>
#include	<time.h>
#include   <malloc.h>

#define DADOPTS_OWN
#include "DADOPONTOS.H"
#undef DADOPTS_OWN


/***********************************************************************
*
*  $TC Tipo de dados: PTS Descritor do struct Dado Pontos
*
*
*  $ED Descrição do tipo
*     Descreve a organização do dado de pontos
*
***********************************************************************/


typedef struct tgDadoPontos{

	int  ultimadobra;// jogador v=1 p=0 z=2
	/* Ultimo jogador que dobrou*/
	int  ptvalor;
	/* Valor da partida*/
} tpDadoPontos;

/*****  Dados encapsulados no módulo  *****/

static tpDadoPontos * pDadoPontos = NULL ;
/* Ponteiro para a dado  */

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/


/***************************************************************************
*
*  Função: PTS Criar struct dado pontos
*  ****/


PTS_tpCondRet PTS_CriaDadoPontos( ){
	
      if ( pDadoPontos != NULL )
      {
         PTS_DestroiDadoPontos();
      } /* if */

    pDadoPontos = ( tpDadoPontos * ) malloc( sizeof( tpDadoPontos )) ;
      if ( pDadoPontos == NULL )
      {
         return PTS_CondRetFaltouMemoria ;
      } /* if */

	pDadoPontos->ultimadobra = 2;// jogador v e jogador p
	/* indica quem foi o ultimo jogador que dobrou*/
	pDadoPontos->ptvalor=1;
	/* pontuacao jogo*/

      return PTS_CondRetOK ;
} /* Fim função: PTS Criar dado */


/***************************************************************************
*
*  Função: PTS Destruir Dado
*  ****/


void PTS_DestroiDadoPontos( ){

      if ( pDadoPontos != NULL )
      {
         free( pDadoPontos ) ;
         pDadoPontos = NULL ;
      } 

   } /* Fim função: PTS Destruir dado */



/***************************************************************************
*
*  Função: PTS Dobra dado pontos
*  ****/


PTS_tpCondRet PTS_DobraDadoPontos( int quemdobrou){
		if(pDadoPontos ==NULL) return PTS_CondRetErro;

		else{
			if (pDadoPontos->ultimadobra==quemdobrou){
				printf("nao pode repetir \n "); 
				return  PTS_CondRetRepetiu ;
			}
			if (pDadoPontos->ptvalor==64){
				printf("nao pode mais dobrar \n "); 
				return  PTS_CondRetDobraMaxima ;
			}

			if (pDadoPontos->ptvalor==0){ //primeira dobra
				pDadoPontos->ultimadobra=quemdobrou;
				pDadoPontos->ptvalor=2;
				return  PTS_CondRetOK ;
			}

			else{
				if (quemdobrou==1) {
				
					pDadoPontos->ultimadobra=1;
					pDadoPontos->ptvalor= pDadoPontos->ptvalor*2;
					return PTS_CondRetOK ;
				}

				if (quemdobrou==0) {
					pDadoPontos->ultimadobra=0;
					pDadoPontos->ptvalor= pDadoPontos->ptvalor*2;
					return PTS_CondRetOK ;
				}
				else{ // se o valor recebido for diferente 
				printf(" jogador invalido \n");
				return PTS_CondRetErro;
				}
			}
		}
}/* Fim função: PTS Dobra pontos */

/***************************************************************************
*
*  Função: PTS Obtem valor da partida
*  ****/


PTS_tpCondRet PTS_ObtemPontos(int * Pontuacao ){

	   if (pDadoPontos == NULL)
		   return PTS_CondRetErro;

	   *Pontuacao = pDadoPontos->ptvalor;

	   return PTS_CondRetOK;

   }/* Fim função: PTS Obtem valor da partida */

/***************************************************************************
*
*  Função: PTS Quem dobra
*  ****/


PTS_tpCondRet PTS_QuemDobra( int * quemdobra ){

	   if (pDadoPontos == NULL)
		   return PTS_CondRetErro;

	   *quemdobra = pDadoPontos->ultimadobra;

	   return PTS_CondRetOK;

   } /* Fim função: PTS Ultimo jogador a dobrar */



void PTS_InsereValores(int cor, int valor ) {

	pDadoPontos->ultimadobra = cor;// jogador v=1 e jogador p=0
	/* indica quem foi o ultimo jogador que dobrou*/
	pDadoPontos->ptvalor = valor;
	/* pontuacao jogo*/

	return ;
} /* Fim função: PTS */