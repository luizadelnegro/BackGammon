#if ! defined ( DADO_ )
#define DADO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo dado simples
*  Arquivo gerado:              DADO.H
*  Letras identificadoras:      DD
*
*  Nome da base de software:    jogo de gamao
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: ldn	- Luiza Del Negro
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		1.00   ldn	 23/04/2019 Inicio e fim do desenvolvimento do modulo dado.
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para simular 
*     a representacao de um dado simples de seis lados. 
*	  Ele gera um  numero aleatorio de um a seis quando lancado.
*	  Esse modulo se baseia nos modelos de lista e arvore fornecidos pelo arcabouco.
*
***************************************************************************/

#if defined( DADO_OWN )
#define DADO_EXT
#else
#define DADO_EXT extern
#endif



/***********************************************************************
*
*  $TC Tipo de dados: ARV Condicoes de retorno
*
*
***********************************************************************/


typedef enum {

	DD_CondRetOK,
    
   	DD_CondRetDadosIguais
	/* Concluiu corretamente */


} DD_tpCondRet;


/***********************************************************************
*
*  $FC Fun��o: DD  &Insere Dado Simples
*
*  $ED Descri��o da fun��o
*   Gerar dois numeros de um a seis
*
*  $EP Par�metros
*	Dois ponteiros para inteiro
*
*  $FV Valor retornado
*	DD_CondRetOK 
*
*  $AE Assertivas de entrada
*	 Os ponteiros para os valores dos dados devem existir 
*
*  $AS Assertivas de saida
*	Se DD_CondRetOK : Dados Foram criados, numeros aleatorios foram gerados. 
*	Ocorreu conforme o esperado 
*
***********************************************************************/


DD_tpCondRet DD_DadoSimples(int * a, int * b);



#undef DADO_EXT

/********** Fim do m�dulo de defini��o: DD  Dado simples **********/

#else
#endif