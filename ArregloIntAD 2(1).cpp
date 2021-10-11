/**********************  PROGRAMA CONJUNTO.CPP ************************/

/*  Definici¢n de la Clase CONJUNTO y de sus funciones propias y prueba
    de la misma
*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

#define  CARDMAX 16

enum  BOOLEAN {FALSO, CIERTO};
enum  CODERROR{NOERR, SOBREFLUJO};

class CONJUNTO{
	   int ELEMS[CARDMAX];          // elementos del conjunto
	   int CARD;			        // cardinalidad
  public:
	   void     VACIARCONJUNTO()	{CARD = 0;}
	   BOOLEAN  MIEMBRO  (int);
	   CODERROR AGREGAEL (int);
	   void     ELIMINAREL(int);
	   void     COPIACONJ(CONJUNTO *);
	   BOOLEAN  CONJIGUAL(CONJUNTO *);
	   void     IMPRIMIR();
	   void     INTERSECCION(CONJUNTO *,CONJUNTO *);
	   CODERROR UNION(CONJUNTO *,CONJUNTO *);
	   BOOLEAN  SUBCONJUNTO(CONJUNTO *);
	   BOOLEAN  SUBCONJREAL(CONJUNTO *);
};

/********************* FUNCION CONJUNTO::MIEMBRO ***************************/
//          Verifica si ELEMENTO es MIEMBRO del CONJUNTO

BOOLEAN  CONJUNTO::MIEMBRO(int ELEMENTO)

   {
    for (int C1=0; C1 < CARD; C1++)
     if (ELEMS[C1] == ELEMENTO) return CIERTO;
    return FALSO;
   }


/********************* FUNCION CONJUNTO::AGREGAEL***************************/
//                   Agrega un ELEMENTO al CONJUNTO

CODERROR CONJUNTO::AGREGAEL (int ELEMENTO)
   {
    for (int C1=0; C1 < CARD; C1++)
     if (ELEMS[C1] == ELEMENTO)
	return NOERR;		                  // Si ya esta , no lo agrega
    if (CARD < CARDMAX) {
       ELEMS[CARD++] = ELEMENTO;          // Si no esta , lo agrega
       return NOERR;}
    else return SOBREFLUJO;               // Si ya sobrepas¢ los elementos
					                      // que puede tener el conjunto
   }


/********************* FUNCION CONJUNTO::ELIMINAREL **************************/
//                  Elimina un ELEMENTO del CONJUNTO

void  CONJUNTO::ELIMINAREL(int ELEMENTO)
   {
    for (int C1=0; C1 < CARD; C1++)
     if (ELEMS[C1] == ELEMENTO){
      for (;C1 < CARD-1; C1++)            // Desplaza los elementos hacia la
       ELEMS[C1] = ELEMS[C1+1];           // izquierda
      --CARD;}
   }


/********************* FUNCION CONJUNTO::COPIACONJ *************************/
//   Copia la cardinalidad y elementos del conjunto original al conjunto
//   indicado como parametro

void CONJUNTO::COPIACONJ(CONJUNTO *CONJCOPIA)
   {
    for (int C1=0; C1 < CARD; C1++)       // Copia elementos
     CONJCOPIA->ELEMS[C1] = ELEMS[C1];
     CONJCOPIA->CARD = CARD;              // Copia cardinalidad
   }


/********************* FUNCION CONJUNTO::CONJIGUAL *************************/
//  Compara el conjunto original, con otro conjunto indicado como parametro
//  Retorna el valor booleano CIERTO si los conjuntos son iguales y FALSO
//  en el caso contrario

BOOLEAN CONJUNTO::CONJIGUAL(CONJUNTO *CONJACOMP)
   {
    if (CONJACOMP->CARD != CARD) return FALSO; // Cardinalidad diferente
    for (int C1=0; C1 < CARD; C1++)
     if (!(CONJACOMP->MIEMBRO(ELEMS[C1])))
      return FALSO;                            // Elemento diferente
    return CIERTO;                             // Conjuntos iguales
   }


/********************* FUNCION CONJUNTO::IMPRIMIR **************************/
//  Imprime el contenido de un conjunto en notaci¢n de teor¡a de conjuntos

void CONJUNTO::IMPRIMIR()
   {
    cout << "{";
    for (int C1=0; C1 < CARD-1; C1++)
     cout << ELEMS[C1] << ",";
    if (CARD > 0) cout << ELEMS[CARD-1];
    cout << "}\n";
   }


/********************* FUNCION CONJUNTO::INTERSECCION **********************/
// Deja en el conjunto de salida CONJS el conjunto intersecci¢n del conjunto
// base y elconjunto indicado en su primer argumento, como CONJB

