#include <stdio.h>
#include <stdlib.h>

typedef struct Element T_Element;
struct Element {
   int nombre;
   struct Element *suivant;
};
typedef struct Liste T_Liste;
struct Liste{
  int premier;
  struct Element *newPremier;
};

T_Element *empiler(T_Element *element,int valeur){
//insertion en fin de liste
    T_Element *list = malloc(sizeof(*list));
    list->nombre = valeur;
    list->suivant = NULL;
    if(element == NULL){
       return list;
    }else{
      T_Element *tmp = element;
      while(tmp->suivant!=NULL){
        tmp = tmp->suivant;
      }
      tmp->suivant = list;

      return element;
    }

}
void afficher(T_Element *L)
{
	T_Element*courant=L;
	while(courant!=NULL)
	{
		printf("\t%d",courant->nombre);
		courant=courant->suivant;
	}
}
T_Liste *defiler(T_Element *element){
    T_Element *list = element;
    T_Liste *result = malloc(sizeof(*result));
    result->premier = element->nombre;
    result->newPremier = element->suivant;
    free(element);

  return result;
}
 int depiler(T_Element *element){

    T_Element *depile = element;

    int dernier = NULL;

    while(depile->suivant!=NULL){
       depile = depile->suivant;
    }
    dernier = depile->nombre;
    while(element->suivant!=NULL){
         if(element->suivant == depile){

             element->suivant = NULL;
             free(depile);
             break;
         }
         element = element->suivant;
    }
    return dernier;
 }
 T_Element *initialise(){
    int tab[] = {2,3,5,7,8,9};
    T_Element *elem = NULL;
    for(int i=0;i<6;i++){
        elem = empiler(elem,tab[i]);
    }
    afficher(elem);
    return elem;
 }

int main()
{
    printf("\n Gestion des Piles\n");
    /*Gestion des Piles*/
    T_Element *elem = initialise();
    printf("\nje depile %d\n",depiler(elem));
    printf("\nje depile %d\n",depiler(elem));
    afficher(elem);
    /*Fin gestion des Piles*/
    printf("\n Gestion des Files\n");
    /*Gestion des Files*/
    T_Element *element = initialise();
    T_Liste *firstOut = NULL;
    firstOut = defiler(element);
    printf("\nje defile %d\n",firstOut->premier);
    //afficher(firstOut->newPremier);
    firstOut = defiler(firstOut->newPremier);
    printf("\nje defile %d\n",firstOut->premier);
    afficher(firstOut->newPremier);
    /*Fin gestion de Piles*/

    return 0;
}


