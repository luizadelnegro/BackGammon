/***************************************************************************
*  $MCI Módulo de implementação: Módulo Tabuleiro
*
*  Arquivo gerado:              Tabuleiro.c
*  Letras identificadoras:      TAB
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
*		1.00   ldn	 31/04/2019  Criação do módulo Tabuleiro e algumas funções.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LISTA_OWN
#include "LISTA.H"
#undef LISTA_OWN

#include "PECA.H"


struct casa_triangulo
{
	casaTriangulo* anterior;
	PECA_tppPeca atual;
	casaTriangulo* proximo;
	
};


struct triangulo
{
	casaTriangulo* primeiraPeca;
	int qtdPreto;
	int qtdVermelho;

};

void criaTriangulo(Triangulo** Tri)
{
	*Tri = (Triangulo*) malloc(sizeof(Triangulo));
	if(*Tri == NULL)
	{
		return;
	}
	( *Tri )->primeiraPeca = NULL;
	( *Tri )->qtdPreto = 0;
	( *Tri )->qtdVermelho = 0;
	return;
}


void destroiTriangulo(Triangulo* Tri)
{
	casaTriangulo* corrente ;
	casaTriangulo* auxiliar ;
	corrente = Tri->primeiraPeca ;
	for( ;corrente!=NULL;corrente=auxiliar->proximo )
	{
		auxiliar = corrente ;
		destroiCasaTriangulo( corrente ) ;
	}
	Tri = NULL;
}


void criaCasaTriangulo(casaTriangulo** casaTri)
{
	*casaTri = (casaTriangulo*) malloc(sizeof(casaTriangulo));
	if(casaTri == NULL)
	{
		return;
	}
	( *casaTri )->anterior = NULL;
	( *casaTri )->atual = NULL;
	( *casaTri )->proximo = NULL;
	return;
}


void destroiCasaTriangulo(casaTriangulo* casaTri)
{
	casaTri = NULL;
}


void adicionaPeca(Triangulo* triangulo, int corPeca)
{
	PECA_tppPeca peca;
	casaTriangulo* pecaAtual;

	if(triangulo == NULL) return;

	corPeca == 0 ? PECA_CriarPeca(0, &peca) : PECA_CriarPeca(1, &peca);

	if(peca == NULL) return;
	
	pecaAtual = triangulo->primeiraPeca;

	if(pecaAtual == NULL) return;

	for(;pecaAtual->atual!=NULL;pecaAtual=pecaAtual->proximo)
	{
		if(pecaAtual->proximo == NULL)
		{
			return;
		}
	}

	pecaAtual->atual = peca;

	if(corPeca == 0)
	{
		triangulo->qtdPreto++;
	}
	else
	{
		triangulo->qtdVermelho++;
	}
	
	return;
}

void rmvPeca(Triangulo* triangulo, int corPeca)
{
	int cor;
	casaTriangulo* pecaAtual = triangulo->primeiraPeca;

	if(triangulo == NULL) return;

	if(pecaAtual == NULL) return;

	for(;pecaAtual!=NULL;pecaAtual=pecaAtual->proximo)
	{
		PECA_ObterCor(pecaAtual->atual, &cor);
	
		if(cor == corPeca)
		{
			pecaAtual->atual = NULL;

			if(cor == 0)
			{
				triangulo->qtdPreto--;
			}
			else
			{
				triangulo->qtdVermelho--;
			}

			return;
		}
	}

	return;
}

void povoaTriangulo(Triangulo* triangulo)
{
	casaTriangulo* casaTriAnterior;
	int i;

	for(i=0;i<17;i++)
	{
		casaTriangulo* casaTri;
		criaCasaTriangulo(&casaTri);
		
		if(i==0){
			triangulo->primeiraPeca = casaTri;
			casaTriAnterior = casaTri;
		}

		else
		{
		    casaTriAnterior->proximo = casaTri;
			casaTri->anterior = casaTriAnterior;
			casaTriAnterior = casaTri;
		}
	}
}

void qtdCadaCor(Triangulo* triangulo, int* qtdP, int* qtdV)
{
	*qtdP = triangulo->qtdPreto;
	*qtdV = triangulo->qtdVermelho;
	return;
}