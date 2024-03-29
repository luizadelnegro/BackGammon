/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo teste dado pontos
*
*  Arquivo gerado:              TESTETABULEIRO.C
*  Letras identificadoras:      TTB
*
*  Nome da base de software:	Gamao
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores:
*			irf	- Iago Ribeiro Farroco
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		1.00   irf	 03/05/2019  Inicio do desenvolvimento do teste do m�dulo tabuleiro.
*
*  $ED Descri��o do m�dulo
*		Este modulo contem funcoes especificas para o teste do 
*		modulo tabuleiro. Ilustra como redigir um interpretador de comandos 
*		de teste especificos utilizando o arcabouco de testes pra C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo tabuleiro:
*		=criatabuleiro			-chama a funcao DDPTS_CriaDadoPontos()
*		=andapeca				-chama a funcao DDPTS_DobraDadoPontos(char quemdobra)
*		=destroitabuleiro		-chama a funcao DDPTS_DestroiDadoPontos()
***************************************************************************/


#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <malloc.h>

#include    "TST_ESPC.h"
#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "PECAS_FINALIZADAS.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */
#define CRIA_FINALIZADAS_CMD	  "=cria"
#define ADD_PECA_CMD		      "=add"
#define QUANTIDADE_PECA_CMD		  "=qtd"
#define DESTROI_FINALIZADAS_CMD	  "=destroi"


/***********************************************************************
*
*  $FC Fun��o: Testar tabuleiro
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char* ComandoTeste)
{	
		FIM_tpCondRet CondRetObtido   = FIM_CondRetOK ;
		FIM_tpCondRet CondRetEsperada = FIM_CondRetFaltouMemoria ;


		char ValorEsperado = '?'  ;
		char ValorObtido   = '!'  ;
		char ValorDado     = '\0' ;
		int	 casaInicial = -1 ;
		int  casaDestino = -1 ;

		int  corPeca = -1 ;
		int  qtdPreto = -1 ;
		int  qtdVermelho = -1 ;


		int  NumLidos = -1 ;

		TST_tpCondRet CondRet;


		 /* Testar TAB Monta Tabuleiro*/
		if ( strcmp( ComandoTeste , CRIA_FINALIZADAS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = criaFinalizadas( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar finalizadas." );

         } /* fim ativa: Testar TAB Monta Tabuleiro*/ 

		 /* Testar TAB Mover Peca */
		if ( strcmp( ComandoTeste , ADD_PECA_CMD ) == 0 )
         {
				
            NumLidos = LER_LerParametros( "ii" , &corPeca, 
								&CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  adicionaPecaFinalizadas( corPeca ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao adicionar pe�a." );

         } /* fim ativa: Testar TAB Mover Peca*/
		if ( strcmp( ComandoTeste , QUANTIDADE_PECA_CMD ) == 0 )
         {
				
            NumLidos = LER_LerParametros( "iii" , &qtdPreto, &qtdVermelho,
								&CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  qtdPecasFinalizadasJogador( &qtdPreto, &qtdVermelho ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao pegar quantidade de pe�as." );

         } /* fim ativa: Testar TAB Destroi Tabuleiro */
		if ( strcmp( ComandoTeste , DESTROI_FINALIZADAS_CMD ) == 0 )
         {
				
            NumLidos = LER_LerParametros( "i" , 
								&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  destroiFinalizadas( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao destruir finalizadas." );

         } /* fim ativa: Testar TAB Destroi Tabuleiro */

} /* Fim fun��o: Testar Tabuleiro*/



/********** Fim do m�dulo de implementa��o: TTB Teste TABULEIRO **********/
