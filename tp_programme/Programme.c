#include <stdio.h>
#include <stdlib.h>
#include "Objets.h"
#include "Programme.h"
#include "Recherches.h"
#include "MenuPrincipal.h"


char *fichierProgramme = "Programme.txt";

char *fichierUE1 = "UE.txt";

char *fichierUEChoix1 = "UEChoix1.txt";

char *fichierUEChoix2 = "UEChoix2.txt";

void menuprogramme(){

     int b;
     do
        {
             printf("\n\n************************************************\n");
             printf("                  MENU PROGRAMMES                    \n");
             printf("************************************************");
             printf("\n");
             printf("\n 1. Ajouter un programme");
             printf("\n 2. Lister les programmes");
             printf("\n 3. Modifier des programmes");
             printf("\n 4. Supprimer une programme");
             printf("\n 5. Rechercher une programme");
             printf("\n 6. Sortir");
             printf("\n***********************************************");
             printf("\n Quel operation voulez-vous effectuer : ");

             scanf("%d",&b);
             switch (b)
                { 		case 1: AjouterProgramme();break;
                        case 2: ListeProgramme();break;
                        case 3: ModifierProgramme();break;
                        case 4: SupprimerProgramme();break;
                        case 5: RechercheProgramme();break;
                }
        }while (b>0 && b<6);
         menuPrincipal();
}


void listeUE(int id,char *fichierUEChoix){

     FILE *F;

     F = fopen(fichierUEChoix,"r");
     int j=0;
     do{
               fscanf(F,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                      ,&Programme.id,&UE.id,&UE.codeUE,&UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                                       &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE);
              fflush(stdin);
              if(Programme.id == id){
                              if(j==0){
                                        printf("\n\n\t\t--------------- LISTE DES UEs DU PROGRAMME %d---------------\n",Programme.id);
                                        printf("\t\t---------------------------------------------------------\n");
                                        printf("| ID\t| Code EC\t| Libelle EC\t|");
                              }
                               printf("\n| %d\t| %s\t| %s\t|",UE.id,UE.codeUE,UE.libelleUE);
                             /*  printf("\nCode UE:\t%s",UE.codeUE);
                               printf("\nLibelle UE:\t%s",UE.libelleUE);
                           printf("\n\nVolume Horaire TD:\t%d",UE.valTD);
                           printf("\n\nVolume Horaire TP:\t%d",UE.valTP);
                           printf("\n\nVolume Horaire CM:\t%d",UE.valCM);
                           printf("\n\nCredits:\t%d",UE.credits);
                           printf("\n\nNombre d\'EC:\t%d",UE.nbreEC);
                           printf("\n\nCoefficient CC:\t%f",UE.coefCC);
                           printf("\n\nCoefficient Examen:\t%f",UE.coefEX);
                           printf("\n\nCoefficient TP:\t%f",UE.coefTP);
                           printf("\n\nCoefficient TPE:\t%f",UE.coefTPE);*/
                          j = j+1;
               }
     }while(!feof(F));
      fclose(F);
      printf("\n\n");
}

