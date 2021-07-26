#include <stdio.h>
#include <stdlib.h>
#include "Objets.h"
#include "Classe.h"
#include "Recherches.h"
#include "MenuPrincipal.h"


char *fichierClasses = "Classe.txt";

/*   Ajouter une CLASSE*/
void AjouterClasse(){

    FILE *classe;
    int flagint=1;
    do {
         int num;
         char term;
         classe = fopen(fichierClasses,"ab");
         printf("\nEntrez l\'indice de la classe : ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             while(recherche(num,fichierClasses) == 1){
                  printf("\nCe numero existe déjà!");
                  AjouterClasse();
             }

             Classe.id = num;
             printf("\n Entrez le code de la classe: ");
             scanf("%s",&Classe.codeClasse);
             printf("\n Entrez l\'institution: ");
             scanf("%s",&Classe.institution);
             printf("\n Entrez le nom de l\'etablissement: ");
             scanf("%s",&Classe.etablissement);
             printf("\n Entrez le nom du departement: ");
             scanf("%s",&Classe.departement);
             printf("\n Entrez le parcours: ");
             scanf("%s",&Classe.parcours);
             printf("\n Entrez le niveau: ");
             scanf("%d",&Classe.niveau);

             fprintf(classe,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n"
                   ,Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,
                   Classe.departement,Classe.parcours,Classe.niveau);
             fclose(classe);
             printf("\nDonnées enregistrés avec succès!\n");
             printf("\nVoulez vous continuer  1:Oui / 0:Non? ");
             scanf("%c",&flagint);
         }


     }while(flagint==1);

}
/*   Fin ajout CLASSE*/

/*Supprimer classe*/
void SupprimerClasse(){

         int num;
         char term,rep;

         printf("\nEntrez l\'indice de la classe : ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             if(recherche(num,fichierClasses) == 1){
                  printf("\nVoulez vous vraiment supprimer O/N? ");
                  scanf("%c",&rep);
                  fflush(stdin);
                  if(rep == 'o'||rep=='O'){
                      FILE *tmp,*newclasse;
                      newclasse = fopen(fichierClasses,"r");
                      tmp = fopen("tmpClasse.txt","ab");
                      do{

                            fscanf(newclasse,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n"
                                ,&Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,
                                 Classe.departement,Classe.parcours,&Classe.niveau);
                            fflush(stdin);
                            if(Classe.id != num){
                                  fprintf(tmp,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n"
                                      ,Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,
                                       Classe.departement,Classe.parcours,Classe.niveau);
                             }
                      }while(!feof(newclasse));
                      fclose(tmp);
                      fclose(newclasse);
                      remove(fichierClasses);
                      rename("tmpClasse.txt",fichierClasses);
                      printf("Suppression éffectuée avec succès!\n");

                  }
             }
         }

}
/* Supprimer classe*/

void RechercheClasse(){

    FILE *F;
    F = fopen(fichierClasses,"r");
    int num;
    printf("\n Entrez le numero de la classe rechercher: ");
    char term;
    fflush(stdin);
    if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
         printf("\n Entrez un nombre svp!");
         fclose(F);
     }else{

        int i=0;
           do{
               fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n"
               ,&Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,
               Classe.departement,Classe.parcours,&Classe.niveau);
                fflush(stdin);
                if(Classe.id == num){
                    if(i==0){
                       printf("\n\n--------------------- INFORMATIONS SUR LA CLASSE %d------------------------------\n",Classe.id);
                       printf("--------------------------------------------------------------------------------\n");
                       printf("| Code\t| Institution\t| Etablissement\t| Departement\t| Parcours| Niveau\t|\n");

                    }
                       printf("--------------------------------------------------------------------------------\n");
                       printf("| %s\t| %s\t\t| %s\t\t| %s\t\t| %s\t\t| %d\t",Classe.codeClasse,Classe.institution,Classe.etablissement,Classe.departement,Classe.parcours,Classe.niveau);
                       i = i+1;
                }

           }while(!feof(F));
           fclose(F);
           printf("\n\n");
      }

}

