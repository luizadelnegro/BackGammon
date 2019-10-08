#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*                                                                          *
*  $MCD Módulo de definição: Módulo Peça                                   *
*  Arquivo: Peca.h                                                         *
*  Identificador: PECA                                                     *
*                                                                          *
*  Autores: dw - Daniel Weil                                               *
*           ldn - Luiza Del Negro                                          *
*           irf - Iago Ribeiro Farroco                                     *
*                                                                          *
*  $HA Histórico de evolução:                                              *
*     Versão     Autor     Data          Observações                       *
*       0.1       dw       28/04         Criação do arquivo Peca.h         *
*       0.11	   irf	   03/05         Correção de um elemento da struct *                                                                 *
*       0.2       dw       11/05         Criacao das assertivas de entrada *
*       0.2       dw       11/05         Criacao das assertivas de saida   *                                         
*                                                                          *
*  $ED Descrição do módulo                                                 *
*	  Define o modulo Peca para ser usada no jogo de Gamao.                 *
*                                                                          *
***************************************************************************/

#if defined( PECA_OWN )
  #define PECA_EXT
#else
  #define PECA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma peça */

typedef struct tgPeca PECA_tpPeca;

typedef PECA_tpPeca * PECA_tppPeca;

/***********************************************************************
*
*  $TC Tipo de dados: PECA Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno referentes às funções de peca
*
***********************************************************************/

   typedef enum {

      PECA_CondRetOK = 0,
         /* Concluiu corretamente */

		PECA_CondRetPecaNaoExiste = 1,
		   /* A peca não foi criada*/

      PECA_CondRetFaltouMemoria = 2,
		   /* Faltou Memoria*/
      PECA_CondRetCorInvalida = 3
         /* Cor data é invalida */

   } PECA_tpCondRet;

/***********************************************************************
*
*  $FC Função: PECA  &Criar Peca
*
*  $ED Descrição da função
*    Cria uma nova peca vazia
*
*	$EP Parâmetros
*    cor - Elemento do Enum COR (preto = 0, vermelho = 1)
*    pPeca = Ponteiro para PECA_tppPeca, aonde será guardada a peça criada.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a peça.
*     Este ponteiro será utilizado pelas funções que manipulem esta peça.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
*  $AE Assertivas de entrada
*		Tem que haver espaco na memoria
*     Recebeu um elemento do enum COR em seus parametros de entrada, com valor válido
*     Recebeu um ponteiro para a PECA_tppPeca em seus parametros de entrada 
*
*	$AS Assertivas de saida
*		Funcao ocorreu conforme esperado, não resultando em erros
*     Funcao criou a peca e guardou ela na variavel pPeca
*		A Função retornou PECA_tpCondRet
*
***********************************************************************/

    PECA_tpCondRet PECA_CriarPeca (int cor, PECA_tppPeca* pPeca);


 /***********************************************************************
*
*  $FC Função: PECA Destruir Peça
*
*  $ED Descrição da função
*     Destroi uma peça passada como parametro.
*
*  $EP Parâmetros
*    pPeca - ponteiro para a peça que será destruída
*
*  $FV Valor retornado
*     PEC_CondRetOK - Peça foi destruída corretamente
*     PEC_CondRetPecaNaoExiste - Peça não existe
*
*  $AE Assertivas de entrada
*     Recebeu um ponteiro para a PECA_tppPeca em seus parametros de entrada 
*     e PECA_tpp contém uma peca valida 
*
*	$AS Assertivas de saida
*		Funcao ocorreu conforme esperado, não resultando em erros
*     Funcao liberou o espaço de memoria alocado para a peca
*
***********************************************************************/

   void PECA_DestruirPeca(PECA_tppPeca *pPeca);

/***********************************************************************
*
*  $FC Função: PECA Obter cor
*
*  $ED Descrição da função
*     Obtém a cor e recebe como parametros a peca para descobrir a cor e um vetor cor onde sera preenchida a cor.
*
*  $EP Parâmetros
*     pPeca - ponteiro para a peça que obteremos informações
*     pCor  - ponteiro que retorna a cor da peça
*
*  $FV Valor retornado
*     PEC_CondRetOk - Cor foi obtida corretamente
*     PEC_CondRetPecaNaoExiste - Peça não existe
*
*  $AE Assertivas de entrada
*     Recebeu um ponteiro para a PECA_tppPeca em seus parametros de entrada e
*     PECA_tpp contém uma peca valida 
*     Recebeu um ponteiro para o inteiro pCor, aonde guardará a cor da peca
*
*	$AS Assertivas de saida
*		Funcao ocorreu conforme esperado, não resultando em erros
*		Funcao guardou a cor da peca na variavel pCor
*     A Função retornou PECA_tpCondRet
*
***********************************************************************/
   PECA_tpCondRet PECA_ObterCor(PECA_tppPeca pPeca, int *pCor);

#undef PECA_EXT


/********** Fim do módulo de definição: Módulo Peça **********/


#else
#endif