#include <stdio.h>
#include <stdlib.h>
#include "Objets.h"
#include "EC.h"
#include "UE.h"
#include "Recherches.h"
#include "MenuPrincipal.h"

char *fichierUE = "UE.txt";

char *fichierEC1 = "EC.txt";

char *fichierUEChoix = "UEChoix.txt";

void listeEC(int id){


     FILE *F;

     F = fopen(fichierUEChoix,"r");
     int j=0;
     do{
               fscanf(F,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                     ,&UE.id,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                     &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
              fflush(stdin);
              if(UE.id == id){
                              if(j==0){
                                        printf("\n\n\t\t--------------- LISTE DES ECs DE l\' UE %d---------------\n",UE.id);
                                        printf("\t\t---------------------------------------------------------\n");
                                        printf("| ID\t| Code EC\t| Libelle EC\t|");
                              }
                               printf("\n| %d\t| %s\t| %s\t|",EC.id,EC.codeEC,EC.libelleEC);
                               /*printf("\t\t\n\nCode EC:\t%s");
                               printf("\t\t\n\nLibelle EC:\t%s");
                               printf("\t\t\n\nVol Horaire TD:\t%d",EC.valTD);
                               printf("\t\t\n\nVol Horaire TP:\t%d",EC.valTP);
                               printf("\t\t\n\nVol Horaire TPE:\t%d",EC.valTPE);
                               printf("\t\t\n\nVol Horaire CM:\t%d",EC.valCM);
                               printf("\t\t\n\nCredits:\t%d",EC.credits);
                               printf("\t\t\n\nNiveau:\t%d",EC.niveau);
                               printf("\t\t\n\nCoef CC:\t%f",EC.coefCC);
                               printf("\t\t\n\nCoef Exam:\t%f",EC.coefEX);
                               printf("\t\t\n\nCoef TP:\t%f",EC.coefTP);
                               printf("\t\t\n\nCoef TPE:\t%f",EC.coefTPE);*/
                          j = j+1;
               }
     }while(!feof(F));
      fclose(F);
      printf("\n\n");
}
void menuue(){

    int b;
     do
        {
             printf("\n\n************************************************\n");
             printf("                  MENU UE                       \n");
             printf("************************************************");
             printf("\n");
             printf("\n 1. Ajouter un UE");
             printf("\n 2. Lister les UE");
             printf("\n 3. Modifier les UEs");
             printf("\n 4. Supprimer un UE");
             printf("\n 5. Rechercher un UE");
             printf("\n 6. Sortir");
             printf("\n***********************************************");
             printf("\n Quel operation voulez-vous effectuer : ");

             scanf("%d",&b);
             switch (b)
                { 		case 1: AjouterUE();break;
                        case 2: ListeUE();break;
                        case 3: ModifierUE();break;
                        case 4: SupprimerUE();break;
                        case 5: RechercheUE();break;
                }
        }while (b>0 && b<6);

       menuPrincipal();
}

/*void afficher(struct T_EC *L)
{
	struct T_EC *courant=L;
	printf("\t\tLISTES SIMPLEMENT CHAINÉE\n\n");
	while(courant!=NULL)
	{
		printf("\t%d",courant->id);
		printf("\t%s",courant->codeEC);
		printf("\t%s",courant->libelleEC);
		printf("\t%d",courant->valTD);
		printf("\t%d",courant->valTP);
		printf("\t%d",courant->valTPE);
		printf("\t%d",courant->valCM);
		printf("\t%f",courant->coefCC);
		printf("\t%f",courant->coefEX);
		printf("\t%f",courant->coefTP);
		printf("\t%f",courant->coefTPE);
		printf("\t%d",courant->credits);
		printf("\t%d",courant->niveau);
		courant=courant->ECSuivant;
	}
}
struct T_EC *insertion_EC_fin (struct T_EC *premier,int id,char codeEC[100],char libelleEC[100],int valTD,int valTP,int valTPE,int valCM,int credits,int niveau,float coefCC,float coefEX,float coefTP,float coefTPE){


	struct T_EC *nouvel_element;
	nouvel_element = malloc(sizeof(*nouvel_element));
	nouvel_element->id = id;
	memset(nouvel_element->codeEC,'\0',sizeof(nouvel_element->codeEC));
	strncpy(nouvel_element->codeEC,codeEC,100);
	memset(nouvel_element->libelleEC,'\0',sizeof(nouvel_element->libelleEC));
	strncpy(nouvel_element->libelleEC, libelleEC,100);
	nouvel_element->valTD = valTD;
	nouvel_element->valTP = valTP;
	nouvel_element->valTPE = valTPE;
	nouvel_element->valCM = valCM;
	nouvel_element->coefCC = coefCC;
	nouvel_element->coefEX = coefEX;
	nouvel_element->coefTP = coefTP;
	nouvel_element->coefTPE = coefTPE;
	nouvel_element->credits = credits;
	nouvel_element->niveau = niveau;
	nouvel_element->ECSuivant = NULL;
	if(premier==NULL){
	  return nouvel_element;
	}else {
		 struct T_EC *courant = premier;
		while (courant->ECSuivant!=NULL)
		{
			courant = courant->ECSuivant;
		}
		courant->ECSuivant = nouvel_element;
		return premier;
	}

}*/

/*   Ajouter un UE*/
void AjouterUE(){

    FILE *F;
    int flagint = 1;
    do {
         int num;
         F = fopen(fichierUE,"ab");
         printf("\nEntrez l\'indice de l\'UE : ");
         char term;
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{
             while(recherche(num,fichierUE) == 1){
                  printf("\nCe numero existe déjà!");
                  AjouterUE();
             }
             struct T_EC *listeEC = NULL;
             UE.id = num;
             printf("\n Entrez le code de l\'UE: ");
             scanf("%s",&UE.codeUE);
             printf("\n Entrez le libelle de l\'UE: ");
             scanf("%s",&UE.libelleUE);
             printf("\n Entrez le volume horaire des TDs: ");
             scanf("%d",&UE.valTD);
             printf("\n Entrez le volume horaire des TPs: ");
             scanf("%d",&UE.valTP);
             printf("\n Entrez le volume horaire des CMs: ");
             scanf("%d",&UE.valCM);
             printf("\n Entrez le coefficient des CCs: ");
             scanf("%f",&UE.coefCC);
             printf("\n Entrez le coefficient des Examens: ");
             scanf("%f",&UE.coefEX);
             printf("\n Entrez le coefficient des TPs: ");
             scanf("%f",&UE.coefTP);
             printf("\n Entrez le coefficient des TPEs: ");
             scanf("%f",&UE.coefTPE);
             printf("\n Entrez le nombre de Credit: ");
             scanf("%d",&UE.credits);
             printf("\n Entrez le nombre d\' EC: ");
             scanf("%d",&UE.nbreEC);
             fprintf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                   ,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                    UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);
             fflush(stdin);
             fclose(F);
             /*---------------- GESTION DES LISTES D'EC---------------------*/

             printf("\n Selectionnez les ECs liés à cet UE");
             int newflag=1;
             int newnum;
             do{
                     ListeEC();
                     printf("\nEntrez l\'indice de l\'EC : ");
                     fflush(stdin);
                     char term;
                     if(scanf("%d%c",&newnum,&term)!=2 || term != '\n'){
                           printf("\n Entrez un nombre svp!");
                     }else{
                           while(recherche(newnum,fichierEC1) != 1){
                                 printf("\nCe numero n\' existe pas!");
                                 AjouterEC();
                            }
                             FILE *ec;
                               ec= fopen(fichierEC1,"r");
                            do{
                               fscanf(ec,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                               ,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                                &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                                fflush(stdin);
                                if(EC.id == newnum){
                                       FILE *newEC;
                                       newEC = fopen(fichierUEChoix,"ab");
                                       fprintf(newEC,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                           ,UE.id,EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,
                                            EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                                      //listeEC = insertion_EC_fin (listeEC,EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                                       fflush(stdin);
                                       fclose(newEC);

                                }
                           }while(!feof(ec));
                           fclose(ec);
                           fflush(stdin);
                            printf("\nVoulez vous continuer l\'ajout des ECs? 1:Oui / 0:Non? ");
                            scanf("%d",&newflag);
                     }
             }while(newflag == 1);
             /*-------------------------------------------------------------*/

         printf("\nVoulez vous continuer l\'ajout des UEs? 1:Oui / 0:Non? ");
         scanf("%d",&flagint);
         }

  }while(flagint ==1);

}
/*   Fin ajout UE*/

void ModifierUE(){

    int num,i;
         char term,rep;
         FILE *newue,*tmp;
         printf("\nEntrez l\'indice de l\'UE: ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             if(recherche(num,fichierUE) == 1){
                  printf("\nVoulez vous vraiment modifier cet UE O/N? ");
                  scanf("%c",&rep);
                  fflush(stdin);
                  if(rep == 'o'||rep=='O'){

                     newue = fopen(fichierUE,"r");
                      tmp = fopen("tmpue.txt","ab");
                      do{

                            fscanf(newue,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                   ,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                                   &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                            fflush(stdin);
                            if(UE.id == num){

                                 UE.id = num;
                                 printf("\n Entrez le code de l\'UE: ");
                                 scanf("%s",&UE.codeUE);
                                 printf("\n Entrez le libelle de l\'UE: ");
                                 scanf("%s",&UE.libelleUE);
                                 printf("\n Entrez le volume horaire des TDs: ");
                                 scanf("%d",&UE.valTD);
                                 printf("\n Entrez le volume horaire des TPs: ");
                                 scanf("%d",&UE.valTP);
                                 printf("\n Entrez le volume horaire des CMs: ");
                                 scanf("%d",&UE.valCM);
                                 printf("\n Entrez le coefficient des CCs: ");
                                 scanf("%f",&UE.coefCC);
                                 printf("\n Entrez le coefficient des Examens: ");
                                 scanf("%f",&UE.coefEX);
                                 printf("\n Entrez le coefficient des TPs: ");
                                 scanf("%f",&UE.coefTP);
                                 printf("\n Entrez le coefficient des TPEs: ");
                                 scanf("%f",&UE.coefTPE);
                                 printf("\n Entrez le nombre de Credit: ");
                                 scanf("%d",&UE.credits);
                                 printf("\n Entrez le nombre d\' EC: ");
                                 scanf("%d",&UE.nbreEC);
                                /*---------------- GESTION DES LISTES D'EC---------------------*/
                                /* printf("\n Liste d\' EC: ");
                                 scanf("%s",&UE.listeEC);*/
                            }
                            fprintf(tmp,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                  ,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                                  UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);

                      }while(!feof(newue));
                      fclose(tmp);
                      fclose(newue);
                      remove(fichierUE);
                      rename("tmpue.txt",fichierUE);
                      printf("Modification éffectuée avec succès!\n\n");
                  }else{

                      printf("La modification à été annulée\n\n");
                  }

              }else{
                  printf("Ce numéro d\'ec n'existe pas!\n\n");
              }
         }
}

/*Supprimer UE*/
void SupprimerUE(){

      int num;
         char term,rep;

         printf("\nEntrez l\'indice de l\'UE : ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             if(recherche(num,fichierUE) == 1){
                  printf("\nVoulez vous vraiment supprimer O/N? ");
                  scanf("%c",&rep);
                  fflush(stdin);
                  if(rep == 'o'||rep=='O'){
                      FILE *tmp,*newue,*tmpuechoix,*newuechoix;
                      newue = fopen(fichierUE,"r");
                      newuechoix = fopen(fichierUEChoix,"r");
                      tmp = fopen("tmpue.txt","ab");
                      tmpuechoix = fopen("tmpuechoix.txt","ab");
                      do{

                            fscanf(newue,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                      ,&UE.id,&UE.codeUE,&UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                                       &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE);
                            fflush(stdin);
                            if(UE.id != num){
                                  fprintf(tmp,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                           ,UE.id,UE.codeUE,UE.libelleUE,UE.valTD,UE.valTP,UE.valCM,UE.credits,
                                            UE.nbreEC,UE.coefCC,UE.coefEX,UE.coefTP,UE.coefTPE);
                             }
                      }while(!feof(newue));
                      fclose(tmp);
                      fclose(newue);
                      remove(fichierUE);
                      rename("tmpue.txt",fichierUE);
                       do{
                            fscanf(newuechoix,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                     ,&UE.id,&EC.id,&EC.codeEC,&EC.libelleEC,&EC.valTD,&EC.valTP,&EC.valTPE,&EC.valCM,&EC.credits,
                                     &EC.niveau,&EC.coefCC,&EC.coefEX,&EC.coefTP,&EC.coefTPE);
                            fflush(stdin);
                            if(UE.id != num){
                                  fprintf(tmpuechoix,"%d ;%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                                           ,UE.id,EC.id,EC.codeEC,EC.libelleEC,EC.valTD,EC.valTP,EC.valTPE,EC.valCM,EC.credits,
                                            EC.niveau,EC.coefCC,EC.coefEX,EC.coefTP,EC.coefTPE);
                             }
                      }while(!feof(newuechoix));
                      fclose(tmpuechoix);
                      fclose(newuechoix);
                      remove(fichierUEChoix);
                      rename("tmpuechoix.txt",fichierUEChoix);

                      printf("Suppression éffectuée avec succès!\n");

                  }
             }
         }
}
/* Supprimer UE*/


 void ListeUE(){

    FILE *F;

    F = fopen(fichierUE,"r");
    char term;
    fflush(stdin);

        int i=0;
           do{
               fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                   ,&UE.id,&UE.codeUE,&UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                    &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE);
                    fflush(stdin);
                        if(i==0){
                           printf("----------- INFORMATIONS SUR L\'UE %d-------------\n",UE.id);
                           printf("\t\t---------------------------------------------------------\n");

                        }
                           printf("\n\nID:\t%d",UE.id);
                           printf("\n\nCode UE:\t%s",UE.codeUE);
                           printf("\n\nLibelle UE:\t%s",UE.libelleUE);
                           printf("\n\nVolume Horaire TD:\t%d",UE.valTD);
                           printf("\n\nVolume Horaire TP:\t%d",UE.valTP);
                           printf("\n\nVolume Horaire CM:\t%d",UE.valCM);
                           printf("\n\nCredits:\t%d",UE.credits);
                           printf("\n\nNombre d\'EC:\t%d",UE.nbreEC);
                           printf("\n\nCoefficient CC:\t%f",UE.coefCC);
                           printf("\n\nCoefficient Examen:\t%f",UE.coefEX);
                           printf("\n\nCoefficient TP:\t%f",UE.coefTP);
                           printf("\n\nCoefficient TPE:\t%f",UE.coefTPE);

                           if(recherche(UE.id,fichierUEChoix) == 1){
                                printf("%d",UE.id);
                                listeEC(UE.id);
                           }
                           i =i +1;
           }while(!feof(F));
           fclose(F);
           printf("\n\n");
 }
