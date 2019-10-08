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

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>

#define DADO_OWN
#include "DADO.H"
#undef DADO_OWN

static int primeira_vez = 1;


/*****************************************************************
*	Funcao: DD  Dado Simples
*		gera dois numero aleatorio de um a seis, os quais as pecas devem andar
*
/*****************************************************************/

DD_tpCondRet DD_DadoSimples(int * d1, int * d2) {

	if(primeira_vez)
	{
		srand( (unsigned)time(NULL) ) ;
		primeira_vez = 0;
	}
	*d1 = rand() % 6 + 1;
	*d2 = rand() % 6 + 1;
    if(*d1 == *d2){
        return DD_CondRetDadosIguais;
    }
    else{
        return DD_CondRetOK;
    }
}/* Fim fun��o: insere Dado Simples*/