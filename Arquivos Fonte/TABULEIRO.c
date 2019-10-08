/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Tabuleiro
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data      Observa��es
*		1.00   ldn	 31/04/2019  Cria��o do m�dulo Tabuleiro e algumas fun��es.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TABULEIRO_OWN
#include "TABULEIRO.H"
#undef TABULEIRO_OWN
#include "PECA.H"
#include "LISTA.H"
#include "BARRA.H"
#include "PECAS_FINALIZADAS.H"

/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor do struct Tabuleiro
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do tabuleiro.
*
***********************************************************************/

struct tabuleiro
{
	Casa* primeiraCasa;
	int qtdPreto;
	int qtdVermelho;
};

/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor do struct Casa
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o das casas que comp�em o tabuleiro.
*
***********************************************************************/

struct casa
{
	Casa*	   casaAnterior;
	Triangulo* ponteiroTriangulo;
	Casa*	   proximaCasa;
	int numeroCasa;

};

/*****  Dados encapsulados no m�dulo  *****/

Tabuleiro* Tab = NULL;
/* Ponteiro para o Tabuleiro */

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

static void destroiCasa( Casa* casa ) ;

static TAB_tpCondRet removePeca( int numeroCasa, int corPeca ) ;

static TAB_tpCondRet confereIdaFinalizadas(int corDaPeca) ;

static TAB_tpCondRet criaCasa(Casa** casa, int numero) ;

/*****  C�digo das fun��es encapsuladas pelo m�dulo  *****/

/***************************************************************************
*
*  $FC Fun��o: TAB Criar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Aloca mem�ria e cria uma estrutura tabuleiro com seus elementos vazios.
*
*  $FV Valor retornado:
*	  Caso n�o seja poss�vel criar o tabuleiro por falta de mem�ria = 1;
*	  Caso tenha criado propriamente = 0;
*
****************************************************************************/

TAB_tpCondRet criaTabuleiro( )
{
	Tab = ( Tabuleiro* ) malloc( sizeof ( Tabuleiro ) ) ;
	if( Tab == NULL )
	{
		return TAB_CondRetFaltouMemoria ;
	}/* if */
	
	Tab->qtdPreto = 0 ;
	Tab->qtdVermelho = 0 ;
	Tab->primeiraCasa = NULL ;
	
	return TAB_CondRetOK;
}/* Fim da fun��o TAB Criar Tabuleiro */

/***************************************************************************
*
*  $FC Fun��o: TAB Criar Casa
*
*  $ED Descri��o da fun��o
*     Aloca mem�ria e cria uma estrutura casa com seus elementos vazios.
*	
*  $EP Par�metros:
*     $P numero - � o n�mero da casa a ser criada.
*
*  $FV Valores de retorno:
*	  Caso n�o seja poss�vel criar a casa por falta de mem�ria = NULL;
*     Caso tenha criado propriamente = Ponteiro para a estrutura criada;
*
****************************************************************************/

TAB_tpCondRet criaCasa(Casa** casa, int numero)
{
	*casa = ( Casa* ) malloc( sizeof ( Casa ) ) ;
	
	if( *casa == NULL )
	{
		return TAB_CondRetFaltouMemoria;
	}/* if */
	
	(*casa)->numeroCasa = numero+1 ;
	(*casa)->ponteiroTriangulo = NULL ;
	(*casa)->proximaCasa = NULL ;
	(*casa)->casaAnterior = NULL ;
	
	return TAB_CondRetOK;
}/* Fim da fun��o TAB Criar Casa */

/***************************************************************************
*
*  $FC Fun��o: TAB Destr�i Casa
*
*  $ED Descri��o da fun��o
*     Libera a mem�ria na qual o tabuleiro est� alocado.
*
****************************************************************************/

void destroiCasa( Casa* casa )
{
	casa = NULL ;
}/* Fim da fun��o TAB Destr�i Casa */

/***************************************************************************
*
*  $FC Fun��o: TAB Adiciona Pe�a
*
*  $ED Descri��o da fun��o
*     Adiciona uma pe�a da cor desejada na casa de n�mero informado.
*	
*  $EP Par�metros:
*     $P numeroCasa - � o n�mero da casa a ter a pe�a inserida.
*     $P cor - � a cor da pe�a que ser� inserida.
*
*  $FV Valores de retorno:
*	  Caso o tri�ngulo j� possua 5 pe�as = 2;
*     Caso o tri�ngulo possua 2 ou mais pe�as de outra cor = 3;
*     Caso a inser��o da pe�a tenha sido bem sucedida = 0;
*
****************************************************************************/

