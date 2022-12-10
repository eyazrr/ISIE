#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct
{
    int jour;
    char mois[20];
    int annee;
} Date;
typedef struct
{
    char municipalite [50];
    char nbrhabitants[20];
    char nbrconseiller[20];
    
} municipaliter ;
typedef struct
{
     char nom [30];
     char prenom [ 30];
     int CIN ;
     int id;
     char login [30] ;
     char mp [30] ;
     int role ;
     int sexe ;
     Date d;
     int vote;
     int idbv;
}utilisateur;

typedef struct
{
char id[20];
municipaliter m;
Date d;
} election;

void ajouterelection(  election E );
void modifierelection(election nouvL);
void supprimerelection(char *id);
void chercherelection( GtkWidget *liste,char ch[30]);
void afficherelection(GtkWidget *liste);
float TPE(char * filename);
void TPHF(char * filename, float * fe,float * h);
int nbe(char * filename,int id);
int verifier(char id[]);

#endif // FUNCTION_H_INCLUDED

