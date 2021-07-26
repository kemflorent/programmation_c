#include <stdio.h>
#include <stdlib.h>
#include "Objets.h"
#include "EC.h"
#include "Recherches.h"
#include "MenuPrincipal.h"

char *fichierEC = "EC.txt";

void menuec(){
     int b;
     do
        {
             printf("************************************************\n");
             printf("                  MENU EC                       \n");
             printf("************************************************");
             printf("\n");
             printf("\n 1. Ajouter un EC");
             printf("\n 2. Lister les ECs");
             printf("\n 3. Modifier les ECs");
             printf("\n 4. Supprimer un EC");
             printf("\n 5. Rechercher un EC");
             printf("\n 6. Sortir");
             printf("\n***********************************************");
             printf("\n Quel operation voulez-vous effectuer : ");

             scanf("%d",&b);
             switch (b)
                { 		case 1: AjouterEC();break;
                        case 2: ListeEC();break;
                        case 3: ModifierEC();break;
                        case 4: SupprimerEC();break;
                        case 5: RechercheEC();break;
                }
        }while (b>0 && b<6);

         menuPrincipal();
}

void ModifierEC(){

    int num,i;
         char term,rep;
         FILE *newec,*tmp;
         printf("\nEntrez l\'indice de l\'EC : ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             if(recherche(num,fichierEC) == 1){
                  printf("\nVoulez vous vraiment modifier cet EC O/N? ");
                  scanf("%c",&rep);
                  fflush(stdin);
                  if(rep == 'o'||rep=='O'){

                     newec = fopen(fichierEC,"r");
                      tmp = fopen("tmpec.txt","ab");
                      do{

                            fscanf(newec,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                   ,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                                   &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                            fflush(stdin);
                            if(EC.id == num){

                                 EC.id = num;
                                 printf("\n Entrez le code de l\'EC: ");
                                 scanf("%s",&EC.codeEC);
                                 printf("\n Entrez le libelle de l\'EC: ");
                                 scanf("%s",&EC.libelleEC);
                                 printf("\n Entrez le volume horaire des TDs: ");
                                 scanf("%d",&EC.valTD);
                                 printf("\n Entrez le volume horaire des TPs: ");
                                 scanf("%d",&EC.valTP);
                                 printf("\n Entrez le volume horaire des TPEs: ");
                                 scanf("%d",&EC.valTPE);
                                 printf("\n Entrez le volume horaire des CMs: ");
                                 scanf("%d",&EC.valCM);
                                 printf("\n Entrez le coefficient des CCs: ");
                                 scanf("%f",&EC.coefCC);
                                 printf("\n Entrez le coefficient des Examens: ");
                                 scanf("%f",&EC.coefEX);
                                 printf("\n Entrez le coefficient des TPs: ");
                                 scanf("%f",&EC.coefTP);
                                 printf("\n Entrez le coefficient des TPEs: ");
                                 scanf("%f",&EC.coefTPE);
                                 printf("\n Entrez le nombre de Credit: ");
                                 scanf("%d",&EC.credits);
                                 printf("\n Entrez le niveau d\'etude: ");
                                 scanf("%f",&EC.niveau);
                            }
                            fprintf(tmp,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                   ,EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,
                                    EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                      }while(!feof(newec));
                      fclose(tmp);
                      fclose(newec);
                      remove(fichierEC);
                      rename("tmpec.txt",fichierEC);
                      printf("Modification éffectuée avec succès!\n\n");
                  }else{

                      printf("La modification à été annulée\n\n");
                  }

              }else{
                  printf("Ce numéro d\'ec n'existe pas!\n\n");
              }
         }
}
/*   Ajouter un EC*/
void AjouterEC(){

     FILE *F;
     int flagint = 1;
     do {
         int num;
         F = fopen(fichierEC,"ab");
         printf("\nEntrez l\'indice de l\'EC : ");
         char term;
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{
             while(recherche(num,fichierEC) == 1){
                  printf("\nCe numero existe déjà!");
                  AjouterEC();
             }

             EC.id = num;
             printf("\n Entrez le code de l\'EC: ");
             scanf("%s",&EC.codeEC);
             printf("\n Entrez le libelle de l\'EC: ");
             scanf("%s",&EC.libelleEC);
             printf("\n Entrez le volume horaire des TDs: ");
             scanf("%d",&EC.valTD);
             printf("\n Entrez le volume horaire des TPs: ");
             scanf("%d",&EC.valTP);
             printf("\n Entrez le volume horaire des TPEs: ");
             scanf("%d",&EC.valTPE);
             printf("\n Entrez le volume horaire des CMs: ");
             scanf("%d",&EC.valCM);
             printf("\n Entrez le coefficient des CCs: ");
             scanf("%f",&EC.coefCC);
             printf("\n Entrez le coefficient des Examens: ");
             scanf("%f",&EC.coefEX);
             printf("\n Entrez le coefficient des TPs: ");
             scanf("%f",&EC.coefTP);
             printf("\n Entrez le coefficient des TPEs: ");
             scanf("%f",&EC.coefTPE);
             printf("\n Entrez le nombre de Credit: ");
             scanf("%d",&EC.credits);
             printf("\n Entrez le niveau d\'etude: ");
             scanf("%f",&EC.niveau);
             fprintf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                   ,EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,
                    EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
             fflush(stdin);
             fclose(F);
             printf("\nDonnées enregistrés avec succès!\n");

         }
         printf("\nVoulez vous continuer 1:Oui / 0:Non? ");
         scanf("%d",&flagint);

     }while(flagint == 1);
}
/*Fin ajout EC*/

/*Supprimer EC*/
void SupprimerEC(){

   int num;
         char term,rep;

         printf("\nEntrez l\'indice de l\'EC : ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             if(recherche(num,fichierEC) == 1){
                  printf("\nVoulez vous vraiment supprimer O/N? ");
                  scanf("%c",&rep);
                  fflush(stdin);
                  if(rep == 'o'||rep=='O'){
                      FILE *tmp,*newec;
                      newec = fopen(fichierEC,"r");
                      tmp = fopen("tmpec.txt","ab");
                      do{

                            fscanf(newec,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                   ,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                                   &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                            fflush(stdin);
                            if(EC.id != num){
                                  fprintf(tmp,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                         ,EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,
                                         EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                             }
                      }while(!feof(newec));
                      fclose(tmp);
                      fclose(newec);
                      remove(fichierEC);
                      rename("tmpec.txt",fichierEC);
                      printf("Suppression éffectuée avec succès!\n");

                  }
             }
         }

}
/*Fin Suppression EC*/

void ListeEC(){

    FILE *F;
    F = fopen(fichierEC,"r");
    char term;
    fflush(stdin);

        int i=0;
           do{
                fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                   ,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                    &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                    fflush(stdin);
                         if(i==0){
                               printf("\n\n--------------------- INFORMATIONS SUR LES ECs ------------------------------\n");
                               printf("--------------------------------------------------------------------------------\n");
                               printf("|ID\t| Libelle EC\t| Vol Horaire TD\t| Vol Horaire TP\t| Vol Horaire TPE\t| Vol Horaire CM\t| Credits\t| Niveau\t| Coef CC\t| Coef Exam\t| Coef TP\t| Coef TPE\t");
                         }

                       //printf("--------------------------------------------------------------------------------\n");
                       printf("|%d\t| %s\t| %s\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %f\t| %f\t| %f\t| %f\t",EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                       i = i+1;

           }while(!feof(F));
           fclose(F);
           printf("\n\n");

}

void RechercheEC(){


       FILE *F;
       F = fopen(fichierEC,"r");
       int num;
        printf("\n Entrez le numero de l\' EC rechercher: ");
        char term;
        fflush(stdin);
        if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{
             int i=0;
              do{
                   fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                   ,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                    &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                    fflush(stdin);
                    if(EC.id == num){
                         if(i==0){
                               printf("\n\n--------------------- INFORMATIONS SUR L\'EC %d------------------------------\n",EC.id);
                               printf("--------------------------------------------------------------------------------\n");
                               printf("| Libelle EC\t| Vol Horaire TD\t| Vol Horaire TP\t| Vol Horaire TPE\t| Vol Horaire CM\t| Credits\t| Niveau\t| Coef CC\t| Coef Exam\t| Coef TP\t| Coef TPE\t");
                         }

                       printf("--------------------------------------------------------------------------------\n");
                       printf("%s\t| %s\t| %d\t| %d\t| %d\t| %d\t| %d\t| %d\t| %f\t| %f\t| %f\t| %f\t",EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                       i = i+1;
                    }
              }while(!feof(F));
              fclose(F);
              printf("\n\n");
        }
}