/*   Ajouter une programme*/
void AjouterProgramme(){

     FILE *F;
     int flagint = 1;
     do{
             int num;
             F = fopen(fichierProgramme,"ab");
             printf("\nEntrez l\'indice du programme de la classe : ");
             char term;
             fflush(stdin);
             if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
                 printf("\n Entrez un nombre svp!");
             }else{
                 while(recherche(num,fichierProgramme) == 1){
                      printf("\nCe numero existe déjà!");
                      AjouterProgramme();
                 }

                 Programme.id = num;
                 printf("\n Entrez la classe: ");
                 scanf("%s",&Programme.classe);
                 printf("\n Entrez l\'intitule: ");
                 scanf("%s",&Programme.intitule);
                 printf("\n Entrez l\'année d\'adoption: ");
                 scanf("%d",Programme.anneeAdoption);
                 printf("\n Entrez le nombre d\'UE du semestre I: ");
                 scanf("%d",Programme.nbreUESem1);
                 printf("\n Entrez le nombre d\'UE du semestre II: ");
                 scanf("%d",Programme.nbreUESem2);

                 fprintf(F,"%d ;%s ;%s ;%d ;%d ;%d \n"
                       ,Programme.id,Programme.classe,Programme.intitule,Programme.anneeAdoption,Programme.nbreUESem1,
                       Programme.nbreUESem2);
                 fflush(stdin);
                 fclose(F);
              /*---------------- GESTION DES LISTES D'UE SEMESTRE I---------------------*/
                      printf("\n LISTE D\' UEs DU SEMESTRE I: ");
                      printf("\n Selectionnez les UEs liés à ce programme");
                      int newflag=1;
                      int newnum;
                      FILE *ue;
                      FILE *newUE;
                 do{
                     ListeUE();
                     printf("\nEntrez l\'indice de l\'UE SEMESTRE I: ");
                     fflush(stdin);
                     char term;
                     if(scanf("%d%c",&newnum,&term)!=2 || term != '\n'){
                           printf("\n Entrez un nombre svp!");
                     }else{
                           while(recherche(newnum,fichierUE1) != 1){
                                 printf("\nCe numero n\' existe pas!");
                                 AjouterProgramme();
                            }

                               ue= fopen(fichierUE1,"r");
                            do{
                               fscanf(ue,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                      ,&UE.id,&UE.codeUE,&UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                                       &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE);

                                fflush(stdin);
                                if(UE.id == newnum){

                                       newUE = fopen(fichierUEChoix1,"ab");
                                       fprintf(newUE,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                               ,Programme.id,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                                                UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);
                                      //listeEC = insertion_EC_fin (listeEC,EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                                       fflush(stdin);
                                       fclose(newUE);

                                }
                           }while(!feof(ue));
                           fclose(ue);
                           fflush(stdin);
                            printf("\nVoulez vous continuer l\'ajout des UEs du semestre I? 1:Oui / 0:Non? ");
                            scanf("%d",&newflag);
                         }
                   }while(newflag == 1);
                 /*-------------------------------------------------------------*/

                  /*---------------- GESTION DES LISTES D'UE SEMESTRE II---------------------*/
                        printf("\n LISTE D\' UEs DU SEMESTRE II: ");
                      printf("\n Selectionnez les UEs liés à ce programme");
                       newflag=1;
                      newnum=0;
                 do{
                     ListeUE();
                     printf("\nEntrez l\'indice de l\'UE SEMESTRE II: ");
                     fflush(stdin);
                     char term;
                     if(scanf("%d%c",&newnum,&term)!=2 || term != '\n'){
                           printf("\n Entrez un nombre svp!");
                     }else{
                           while(recherche(newnum,fichierUE1) != 1){
                                 printf("\nCe numero n\' existe pas!");
                                 AjouterProgramme();
                            }
                               ue= fopen(fichierUE1,"r");
                            do{
                               fscanf(ue,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                      ,&UE.id,&UE.codeUE,&UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                                       &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE);

                                fflush(stdin);
                                if(UE.id == newnum){
                                       newUE = fopen(fichierUEChoix2,"ab");
                                       fprintf(newUE,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                               ,Programme.id,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                                                UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);
                                      //listeEC = insertion_EC_fin (listeEC,EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                                       fflush(stdin);
                                       fclose(newUE);

                                }
                           }while(!feof(ue));
                           fclose(ue);
                           fflush(stdin);
                            printf("\nVoulez vous continuer l\'ajout des UEs du semestre II? 1:Oui / 0:Non? ");
                            scanf("%d",&newflag);
                         }
                   }while(newflag == 1);
                 /*-------------------------------------------------------------*/

             }
        printf("\nVoulez vous continuer l\'ajout de programmes? 1:Oui / 0:Non? ");
        scanf("%d",&flagint);
     }while(flagint ==1);

}
/*   Fin ajout programme*/
void ModifierProgramme(){

 int num,i;
         char term,rep;
         FILE *newprogramme,*tmp;
         printf("\nEntrez l\'indice du programme: ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             if(recherche(num,fichierProgramme) == 1){
                  printf("\nVoulez vous vraiment modifier ce programme O/N? ");
                  scanf("%c",&rep);
                  fflush(stdin);
                  if(rep == 'o'||rep=='O'){

                     newprogramme = fopen(fichierProgramme,"r");
                      tmp = fopen("tmpue.txt","ab");
                      do{

                            fscanf(newprogramme,"%d ;%s ;%s ;%d ;%d ;%d \n"
                                  ,&Programme.id,&Programme.classe,&Programme.intitule,&Programme.anneeAdoption,&Programme.nbreUESem1,
                                  &Programme.nbreUESem2);
                            fflush(stdin);
                            if(Programme.id == num){

                                 Programme.id = num;
                                 printf("\n Entrez la classe: ");
                                 scanf("%s",&Programme.classe);
                                 printf("\n Entrez l\'intitule: ");
                                 scanf("%s",&Programme.intitule);
                                 printf("\n Entrez l\'année d\'adoption: ");
                                 scanf("%d",Programme.anneeAdoption);
                                 printf("\n Entrez le nombre d\'UE du semestre I: ");
                                 scanf("%d",Programme.nbreUESem1);
                                 printf("\n Entrez le nombre d\'UE du semestre II: ");
                                 scanf("%d",Programme.nbreUESem2);

                              /*---------------- GESTION DES LISTES D'UE SEMESTRE I---------------------*/
                                      //printf("\n Liste d\' EC: ");
                                      //scanf("%s",&Programme.listeUESem1);
                                 /*-------------------------------------------------------------*/

                                  /*---------------- GESTION DES LISTES D'UE SEMESTRE II---------------------*/
                                     // printf("\n Liste d\' EC: ");
                                      //scanf("%s",&Programme.listeUESem2);
                                 /*-------------------------------------------------------------*/
                            }
                            fprintf(tmp,"%d ;%s ;%s ;%d ;%d ;%d \n"
                                         ,Programme.id,Programme.classe,Programme.intitule,Programme.anneeAdoption,Programme.nbreUESem1,
                                          Programme.nbreUESem2);//,&Programme.listeUESem1,&Programme.listeUESem2
                      }while(!feof(newprogramme));
                      fclose(tmp);
                      fclose(newprogramme);
                      remove(fichierProgramme);
                      rename("tmpprogramme.txt",fichierProgramme);
                      printf("Modification éffectuée avec succès!\n\n");
                  }else{

                      printf("La modification à été annulée\n\n");
                  }

              }else{
                  printf("Ce numéro d\'ec n'existe pas!\n\n");
              }
         }

}
/*Supprimer Programme*/
void SupprimerProgramme(){

      int num;
         char term,rep;

         printf("\nEntrez l\'indice du programme : ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             if(recherche(num,fichierProgramme) == 1){
                  printf("\nVoulez vous vraiment supprimer O/N? ");
                  scanf("%c",&rep);
                  fflush(stdin);
                  if(rep == 'o'||rep=='O'){

                      FILE *tmp,*newprogramme,*newuechoix1,*tmpuechoix1,*newuechoix2,*tmpuechoix2;
                      newprogramme = fopen(fichierProgramme,"r");
                      tmp = fopen("tmpprogramme.txt","ab");

                      newuechoix1 = fopen(fichierUEChoix1,"r");
                      tmpuechoix1 = fopen("tmpuechoix1.txt","ab");

                      newuechoix2 = fopen(fichierUEChoix2,"r");
                      tmpuechoix2 = fopen("tmpuechoix2.txt","ab");
                      do{

                            fscanf(newprogramme,"%d ;%s ;%s ;%d ;%d ;%d \n"
                                  ,&Programme.id,&Programme.classe,&Programme.intitule,&Programme.anneeAdoption,&Programme.nbreUESem1,
                                  &Programme.nbreUESem2);//,&Programme.listeUESem1,&Programme.listeUESem2
                            fflush(stdin);
                            if(Programme.id != num){
                                  fprintf(tmp,"%d ;%s ;%s ;%d ;%d ;%d \n"
                                         ,&Programme.id,&Programme.classe,&Programme.intitule,&Programme.anneeAdoption,&Programme.nbreUESem1,
                                          &Programme.nbreUESem2);//,&Programme.listeUESem1,&Programme.listeUESem2
                            }
                      }while(!feof(newprogramme));
                      fclose(tmp);
                      fclose(newprogramme);
                      remove(fichierProgramme);
                      rename("tmpprogramme.txt",fichierProgramme);
                      /*suppression UEChoix1*/
                       do{

                            fprintf(newuechoix1,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                               ,Programme.id,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                                                UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);
                            fflush(stdin);
                            if(Programme.id != num){
                                   fprintf(tmpuechoix1,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                               ,Programme.id,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                                                UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);
                            }
                      }while(!feof(newuechoix1));
                      fclose(tmpuechoix1);
                      fclose(newuechoix1);
                      remove(fichierUEChoix1);
                      rename("tmpuechoix1.txt",fichierUEChoix1);
                      /*suppression UEChoix2*/
                      do{

                            fprintf(newuechoix2,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                               ,Programme.id,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                                                UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);
                            fflush(stdin);
                            if(Programme.id != num){
                                   fprintf(tmpuechoix2,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                               ,Programme.id,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                                                UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);
                            }
                      }while(!feof(newuechoix2));
                      fclose(tmpuechoix2);
                      fclose(newuechoix2);
                      remove(fichierUEChoix2);
                      rename("tmpuechoix2.txt",fichierUEChoix2);
                      printf("Suppression éffectuée avec succès!\n");

                  }
             }
         }

}
/* Supprimer Programme*/

 void ListeProgramme(){

    FILE *F;
    F = fopen(fichierProgramme,"r");
    char term;
    fflush(stdin);

        int i=0;
           do{
               fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d \n"
                     ,&Programme.id,&Programme.classe,&Programme.intitule,&Programme.anneeAdoption,&Programme.nbreUESem1,
                     &Programme.nbreUESem2);
                    fflush(stdin);
                        if(i==0){
                           printf("----------- INFORMATIONS SUR LE PROGRAMME -------------\n");
                        }
                           printf("\nClasse:\t%s",Programme.classe);
                           printf("\nIntitule UE:\t%s",Programme.intitule);
                           printf("\nAnnee d\'adoption:\t%d",Programme.anneeAdoption);
                           printf("\nNombre d\'UE semestre I:\t%d",Programme.nbreUESem1);
                           printf("\nNombre d\'UE semestre II:\t%d",Programme.nbreUESem2);
                           if(recherche(Programme.id,fichierUEChoix1) == 1){

                                listeUE(UE.id,fichierUEChoix1);
                           }
                           if(recherche(Programme.id,fichierUEChoix2) == 1){

                                listeUE(UE.id,fichierUEChoix2);
                           }
                          i =i +1;
           }while(!feof(F));
           fclose(F);
           printf("\n\n");
 }
 void RechercheProgramme(){

         FILE *F;
         F = fopen(fichierProgramme,"r");
         int num;
         printf("\n Entrez le numero de le programme rechercher: ");
         char term;
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
             fclose(F);
             RechercheProgramme();
         }else{
           int i=0;
           do{
               fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%s ;%s \n"
                     ,&Programme.id,&Programme.classe,&Programme.intitule,&Programme.anneeAdoption,&Programme.nbreUESem1,
                     &Programme.nbreUESem2,&Programme.listeUESem1,&Programme.listeUESem2);
                fflush(stdin);
                if(Programme.id == num){
                        if(i==0){
                           printf("----------- INFORMATIONS SUR LE PROGRAMME %d-------------\n",UE.id);
                        }
                           printf("Classe:\t%s",Programme.classe);
                           printf("Intitule UE:\t%s",Programme.intitule);
                           printf("Annee d\'adoption:\t%d",Programme.anneeAdoption);
                           printf("Nombre d\'UE semestre I:\t%d",Programme.nbreUESem1);
                           printf("Nombre d\'UE semestre II:\t%d",Programme.nbreUESem2);
                           printf("UE semestre I:\t%s",Programme.listeUESem1);
                           printf("UE semestre II:\t%s",Programme.listeUESem2);
                           i =i +1;
                }
           }while(!feof(F));
           fclose(F);
           printf("\n\n");
         }
 };
