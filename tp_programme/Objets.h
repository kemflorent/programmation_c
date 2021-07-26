#ifndef OBJETS_H_INCLUDED
#define OBJETS_H_INCLUDED



struct T_Classe Classe;
struct T_Classe{
     int id;
     char codeClasse[100],institution[100],etablissement[100],departement[100];
     char parcours[100];
     int niveau;
 };

struct T_EC EC;
struct T_EC{
     int id;
     char codeEC[100],libelleEC[100];
     int valTD,valTP,valTPE,valCM;
     float coefCC,coefEX,coefTP,coefTPE;
     int credits,niveau;
     struct T_EC *ECSuivant;
};

struct T_UE UE;
struct T_UE{
     int id;
     char codeUE[100],libelleUE[100];
     int valTD,valTP,valCM;
     float coefCC,coefEX,coefTP,coefTPE;
     int credits,nbreEC;
     struct T_EC *listeEC;
     struct T_UE *UESuivant;
};

struct T_Programme Programme;
struct T_Programme{
     int id;
     char classe[100],intitule[100];
     int anneeAdoption;
     int nbreUESem1,nbreUESem2;
     struct T_UE *listeUESem1,*listeUESem2;
};

#endif // OBJETS_H_INCLUDED
