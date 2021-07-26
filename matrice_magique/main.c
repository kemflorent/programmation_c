#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    double matrice[N][N];
    printf("MATRICE MAGIQUE\n\n\n");


    printf("Entrez la taille de votre matrice");
    scanf("%d",&N);

    printf("Veuillez saisir les coefficients de la matrice");

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
          scanf("%f",i,j,&matrice[i][j]);
        }
    }
    double diagonale1 = somme_diagonale_haut_bas(matrice,N);
    double diagonale2 = somme_diagonale_bas_haut(matrice,N);
    double ligne = somme_ligne(matrice,N);
    double colonne = somme_colonne(matrice,N);
    if(diagonale1 == diagonale2 && diagonale1 ==ligne && diagonale1 ==colonne && diagonale2 == ligne && diagonale2==colonne && ligne==colonne){
       printf("Note matrice est magique");
    }else{
       printf("Notre matrice n'est pas magique");
    }
    return 0;
}
double somme_diagonale_haut_bas(double mat[][],int taille){
    double somme = 0;
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
             if(i==j){
               somme = somme + mat[i][j];
               break;
             }
        }
    }
    return somme;
}
double somme_diagonale_bas_haut(double mat[][],int taille){
    double somme = 0;
    for(int i=taille-1;i>=0;i++){
        for(int j=0;j<taille;j++){
             if(taille-1==i+j){
               somme = somme + mat[i][j];
               break;
             }
        }
    }
    return somme;
}
double somme_ligne(double mat[][],int taille){
    double somme = 0;
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
           somme = somme + mat[i][j];
        }
    }
    return somme;
}
double somme_colonne(double mat[][],int taille){
    double somme = 0;
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
               somme = somme + mat[j][i];
        }
    }
    return somme;
}
double somme_deux_diagonale(double somme1,double somme2){
  return somme1 + somme2;
}
