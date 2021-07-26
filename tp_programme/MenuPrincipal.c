#include <stdio.h>
#include <stdlib.h>
#include "Recherches.h"
#include "EC.h"
#include "Classe.h"
#include "UE.h"
#include "Programme.h"
#include "MenuPrincipal.h"


void menuPrincipal(){

     int b;

     do
        {
             printf("************************************************\n");
             printf("                  MENU OPERATION                \n");
             printf("************************************************");
             printf("\n");
             printf("\n 1. Operation sur EC");
             printf("\n 2. Operation sur UE");
             printf("\n 3. Operation sur Classe");
             printf("\n 4. Operation sur Programme");
             printf("\n 5. Sortir");
             printf("\n***********************************************");
             printf("\n Quel operation voulez-vous effectuer : ");

             scanf("%d",&b);
             switch (b)
                { 		case 1: menuec();break;
                        case 2: menuue();break;
                        case 3: menuclasse();break;
                        case 4: menuprogramme();break;
                }
        }while (b>0 && b<5);
}
