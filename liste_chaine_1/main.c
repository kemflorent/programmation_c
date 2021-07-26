#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element{
    int nombre;
    struct Element *suivant;
};

int main()
{
int tab = {5,7,6,8,1,3};


ajouter_element(tab,6);




    return 0;
}

void ajouter_element(int tab[],int taille){
  Element *pt;

    for(int i=0;i < taille;i++){
       if(i == 0){
           pt->nombre = tab[i];
           pt->suivant = NULL;
       }else{
          Element *p;
          p->nombre = tab[i];
          p->suivant = NULL;
           p = (Element *) malloc(sizeof(Element));
          (pt+(i-1))->suivant = p;

       }
    }
    for(int i;i<taille;i++){
      //printf("number %d\n",*(p+i).nombre);
      printf("adresse %d\n",pt+i);
    }
}
int est_vide(Element *p){
 /*for(int i;i<){
      if(p == NULL){
        return true;
      }else{
        return false;
      }
  }*/
  return 0;
}

llist ajouterEnFin(llist liste, int valeur)

{

    /* On crée un nouvel élément */

    element* nouvelElement = malloc(sizeof(element));



    /* On assigne la valeur au nouvel élément */

    nouvelElement->val = valeur;



    /* On ajoute en fin, donc aucun élément ne va suivre */

    nouvelElement->nxt = NULL;



    if(liste == NULL)

    {

        /* Si la liste est videé il suffit de renvoyer l'élément créé */

        return nouvelElement;

    }

    else

    {

        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on

        indique que le dernier élément de la liste est relié au nouvel élément */

        element* temp=liste;

        while(temp->nxt != NULL)

        {

            temp = temp->nxt;

        }

        temp->nxt = nouvelElement;

        return liste;

    }

}