void CONJUNTO::INTERSECCION(CONJUNTO *CONJA, CONJUNTO *CONJB)
   {
     VACIARCONJUNTO();          // Vac¡a el conjunto de salida
      for (int C1=0; C1 < CONJA->CARD; C1++)
      if (CONJB->MIEMBRO(CONJA->ELEMS[C1]))
	  AGREGAEL(CONJA->ELEMS[C1]);      // Mete en el conjunto de salida los
				                // elementos que estan en el conjunto
			                    // base y en el conjunto CONJB
   }


/********************* FUNCION CONJUNTO::UNION  ****************************/
// Pone en elconjunto de salida se¤alado por CONJS todos los elementos que
// est n en el conjunto base o en el conjunto se¤alado por el argumento
// CONJB

CODERROR CONJUNTO::UNION(CONJUNTO *CONJA,CONJUNTO *CONJB)
   {
     VACIARCONJUNTO();                // Vac¡a el conjunto de salida
     COPIACONJ(CONJA);                // Copia conjunto base al de salida
     for (int C1=0; C1 < CONJB->CARD; C1++)
      if (!(CONJA->MIEMBRO(CONJB->ELEMS[C1])))
       if (AGREGAEL(CONJB->ELEMS[C1])== SOBREFLUJO) return SOBREFLUJO;
		   // Mete en el conjunto de salida los elementos
		   // que no estan en el conjunto base y estan en
		   // el conjunto CONJB, mientras no haya sobreflujo
     return NOERR; // Cuando no hubo sobreflujo
   }

/****************** FUNCION CONJUNTO::SUBCONJUNTO  ************************/
// Retorna el valor CIERTO si todos los ELEMENTOS del CONJUNTO base son
// miembros del conjunto referido en el argumento de SUBCONJUNTO

BOOLEAN  CONJUNTO::SUBCONJUNTO(CONJUNTO *CONJB)
  {
   for (int C1=0; C1 < CARD; C1++)
    if (!(CONJB->MIEMBRO(ELEMS[C1])))
     return FALSO;                // Al encontrar un elemento que no sea
				                  // miembro del conjunto (CONJB) se retorna
			                      // con el valor FALSO
   return CIERTO;		          // Todos los elementos son tambien
				                  // miembros de (CONJB)
  }

BOOLEAN  CONJUNTO::SUBCONJREAL(CONJUNTO *CONJB)
  {
   if (CONJIGUAL(CONJB)) return FALSO;
   for (int C1=0; C1 < CARD; C1++)
    if (!(CONJB->MIEMBRO(ELEMS[C1])))
     return FALSO;                // Al encontrar un elemento que no sea
				                  // miembro del conjunto (CONJB) se retorna
				                  // con el valor FALSO
   return CIERTO;		          // Todos los elementos son tambien
				                  // miembros de (CONJB)
  }



main()
// Prueba sencilla de la clase CONJUNTO
{
 system("cls");
 CONJUNTO CJ1, CJ2, CJ3;
 CJ1.VACIARCONJUNTO(); CJ2.VACIARCONJUNTO(); CJ3.VACIARCONJUNTO();
 CJ1.AGREGAEL(11); CJ1.AGREGAEL(12);CJ1.AGREGAEL(13);CJ1.AGREGAEL(14);
 CJ2.AGREGAEL(13); CJ2.AGREGAEL(12);CJ2.AGREGAEL(11);CJ2.AGREGAEL(14);
 cout << "CJ1 = "; CJ1.IMPRIMIR();
 cout << "CJ2 = "; CJ2.IMPRIMIR();
 if (CJ1.MIEMBRO(12)) cout << "12 esta en CJ1 \n";
 if ((CJ1.CONJIGUAL(&CJ2))) cout << "CJ1 == CJ2 \n";
 CJ3.INTERSECCION(&CJ1,&CJ2);cout << "CJ3 = CJ1 INTERSC CJ2 = "; CJ3.IMPRIMIR();
 if ((CJ3.SUBCONJUNTO(&CJ2))) cout << "CJ3 es subconjunto de CJ2 \n";
 if ((CJ3.SUBCONJREAL(&CJ2))) cout << "CJ3 es subconjunto real de CJ2 \n";
 else cout << "CJ3 no es subconjunto real de CJ2 \n";
 CJ3.UNION(&CJ1, &CJ2); cout << "CJ3 = CJ1 UNION CJ2 = "; CJ3.IMPRIMIR();
 CJ2.ELIMINAREL(11); cout << "CJ2 sin el elemento 11 = "; CJ2.IMPRIMIR();
  CJ2.AGREGAEL(15); cout << "CJ2 = "; CJ2.IMPRIMIR();
 CJ3.UNION(&CJ1, &CJ2); cout << "CJ3 = CJ1 UNION CJ2 = "; CJ3.IMPRIMIR();
 if ((CJ1.CONJIGUAL(&CJ2))) cout << "CJ1 == CJ2 \n";
 CJ2.AGREGAEL(1000);  cout << "CJ2 = "; CJ2.IMPRIMIR();
 getchar();
}