void RechercheUE(){

        FILE *F;
        F = fopen(fichierUE,"r");
        int num;
        printf("\n Entrez le numero de l\' UE rechercher: ");
        char term;
        fflush(stdin);
        if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
             fclose(F);
             RechercheUE();
         }else{
            int i=0;
               do{
                   fscanf(F,"%d ;%s ;%s ;%d ;%d ;%d ;%d ;%d ;%f ;%f ;%f ;%f \n"
                   ,&UE.id,&UE.codeUE,&UE.libelleUE,&UE.valTD,&UE.valTP,&UE.valCM,&UE.credits,
                    &UE.nbreEC,&UE.coefCC,&UE.coefEX,&UE.coefTP,&UE.coefTPE);
                    fflush(stdin);
                    if(UE.id == num){
                        if(i==0){
                           printf("----------- INFORMATIONS SUR L\'UE %d-------------\n",UE.id);
                        }
                           printf("\n\nCode UE:\t%s",UE.codeUE);
                           printf("\n\nLibelle UE:\t%s",UE.libelleUE);
                           printf("\n\nVolume Horaire TD:\t%d",UE.valTD);
                           printf("\n\nVolume Horaire TP:\t%d",UE.valTP);
                           printf("\n\nVolume Horaire CM:\t%d",UE.valCM);
                           printf("\n\nCredits:\t%d",UE.credits);
                           printf("\n\nNombre d\'EC:\t%d",UE.nbreEC);
                           printf("\n\nCoefficient CC:\t%f",UE.coefCC);
                           printf("\n\nCoefficient Examen:\t%f",UE.coefEX);
                           printf("\n\nCoefficient TP:\t%f",UE.coefTP);
                           printf("\n\nCoefficient TPE:\t%f",UE.coefTPE);
                           //printf("Liste des EC\t%s",UE.listeEC);
                          i =i +1;
                    }
               }while(!feof(F));
               fclose(F);
               printf("\n\n");
        }

};

