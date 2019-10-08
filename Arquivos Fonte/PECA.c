/***************************************************************************
*                                                                          *
*  $MCD Módulo de definição: Módulo Peça                                   *
*  Arquivo: Peca.c                                                         *
*  Identificador: PECA                                                     *
*  Autores: dw - Daniel Weil                                               *
*           ldn	- Luiza Del Negro                                          *
*           irf - Iago Ribeiro Farroco                                     * 
*                                                                          *
*  $HA Histórico de evolução:                                              *
*     Versão     Autor     Data          Observações                       *
*		0.1       dw       27/04         Criação do arquivo Peca.c         *
*       0.11	  irf	   03/05         Correção de um elemento da struct *        
*       0.2       dw       11/05         Correção nas funcoes              *
*                                                                          *
***************************************************************************/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define PECA_OWN
#include "PECA.H"
#undef PECA_OWN

/***********************************************************************
*                                                                      *
*  $TC Tipo de dados: PEÇA Descritor de uma peça                       *
*                                                                      *
*  $ED Descrição do tipo:                                              *
*     Estrutura que guarda a cor referente à peça                      *
*                                                                      *
***********************************************************************/

struct tgPeca{

    int cor;

};


/***********************************************************************
*  Função: PECA Criar Peça                                             *
***********************************************************************/

PECA_tpCondRet PECA_CriarPeca (int cor, PECA_tppPeca* pPeca)
{
    
	*pPeca = ( PECA_tppPeca ) malloc( sizeof( PECA_tpPeca ));
    if (pPeca == NULL) return PECA_CondRetFaltouMemoria;        /* if */

    if(cor != 0 && cor != 1){
        return PECA_CondRetCorInvalida;
    }

	(*pPeca)->cor = cor;

    return PECA_CondRetOK;
}   /* Fim função: PECA Criar Peca */

/***********************************************************************
 *  Função: PECA Destruir Peca
 ***********************************************************************/

void PECA_DestruirPeca (PECA_tppPeca *pPeca)
{

    free(*pPeca);
    pPeca = NULL;

}   /* Fim função: PECA Destruir Peca */

/***********************************************************************
 *  Função: PECA Obter Cor
 ***********************************************************************/

PECA_tpCondRet PECA_ObterCor (PECA_tppPeca pPeca, int *pCor)
{

    if (pPeca == NULL)
    {
        *pCor = -1;
        return PECA_CondRetPecaNaoExiste;
    } /* if */

    *pCor = pPeca->cor;

    return PECA_CondRetOK;
}   /* Fim função: Peca Obter Cor */

