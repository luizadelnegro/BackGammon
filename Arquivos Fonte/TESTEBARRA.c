/***************************************************************************
*  $MCI Módulo de implementação: Módulo teste dado pontos
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		1.00   irf	 03/05/2019  Inicio do desenvolvimento do teste do módulo tabuleiro.
*
*  $ED Descrição do módulo
*		Este modulo contem funcoes especificas para o teste do 
*		modulo tabuleiro. Ilustra como redigir um interpretador de comandos 
*		de teste especificos utilizando o arcabouco de testes pra C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo tabuleiro:
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

#include    "barra.h"

/* Tabela dos nomes dos comandos de teste específicos */
#define CRIA_BARRA_CMD		      "=cria"
#define TIRA_PECA_CMD			  "=tira"
#define ADD_PECA_CMD		      "=add"
#define QUANTIDADE_PECA_CMD		  "=qtd"
#define DESTROI_BARRA_CMD		  "=destroi"


/***********************************************************************
*
*  $FC Função: Testar tabuleiro
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char* ComandoTeste)
{	
		BAR_tpCondRet CondRetObtido   = BAR_CondRetOK ;
		BAR_tpCondRet CondRetEsperada = BAR_CondRetFaltouMemoria ;


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
		if ( strcmp( ComandoTeste , CRIA_BARRA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = criaBarra( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar barra." );

         } /* fim ativa: Testar TAB Monta Tabuleiro*/ 


		 /* Testar TAB Destroi Tabuleiro */
		if ( strcmp( ComandoTeste , TIRA_PECA_CMD ) == 0 )
         {
				
            NumLidos = LER_LerParametros( "ii" , &corPeca,
								&CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  tiraPeca( corPeca ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tirar peça." );

         } /* fim ativa: Testar TAB Destroi Tabuleiro */

		 /* Testar TAB Mover Peca */
		if ( strcmp( ComandoTeste , ADD_PECA_CMD ) == 0 )
         {
				
            NumLidos = LER_LerParametros( "ii" , &corPeca, 
								&CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  adicionaPecaBarra( corPeca ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao adicionar peça." );

         } /* fim ativa: Testar TAB Mover Peca*/
		if ( strcmp( ComandoTeste , QUANTIDADE_PECA_CMD ) == 0 )
         {
				
            NumLidos = LER_LerParametros( "iii" , &qtdPreto, &qtdVermelho,
								&CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  qtdCadaJogadorBarra( &qtdPreto, &qtdVermelho ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao pegar quantidade de peças." );

         } /* fim ativa: Testar TAB Destroi Tabuleiro */
		if ( strcmp( ComandoTeste , DESTROI_BARRA_CMD ) == 0 )
         {
				
            NumLidos = LER_LerParametros( "i" , 
								&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido =  destroiBarra( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao destruir barra." );

         } /* fim ativa: Testar TAB Destroi Tabuleiro */

} /* Fim função: Testar Tabuleiro*/



/********** Fim do módulo de implementação: TTB Teste TABULEIRO **********/