TAB_tpCondRet addPeca( int numeroCasa, int cor )
{
	int i, qtdPreto, qtdVermelho ;
	Casa* casaAtual = Tab->primeiraCasa ;
	
	for( ;casaAtual->numeroCasa!=numeroCasa;casaAtual=casaAtual->proximaCasa ) ;

	adicionaPeca( casaAtual->ponteiroTriangulo, cor ) ;

	return TAB_CondRetOK ;
}/* Fim da fun��o TAB Adiciona Pe�a */

/***************************************************************************
*
*  $FC Fun��o: TAB Remove Pe�a
*
*  $ED Descri��o da fun��o
*     Remove uma pe�a da cor desejada na casa de n�mero informado.
*	
*  $EP Par�metros:
*     $P numeroCasa - � o n�mero da casa a ter a pe�a removida.
*     $P cor - � a cor da pe�a que ser� removida.
*
*  $FV Valores de retorno:
*	  Caso o tri�ngulo n�o possua nenhuma pe�a da cor informada = 4;
*     Caso a remo��o da pe�a tenha sido bem sucedida = 0;
*
****************************************************************************/

TAB_tpCondRet removePeca( int numeroCasa, int corPeca )
{
	Casa* casaAtual = Tab->primeiraCasa ;
	casaTriangulo* pecaAtual ;
	int qtdPreto, qtdVermelho ;
	
	for( ;casaAtual->numeroCasa!=numeroCasa;casaAtual=casaAtual->proximaCasa ) ;

	qtdCadaCor( casaAtual->ponteiroTriangulo, &qtdPreto, &qtdVermelho ) ;
	
	if( corPeca == 0 && qtdPreto == 0 )
	{
		return TAB_CondRetPecaNaoEncontrada ;
	}/* if */
	else if( corPeca == 1 && qtdVermelho == 0 )
	{
		return TAB_CondRetPecaNaoEncontrada ;
	}/* else if */

	rmvPeca( casaAtual->ponteiroTriangulo, corPeca ) ;
	
	if( corPeca == 0 )
	{
		Tab->qtdPreto-- ;
	}/* if */
	else
	{
		Tab->qtdVermelho-- ;
	}/* else */
	
	return TAB_CondRetOK ;
}/* Fim da fun��o TAB Remove Pe�a */

/***************************************************************************
*
*  $FC Fun��o: TAB Adiciona Casa com Triangulos e Casas do Triangulo
*
*  $ED Descri��o da fun��o
*     Cria todas as casas do tabuleiro j� com seus respectivos tri�ngulos.
*	  Todos os tri�ngulos j� t�m 5 espa�os vazios para futuras inser��es de pe�a.
*
****************************************************************************/

void addCasaComTriangulo ( )
{
	int qtd, i ;
	Triangulo* Tri ;
	Casa* casa ;
	Casa* casaAtual ;
	
	if( Tab->primeiraCasa == NULL )
	{
		criaCasa( &casa, 0 ) ;
		Tab->primeiraCasa = casa ;
		criaTriangulo( &Tri ) ;
		Tab->primeiraCasa->ponteiroTriangulo = Tri ;
	}/* if */
	else
	{
	    casaAtual = Tab->primeiraCasa ;
	    
	    for( ;casaAtual->proximaCasa!=NULL;casaAtual=casaAtual->proximaCasa ) ;
		
		qtd = casaAtual->numeroCasa ;
		criaCasa( &casa, qtd ) ;
		casaAtual->proximaCasa = casa ;
		casa->casaAnterior = casaAtual ;
		criaTriangulo( &Tri ) ;
		casa->ponteiroTriangulo = Tri ;
	}/* else */

	povoaTriangulo( casa->ponteiroTriangulo ) ;

}/* Fim da fun��o TAB Adiciona Casa com Triangulos e Casas do Triangulo */

/***************************************************************************
*
*  $FC Fun��o: TAB Destruir Ponteiro Tabuleiro
*
*  $ED Descri��o da fun��o
*	   Destroi um ponteiro para estrutura tabuleiro;
*
****************************************************************************/

void destuirPonteiroTabuleiro(Tabuleiro* Tab)
{
	Tab = NULL ;
}/* Fim da fun��o TAB Adiciona Casa com Triangulos e Casas do Triangulo */

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: TAB Monta Tabuleiro
*
****************************************************************************/

