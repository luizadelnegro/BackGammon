#if ! defined ( LISTA_ )
#define LISTA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Tabuleiro
*  Arquivo gerado:              TABULEIRO.H
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: irf	- Iago Ribeiro Farroco
*			ldn - Luiza Del Negro
*			dwl - Daniel Weil Lins
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		1.00   irf	 31/04/2019  Cria��o do m�dulo Tabuleiro e algumas fun��es.
*
*  $ED Descri��o do m�dulo
*	M�dulo que representa o tabuleiro e todos os seus componentes.
*	
*
*
*
*
***************************************************************************/

#if defined( LISTA_OWN )
#define LISTA_EXT
#else
#define LISTA_EXT extern
#endif

   typedef struct casa_triangulo casaTriangulo;

   typedef struct triangulo Triangulo;

   void adicionaPeca(Triangulo* triangulo, int corPeca);

   void rmvPeca(Triangulo* triangulo, int corPeca);

   void criaCasaTriangulo(casaTriangulo** casaTri);

   void criaTriangulo(Triangulo** Tri);

   void povoaTriangulo(Triangulo* triangulo);
   
   void qtdCadaCor(Triangulo* triangulo, int* qtdPreto, int* qtdVermelho);

   void destroiTriangulo(Triangulo* Tri);

   void destroiCasaTriangulo(casaTriangulo* casaTri);

   void criaTriangulo(Triangulo** Tri);

   void destroiTriangulo(Triangulo* Tri);

   void criaCasaTriangulo(casaTriangulo** casaTri);

   void destroiCasaTriangulo(casaTriangulo* casaTri);





#undef LISTA_EXT


/********** Fim do m�dulo de defini��o: M�dulo Tabuleiro **********/


#else
#endif