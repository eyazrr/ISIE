
#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED



typedef struct
{  int jour ;
   int mois;
   int annee ;

} date;

typedef struct
{
     char nom [30];
     char prenom [ 30];
     int id;
     int CIN ;
     char login [30] ;
     char mp [30] ;
     char nationnalite [50];
     char appartenance [30];
     int sexe ;
     date d;
}observateur;

int ajouterobservateur( char * filename , observateur o);
int modifierobservateur( char * filename, int id, observateur nouvl );
int supprimerobservateur ( char * filename , int id );
observateur chercherobservateur ( char* filename , int id);










#endif // FUNCTION_H_INCLUDED
