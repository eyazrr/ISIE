#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;
typedef struct
{
    int idm;
    int nbrhabitants;
    int nbrconseiller;
    char nom [50];
} municipalite ;
typedef struct
{
int id;
municipalite m;
Date d;
} election;
int ajouterelection( char * filename , election e );
int modifierelection(int id, election nouv, char * filename);
int supprimerelection(int id, char * filename);
election chercherelection( char * filename,int id);



#endif // FUNCTION_H_INCLUDED

