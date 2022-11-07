#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct
{
    int jour;
    int mois;
    int annee;
}Dateelection;
typedef struct
{
int id;
int nbrhabitants;
int nbrconseiller;
int municipalite;
Dateelection date;
}election;
int ajouterelection( char * filename , election e );
int modifierelection(int id, election nouv, char * filename);
int supprimerelection(int id, char * filename);
election chercherelection( char * filename,int id);


#endif // FONCTION_H_INCLUDED