TAB_tpCondRet montaTabuleiro( )
{
	int i, cor, condRet ;
	Casa* auxiliar ;
	PECA_tppPeca pecaTeste ;

	condRet = criaTabuleiro( ) ;
	criaBarra();
	criaFinalizadas();

	if( condRet == 1 )
	{
		return TAB_CondRetFaltouMemoria ;
	}/* if */
			
	for( i=0;i<24;i++ )
	{
	    addCasaComTriangulo( ) ;
	}
	
	for( i=0;i<5;i++ )
	{	    
	    addPeca( 6, 0 ) ;
	    addPeca( 19, 1 ) ;
	    addPeca( 13, 0 ) ;
	    addPeca( 12, 1 ) ;
	    
	    if( i>1 )
	    {
	        addPeca( 8, 0 ) ;
	        addPeca( 17, 1 ) ;
	    }/* if */
	    
	    if( i>2 )
	    {
	        addPeca( 24, 0 ) ;
	        addPeca( 1, 1 ) ;
	    }/* if */
	}

	Tab->qtdPreto = 15 ;
	Tab->qtdVermelho = 15 ;
	
	return TAB_CondRetOK ;
}/* Fim da fun��o TAB Monta Tabuleiro */

/***************************************************************************
*
*  Fun��o: TAB Move Pe�a
*
****************************************************************************/

TAB_tpCondRet movePeca( int casaInicial, int casaDestino )
{
	int cor, condRet = 0, qtdP, qtdV ;

	if(casaInicial == 26 || casaInicial == 27)
	{
		if(casaInicial == 26)
		{
			cor = 0;
		}
		else
		{
			cor = 1;
		}
	
	}
	else{
		if( ( casaDestino - casaInicial ) > 0 )
		{
			cor = 1;
		}
		else
		{
			cor = 0;
		}
	}

	qtdCadaJogadorBarra(&qtdP, &qtdV);

	if((qtdP >= 1 && casaInicial != 25 && cor == 0) || (qtdV >= 1 && casaInicial != 0 && cor == 1))
	{
		return TAB_CondRetAindaExistePecaNaBarra;
	}

	if(casaInicial == 0)
	{
		if(qtdV == 0) return TAB_CondRetNaoJogadorNaoPossuiPecaNaBarra;

		qtdPecaTabuleiro(casaDestino, &qtdP, &qtdV);

		if( qtdP == 0 )
		{
			tiraPeca(1);
			addPeca(casaDestino, 1);
			return TAB_CondRetOK;
		}
		else if(qtdP == 1)
		{
			tiraPeca(1);
			addPeca(casaDestino, 1);
			removePeca( casaDestino, 0 );
			adicionaPecaBarra(0);
			return TAB_CondRetOK;
		}
		else
		{
			return TAB_CondRetTrianguloBloqueado;
		}
	}
	else if(casaInicial == 25)
	{
		if(qtdP == 0) return TAB_CondRetNaoJogadorNaoPossuiPecaNaBarra;

		qtdPecaTabuleiro(casaDestino, &qtdP, &qtdV);

		if( qtdV == 0 )
		{
			tiraPeca(0);
			addPeca(casaDestino, 0);
			return TAB_CondRetOK;
		}
		else if(qtdV == 1)
		{
			tiraPeca(0);
			addPeca(casaDestino, 0);
			removePeca( casaDestino, 1 );
			adicionaPecaBarra(1);
			return TAB_CondRetOK;
		}
		else
		{
			return TAB_CondRetTrianguloBloqueado;
		}
	}

	if(casaDestino == 26 || casaDestino == 27)
	{
		condRet = confereIdaFinalizadas(cor);
		
		if(condRet == 10)
		{
			return TAB_CondRetNemTodasAsPecasEstaoNoQuadranteFinal;
		}
		else
		{
			condRet = removePeca( casaInicial, cor ) ;
			if( condRet == 3 )
			{
				return TAB_CondRetPecaNaoEncontrada ;
			}/* if */
			adicionaPecaFinalizadas(cor);
			return TAB_CondRetOK;
		}
	
	}
	
	else
	{
		qtdPecaTabuleiro(casaDestino, &qtdP, &qtdV);
		
		if(cor == 1)
		{
			if( qtdP == 0)
			{
				condRet = removePeca( casaInicial, cor ) ;
				if( condRet == 3 )
				{
					return TAB_CondRetPecaNaoEncontrada ;
				}/* if */
				addPeca( casaDestino, cor );
				return TAB_CondRetOK;
			}
			else if( qtdP == 1)
			{
				condRet = removePeca( casaInicial, cor ) ;
				if( condRet == 3 )
				{
					return TAB_CondRetPecaNaoEncontrada ;
				}/* if */
				addPeca( casaDestino, cor );
				condRet = removePeca( casaDestino, 0 ) ;
				if( condRet == 3 )
				{
					return TAB_CondRetPecaNaoEncontrada ;
				}/* if */
				adicionaPecaBarra( 0 );
				return TAB_CondRetOK;
			}
			else
			{
				return TAB_CondRetTrianguloBloqueado;
			}
		}
		else
		{
			if( qtdV == 0)
			{
				condRet = removePeca( casaInicial, cor ) ;
				if( condRet == 3 )
				{
					return TAB_CondRetPecaNaoEncontrada ;
				}/* if */
				addPeca( casaDestino, cor );
				return TAB_CondRetOK;
			}
			else if( qtdV == 1)
			{
				condRet = removePeca( casaInicial, cor ) ;
				if( condRet == 3 )
				{
					return TAB_CondRetPecaNaoEncontrada ;
				}/* if */
				addPeca( casaDestino, cor );
				condRet = removePeca( casaDestino, 1 ) ;
				if( condRet == 3 )
				{
					return TAB_CondRetPecaNaoEncontrada ;
				}/* if */
				adicionaPecaBarra( 1 );
				return TAB_CondRetOK;
			}
			else
			{
				return TAB_CondRetTrianguloBloqueado;
			}
		}/* else */
	}

}/* Fim da fun��o TAB Move Pe�a */

