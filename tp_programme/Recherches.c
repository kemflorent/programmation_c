#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recherches.h"
#include "Objets.h"

/*Recherche */
int recherche(int indice, char *nomFichier){

       FILE *F;
       if(strcmp(nomFichier,"EC.txt") == 0){
          F = fopen("EC.txt","r");
          do{
               fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
               ,&EC.id,EC.codeEC,EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                fflush(stdin);
                if(EC.id == indice){
                   fclose(F);
                   return 1;
                }
          }while(!feof(F));
          fclose(F);
          return -1;
       }else if(strcmp(nomFichier,"UE.txt") == 0){
           F = fopen("UE.txt","r");
           do{
               fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f ;%s \n"
               ,&UE.id,UE.codeUE,UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE,UE.listeEC);
                fflush(stdin);
                if(UE.id == indice){
                   fclose(F);
                   return 1;
                }
           }while(!feof(F));
           fclose(F);
           return -1;
       }else  if(strcmp(nomFichier,"Classe.txt") == 0){
           F = fopen("Classe.txt","r");
           do{
               fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n"
               ,&Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,
               Classe.departement,Classe.parcours,&Classe.niveau);
                fflush(stdin);
                if(Classe.id == indice){
                   fclose(F);
                   return 1;
                }
           }while(!feof(F));
           fclose(F);
           return -1;
       }else  if(strcmp(nomFichier,"Programme.txt") == 0){
           F = fopen("Programme.txt","r");
           do{
               fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%s ;%s \n"
               ,&Programme.id,Programme.classe,Programme.intitule,&Programme.anneeAdoption,&Programme.nbreUESem1,
               &Programme.nbreUESem2,Programme.listeUESem1,Programme.listeUESem2);
                fflush(stdin);
                if(Programme.id == indice){
                   fclose(F);
                   return 1;
                }
           }while(!feof(F));
           fclose(F);
           return -1;//"UEChoix.txt"
       }else  if(strcmp(nomFichier,"UEChoix.txt") == 0){

           F = fopen("UEChoix.txt","r");
           int id;
           do{
               fscanf(F,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                                ,&id,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                                                 &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                fflush(stdin);
                if(id == indice){
                   fclose(F);
                   return 1;
                }
           }while(!feof(F));
           fclose(F);

           return -1;
       }else  if(strcmp(nomFichier,"UEChoix1.txt") == 0){

           F = fopen("UEChoix1.txt","r");
           int id;
           do{
               fscanf(F,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                      ,&id,&UE.id,&UE.codeUE,&UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                                       &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE);
                fflush(stdin);
                if(id == indice){
                   fclose(F);
                   return 1;
                }
           }while(!feof(F));
           fclose(F);

           return -1;
       }else  if(strcmp(nomFichier,"UEChoix2.txt") == 0){

           F = fopen("UEChoix2.txt","r");
           int id;
           do{
               fscanf(F,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                      ,&id,&UE.id,&UE.codeUE,&UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                                       &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE);
                fflush(stdin);
                if(id == indice){
                   fclose(F);
                   return 1;
                }
           }while(!feof(F));
           fclose(F);

           return -1;
       }else{
           printf("désolé le fichier n\'existe pas!");
       }

}
/*Fin recherche*/

/*Recherche et affiche*/

void Recherche(int indice, char *nomFichier){
}
/*Fin recherche et affiche*/