void ModifierClasse(){

         int num,i;
         char term,rep;
         FILE *newclasse,*tmp;
         printf("\nEntrez l\'indice de la classe : ");
         fflush(stdin);
         if(scanf("%d%c",&num,&term)!=2 || term != '\n'){
             printf("\n Entrez un nombre svp!");
         }else{

             if(recherche(num,fichierClasses) == 1){
                  printf("\nVoulez vous vraiment modifier cette classe O/N? ");
                  scanf("%c",&rep);
                  fflush(stdin);
                  if(rep == 'o'||rep=='O'){

                     newclasse = fopen(fichierClasses,"r");
                      tmp = fopen("tmpClasse.txt","ab");
                      do{

                            fscanf(newclasse,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n"
                                ,&Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,
                                 Classe.departement,Classe.parcours,&Classe.niveau);
                            fflush(stdin);
                            if(Classe.id == num){

                                     Classe.id = num;
                                     printf("\n Entrez le nouveau code de la classe: ");
                                     scanf("%s",&Classe.codeClasse);
                                     printf("\n Entrez la nouvelle l\'institution: ");
                                     scanf("%s",&Classe.institution);
                                     printf("\n Entrez le nouveau nom de l\'etablissement: ");
                                     scanf("%s",&Classe.etablissement);
                                     printf("\n Entrez le nouveau nom du departement: ");
                                     scanf("%s",&Classe.departement);
                                     printf("\n Entrez le nouveau parcours: ");
                                     scanf("%s",&Classe.parcours);
                                     printf("\n Entrez le nouveau niveau: ");
                                     scanf("%d",&Classe.niveau);
                            }
                            fprintf(tmp,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n"
                                      ,Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,
                                       Classe.departement,Classe.parcours,Classe.niveau);
                      }while(!feof(newclasse));
                      fclose(tmp);
                      fclose(newclasse);
                      remove(fichierClasses);
                      rename("tmpClasse.txt",fichierClasses);
                      printf("Modification éffectuée avec succès!\n");
                  }else{

                      printf("La modification à été annulée\n");
                  }

              }else{
                  printf("Ce numéro de classe n'existe pas!\n");
              }
         }
}

void ListeClasse(){

    FILE *F;
    F = fopen(fichierClasses,"r");
    char term;
    fflush(stdin);

        int i=0;
           do{
               fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d \n"
               ,&Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,
               Classe.departement,Classe.parcours,&Classe.niveau);
                fflush(stdin);
                    if(i==0){
                       printf("\n\n--------------------- INFORMATIONS SUR LA CLASSE ------------------------------\n");
                       printf("--------------------------------------------------------------------------------\n");
                       printf("| ID | Code | Institution | Etablissement | Departement | Parcours | Niveau  |\n");

                    }
                       printf("\n\n| %d | %s | %s     | %s    | %s     | %s    | %d |",Classe.id,Classe.codeClasse,Classe.institution,Classe.etablissement,Classe.departement,Classe.parcours,Classe.niveau);
                       i = i+1;

           }while(!feof(F));
           fclose(F);
           printf("\n\n");

}

void menuclasse(){

    int b;
     do
        {
             printf("\n\n************************************************\n");
             printf("                  MENU CLASSES                       \n");
             printf("************************************************");
             printf("\n");
             printf("\n 1. Ajouter une classe");
             printf("\n 2. Lister les classes");
             printf("\n 3. Modifier des classes");
             printf("\n 4. Supprimer une classe");
             printf("\n 5. Rechercher une classe");
             printf("\n 6. Sortir");
             printf("\n***********************************************");
             printf("\n Quel operation voulez-vous effectuer : ");

             scanf("%d",&b);
             switch (b)
                { 		case 1: AjouterClasse();break;
                        case 2: ListeClasse();break;
                        case 3: ModifierClasse();break;
                        case 4: SupprimerClasse();break;
                        case 5: RechercheClasse();break;
                }
        }while (b>0 && b<6);

         menuPrincipal();
}