/***************************************************************************
*
*  Fun��o: TAB Verifica Fim do Jogo
*
****************************************************************************/

TAB_tpCondRet fimDoJogo( )
{
	int corP;
	int corV;

	qtdPecasFinalizadasJogador(&corP, &corV);

	if( corP == 15 )
	{
		return TAB_CondRetJogadorPretoVenceu ;
	}/* if */
	else if( corV == 15 )
	{
		return TAB_CondRetJogadorVermelhoVenceu ;
	}/* else if */
	else
	{
		return TAB_CondRetJogoNaoAcabou ;
	}/* else */
}/* Fim da fun��o TAB Verifica Fim do Jogo */

/***************************************************************************
*
*  Fun��o: TAB Destr�i Tabuleiro
*
****************************************************************************/

TAB_tpCondRet destroiTabuleiro( )
{
	destroiTriangulo(Tab->primeiraCasa->ponteiroTriangulo) ;
	destroiCasa(Tab->primeiraCasa) ;
	destuirPonteiroTabuleiro(Tab);
    
	return TAB_CondRetOK ;
}/* Fim da fun��o TAB Destr�i Tabuleiro */

TAB_tpCondRet qtdPecaTabuleiro( int nCasa, int* qtdPreto, int* qtdVermelho )
{
	Casa* casaAtual ;
	
	casaAtual = Tab->primeiraCasa ;

	while( casaAtual->numeroCasa != nCasa )
	{
		if( casaAtual == NULL )
		{
			return TAB_CondRetNumeroDaCasaInvalido ;
		}
		casaAtual = casaAtual->proximaCasa ;
	}
	
	qtdCadaCor( casaAtual->ponteiroTriangulo, qtdPreto, qtdVermelho ) ;

	return TAB_CondRetOK ;

}

TAB_tpCondRet confereIdaFinalizadas(int corDaPeca)
{
	Casa* iteradorCasas;
	int qtdP, qtdV;

	iteradorCasas = Tab->primeiraCasa;

	for(;iteradorCasas != NULL;iteradorCasas=iteradorCasas->proximaCasa)
	{
		qtdCadaCor(iteradorCasas->ponteiroTriangulo, &qtdP, &qtdV);
		if(iteradorCasas->numeroCasa > 6)
		{
			if( qtdP >= 1 && corDaPeca == 0)
			{
				return TAB_CondRetNemTodasAsPecasEstaoNoQuadranteFinal;
			}
		}
		if(iteradorCasas->numeroCasa < 19)
		{
			if( qtdV >= 1 && corDaPeca == 1)
			{
				return TAB_CondRetNemTodasAsPecasEstaoNoQuadranteFinal;
			}	
		}
	}
	return TAB_CondRetOK;

}

TAB_tpCondRet qtdPecaBarra( int* qtdPreto, int* qtdVermelho )
{
	qtdCadaJogadorBarra( qtdPreto, qtdVermelho );
	return TAB_CondRetOK;
}

TAB_tpCondRet qtdPecaFinalizadas( int* qtdPreto, int* qtdVermelho )
{
	qtdPecasFinalizadasJogador( qtdPreto, qtdVermelho );
	return TAB_CondRetOK;
}

void qtdPecaCasa(int nCasa, int*qtd, int* color)
{
	Casa* casaAtual;
	int  qtdPreto = 0;
	int  qtdVermelho = 0;
	casaAtual = Tab->primeiraCasa;

	while (casaAtual->numeroCasa != nCasa) {
		if (casaAtual == NULL) {
			*color = 2;
			*qtd = 0;
			return;
		}
		casaAtual = casaAtual->proximaCasa;
	}
	qtdCadaCor(casaAtual->ponteiroTriangulo, &qtdPreto, &qtdVermelho);
	if (qtdPreto != 0) {
		*color = 0;
		*qtd = qtdPreto;
	}
	if (qtdVermelho != 0) {
		*color = 1;
		*qtd = qtdVermelho;
	}


	return;

}