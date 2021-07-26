#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=8,tab[n],i;
    lire(tab,n);
    for(int i=0;i<n;i++){
       printf(" ordre %d",n);
       tri(tab,n);
       printf(" ordre %d %d",tab[i],n);
       n--;

    }
    /*for(int k=0;k<n;k++){
      printf(" ligne %d ",tab[k]);

    }*/
    return 0;
}
void lire(int tab[],int taille){
  printf("Veuillez saisir les valeurs du tableau");
  for(int i=0;i<taille;i++){
      printf(" ligne %d ",i);
      scanf("%d",&tab[i]);

  }
}

void tri(int tab[],int taille){
  int newrang = rangmax(tab,taille);
  permute(tab,taille,newrang);

}

int rangmax(int tab[],int taille){
  int max=tab[taille-1],id;
  for(int i=0;i<taille;i++){
    if (max < tab[i]){
       max=tab[i];
    }else{
       max = max;
    }
  }
   for(int j=0;j<taille;j++){
    if (max == tab[j]){
       id = j;
    }
   }
  return id;
}
void permute(int tab[],int i,int j){
  int el_courant = tab[i-1];
  tab[i-1] = tab[j];
  tab[j] = el_courant;
}
