#include <stdio.h>
#include <stdlib.h>

struct Element{
  int nombre;
  struct Element * suivant;
};
typedef struct Element T_Element;
struct Position{
  int maPosition;
  struct Element * premier;
  struct Element * suivant;
};
typedef struct Position T_Position;

T_Element* supprimerElementEnTete(T_Element *liste){


    if(liste != NULL){

      T_Element* aRenvoyer = liste->suivant;

         free(liste);

      return aRenvoyer;

    }

    else{ return NULL;}

}

T_Position *rechercherElement(T_Element *list, int valeur){

  T_Element *tmp=list;
  T_Position *pos = malloc(sizeof(*pos));
  int i = 1;
   while(tmp != NULL){

        if(tmp->nombre == valeur){
          break;
        }

        tmp = tmp->suivant;
       i++;
   }
   pos->maPosition = i;
   pos->suivant = tmp->suivant;
   if(i == 1){
      printf("ma position %d",i);
      list = supprimerElementEnTete(tmp);
   }else{

       free(tmp);
   }
   pos->premier = list;

   return pos;

}
void supprimer_nombre_N(T_Element *list, int valeur){
  T_Position * pos_suiv = rechercherElement(list,valeur);
  T_Element *tmp = pos_suiv->premier;
   if(pos_suiv->premier == list){
       int i = 1;
       while(tmp != NULL){

            if(i == ((pos_suiv->maPosition)-1)){
              break;
            }

            tmp = tmp->suivant;
           i++;
       }
       tmp->suivant = pos_suiv->suivant;
   }
  afficher(pos_suiv->premier);
}


T_Element *supprimerElementEnFin(T_Element *liste){


    if(liste != NULL){

      T_Element *elemen = liste;
      T_Element *avantDernier = NULL;

      while(elemen->suivant!=NULL){

         elemen = elemen->suivant;
      }
      avantDernier = elemen;
      free(elemen);
      while(liste->suivant!=NULL){
          if(liste->suivant == avantDernier){
             liste->suivant = NULL;
             break;
          }
         liste = liste->suivant;
      }

      return liste;

    }

}

T_Element * insertion_debut(T_Element * precedent,int valeur){

     T_Element * elem = malloc(sizeof(* elem));
     elem->nombre = valeur;

     if(precedent == NULL){
        elem->suivant = NULL;
     }else{
        elem->suivant = precedent;
     }
   return elem;
}

void afficher(T_Element * L)
{
	struct Element * courant=L;
	printf("\t\tLISTES SIMPLEMENT CHAINÉE\n\n");
	while(courant!=NULL)
	{
		printf("\t%d",courant->nombre);
		courant=courant->suivant;
	}
}
T_Element* insertion_fin(T_Element *premier,int valeur){


	T_Element *nouvel_element;
	nouvel_element = malloc (sizeof(*nouvel_element));
	nouvel_element->nombre = valeur;
	nouvel_element->suivant = NULL;
	if(premier==NULL){
	  return nouvel_element;
	}else {
		 T_Element* courant = premier;
		while (courant->suivant!=NULL)
		{
			courant = courant->suivant;
		}
		courant->suivant = nouvel_element;
		return premier;
	}

}
/* insertion à la position demandée */
void insertion_position_N(T_Element *element,int position,int valeur){

    T_Element *elem = malloc(sizeof(*elem));
    elem->nombre = valeur;
    if(position == 1){
       element = insertion_debut(element,valeur);
    }else{
       int i = 1;
       T_Element *tmp = element;
       while(tmp!= NULL){
         if(i == position){
            break;
         }
         tmp = tmp->suivant;
         i++;
       }
       elem->suivant = tmp;
       int j=1;
       T_Element *tmp1 = element;
        while(tmp1!= NULL){
         if(j == (position-1)){
            break;
         }
         tmp1 = tmp1->suivant;
         j++;
       }
       tmp1->suivant = elem;
    }
   afficher(element);
}
T_Element * initialise(){
int tab[] = {2,3,6,7,8,9};
     T_Element * element = NULL;
     for(int i=0;i <6;i++){
         element = insertion_fin(element,tab[i]);
     }
     return element;
}
int main()
{
 int tab[] = {2,3,6,7,8,9},drapeau=1,choix;

 do{
    printf("\t1-Insertion en debut de liste\n");
    printf("\t2-Insertion en fin de liste\n");
    printf("\t3-Insertion à une position donné de la liste\n");
    printf("\t4-Suppression d'un élément en debut de liste\n");
    printf("\t5-Suppression d'un élément en fin de liste\n");
    printf("\t6-Suppression d'un élément de la liste\n");
    scanf("%d",&choix);
    T_Element * element = NULL;
    switch(choix){
        case 1:{
             for(int i=0;i <6;i++){
                element = insertion_debut(element,tab[i]);
             }
             afficher(element);
             break;
        }
        case 2:{
             for(int i=0;i <6;i++){
                element = insertion_fin(element,tab[i]);
             }
             afficher(element);
             break;
        }
        case 3:{
             element = initialise();
             afficher(element);
             int nombre,position;
             printf("\nEntrez le nombre\n");
             scanf("%d",&nombre);
             printf("\nEntrez la position à laquelle vous voulez inserer le nombre\n");
             scanf("%d",&position);
             insertion_position_N(element,position,nombre);
             break;
        }
        case 4:{
            element = initialise();
            afficher(element);
            element = supprimerElementEnTete(element);
            afficher(element);

             break;
        }
        case 5:{
             element = initialise();
             afficher(element);
             supprimerElementEnFin(element);
             afficher(element);
             break;
        }
        default:{
             element = initialise();
             afficher(element);
             int nombre;
             printf("\nEntrez le nombre\n");
             scanf("%d",&nombre);
             supprimer_nombre_N(element,nombre);
             break;
        }
    }
    printf("\nVoulez-vous continuer? 1:oui, 0:non ");
    scanf("%d",&drapeau);


 }while(drapeau==1);

    return 0;
}


