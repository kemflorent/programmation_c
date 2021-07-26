#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tab[5] = {5, 3, 4, 1, 2};

    int i;


    quickSort(tab, 0, 4);



    for(i = 0; i < 5; i++)

    {

    printf("%d ", tab[i]);

    }

    putchar('\n');

    return 0;
}
void quickSort(int tableau[], int debut, int fin)

{

    int gauche = debut-1;

    int droite = fin+1;

    const int pivot = tableau[debut];


    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */

    if(debut >= fin)

        return;


    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une

       autre de gauche à droite, à la recherche d'éléments mal placés,

       que l'on permute. Si les deux parcours se croisent, on arrête. */

    while(1)

    {

        do droite--; while(tableau[droite] > pivot);

        do gauche++; while(tableau[gauche] < pivot);


        if(gauche < droite)

            echanger(tableau, gauche, droite);

        else break;

    }


    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux

       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise

       pour cela... la méthode quickSort elle-même ! */

    quickSort(tableau, debut, droite);

    quickSort(tableau, droite+1, fin);

}

void echanger(int tableau[], int a, int b)

{

    int temp = tableau[a];

    tableau[a] = tableau[b];

    tableau[b] = temp;

}
