#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i,j,n,MatriceAdjacente[n][n],p,path[p][n],distance[p],v,row,column,distanceMin;

    printf("Entrez le nombre de sommet ");
    scanf("%d",&n);
    printf("\nEntrez les distances entre sommets ");
    for(int i=1;i<=n-1;i++){
       for(int j=1;j<=n;j++){
           printf("\nDe %d-->%d distance = ",i,j);
           scanf("%d",&MatriceAdjacente[i][j]);
       }
    }
    //Parcour du graphe en partant du premier sommet vers le dernier
    /*selection du sommet à atteindre*/
      printf("\nEntrez le sommet à atteindre ");
      scanf("%d",&v);

    /* Determination du nombre de chemin possible*/
    p=0;
    for(i=1;i<=v;i++){
       if(MatriceAdjacente[1][i]!= 0){
          p++;
       }
    }
    /* Table des chemins possibles*/
   printf("\nListe des chemins possibles");
   for(i=1;i<=p;i++){
       for(j=1;j<=n;j++){
          if(j!=1){
            printf("--->");
          }else{
            printf("\nchemin %d --->",i);
          }

          scanf("%d",&path[i][j]);

       }
    }
  for(i=1;i<=p;i++){

       distance[i] = 0;
       row = 1;

       for(j=1;j<=n;j++){
          column = path[i][j+1];
          distance[i] = distance[i] + MatriceAdjacente[row][column];
          row = column;
       }
    }
    distanceMin = distance[1];
    for(i=1;i<=p;i++){
      if(distance[i]<= distanceMin){
         distanceMin = distance[i];
         row=i;
      }
    }
    printf("Distance Min %d",distanceMin);
    for(i=1;i<=n;i++){
      if(path[row][i]!= 0){
        printf("\t-->%d",path[row][i]);
      }
    }
    return 0;
}
