/***************************************************************************
*  $MCI Módulo de implementação: Módulo Barra
*
*  Arquivo gerado:              Barra.c
*  Letras identificadoras:      BAR
*
*  Nome da base de software:	Jogo de Gamao
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores:
*			irf	- Iago Ribeiro Farroco
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*		1.00   irf	 30/05/2019  Criação do módulo Barra e algumas funções.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define BARRA_OWN
#include "BARRA.H"
#undef BARRA_OWN
#include "PECA.H"
#include "LISTA.H"

struct no_barra
{
	noBarra* anterior;
	PECA_tppPeca atual;
	noBarra* proximo;
	
};


struct cabeca_barra
{
	noBarra* primeiraPeca;
	int qtdPreto;
	int qtdVermelho;

};


static cabecaBarra* Barra = NULL;
/* Ponteiro para a Barra */

void criaNoBarra(noBarra** No);


void criaNoBarra(noBarra** No)
{
	*No = (noBarra*) malloc(sizeof(noBarra));
	if(*No == NULL)
	{
		return;
	}
	(*No)->anterior = NULL;
	(*No)->atual = NULL;
	(*No)->proximo = NULL;
	return;
}/* Fim da função BAR Criar No da Barra */



BAR_tpCondRet criaBarra()
{
	noBarra* No;
	Barra = (cabecaBarra*) malloc(sizeof(cabecaBarra));
	if(Barra == NULL)
	{
		return BAR_CondRetFaltouMemoria;
	}
	criaNoBarra(&No);
	Barra->primeiraPeca = No;
	Barra->qtdPreto = 0;
	Barra->qtdVermelho = 0;
	return BAR_CondRetOK;
}/* Fim da função BAR Cria Barra */


BAR_tpCondRet adicionaPecaBarra(int corPeca)
{
	PECA_tppPeca peca;
	noBarra* pecaAtual;
    noBarra* auxiliar;
	noBarra* No;

	criaNoBarra(&No);

	if(Barra == NULL) return BAR_CondRetBarraNaoExiste;

	corPeca == 0 ? PECA_CriarPeca(0, &peca) : PECA_CriarPeca(1, &peca);

	if(peca == NULL) return BAR_CondRetFaltouMemoria;
	
	pecaAtual = Barra->primeiraPeca;

	if(pecaAtual->atual == NULL)
	{
        pecaAtual->atual = peca;
	}
    for(;pecaAtual!=NULL; auxiliar = pecaAtual, pecaAtual=pecaAtual->proximo);
    
    pecaAtual = No;
    auxiliar->proximo = pecaAtual;
    pecaAtual->anterior = auxiliar;
    pecaAtual->atual = peca;
    pecaAtual->proximo = NULL;
    
    No->anterior = pecaAtual;
	No->atual = peca;
	
    if(corPeca == 0)
	{
		Barra->qtdPreto++;
	}
	else
	{
		Barra->qtdVermelho++;
	}
	
	return BAR_CondRetOK;
}/* Fim da função BAR Adiciona Peca na Barra */


BAR_tpCondRet tiraPeca(int corPeca)
{
	int cor;
	noBarra* pecaAtual = Barra->primeiraPeca;

	if(Barra == NULL) return BAR_CondRetBarraNaoExiste;

	for(;pecaAtual!=NULL;pecaAtual=pecaAtual->proximo)
	{
		PECA_ObterCor(pecaAtual->atual, &cor);
	
		if(cor == corPeca)
		{
			pecaAtual->atual = NULL;
            pecaAtual->proximo = NULL;
            pecaAtual->anterior = NULL;
            
			if(cor == 0)
			{
				Barra->qtdPreto--;
			}
			else
			{
				Barra->qtdVermelho--;
			}

			return BAR_CondRetOK;
		}
	}

	return BAR_CondRetOK;
}/* Fim da função BAR Tira Peça da Barra */


BAR_tpCondRet qtdCadaJogadorBarra(int* qtdP, int* qtdV)
{
	*qtdP = Barra->qtdPreto;
	*qtdV = Barra->qtdVermelho;
	return BAR_CondRetOK;
}/* Fim da função BAR Quantidade de Peca de Cada Jogador na Barra */

BAR_tpCondRet destroiBarra()
{
	free(Barra);
	Barra = NULL;
	return BAR_CondRetOK;
}/* Fim da função BAR Destroi Barra */