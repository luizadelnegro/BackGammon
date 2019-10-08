#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define PECAS_FINALIZADAS_OWN
#include "PECAS_FINALIZADAS.H"
#undef PECAS_FINALIZADAS_OWN
#include "PECA.H"
#include "LISTA.H"

static cabecaFinalizadas* Finalizadas = NULL;

void criaNoFinalizadas(noFinalizadas** No);

struct no_finalizadas
{
	noFinalizadas* anterior;
	PECA_tppPeca atual;
	noFinalizadas* proximo;
	
};

struct cabeca_finalizadas
{
	noFinalizadas* primeiraPeca;
	int qtdPreto;
	int qtdVermelho;

};


FIM_tpCondRet criaFinalizadas()
{
	noFinalizadas* No;
	Finalizadas = (cabecaFinalizadas*) malloc(sizeof(cabecaFinalizadas));
	if(Finalizadas == NULL)
	{
		return  FIM_CondRetFaltouMemoria;
	}
	criaNoFinalizadas(&No);
	Finalizadas->primeiraPeca = No;
	Finalizadas->qtdPreto = 0;
	Finalizadas->qtdVermelho = 0;
	return FIM_CondRetOK;
}

void criaNoFinalizadas(noFinalizadas** No)
{
	*No = (noFinalizadas*) malloc(sizeof(noFinalizadas));
	if(*No == NULL)
	{
		return;
	}
	(*No)->anterior = NULL;
	(*No)->atual = NULL;
	(*No)->proximo = NULL;
	return;
}

FIM_tpCondRet adicionaPecaFinalizadas(int corPeca)
{
	PECA_tppPeca peca;
	noFinalizadas* pecaAtual;
	noFinalizadas* auxiliar;
	noFinalizadas* No;

	criaNoFinalizadas(&No);

	if(Finalizadas == NULL) return FIM_CondRetPecasFinalizadasNaoExiste;

	corPeca == 0 ? PECA_CriarPeca(0, &peca) : PECA_CriarPeca(1, &peca);

	if(peca == NULL) return FIM_CondRetFaltouMemoria;
	
	pecaAtual = Finalizadas->primeiraPeca;

	if(pecaAtual == NULL)
	{
		pecaAtual = No;
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
		Finalizadas->qtdPreto++;
	}
	else
	{
		Finalizadas->qtdVermelho++;
	}
	
	return FIM_CondRetOK;
}

FIM_tpCondRet qtdPecasFinalizadasJogador(int* qtdP, int* qtdV)
{
	*qtdP = Finalizadas->qtdPreto;
	*qtdV = Finalizadas->qtdVermelho;
	return FIM_CondRetOK;
}

FIM_tpCondRet destroiFinalizadas()
{
	free(Finalizadas);
	Finalizadas = NULL;
	return FIM_CondRetOK;
}
