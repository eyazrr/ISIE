#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


typedef struct
{  int jour ;
   int mois;
   int annee ;

} date;

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
     date d;
}utilisateur;

int ajouterutilisateur ( char * filename , utilisateur u);
int modifierutilisateur( char * filename, int id, utilisateur nouvl );
int supprimerutilisateur ( char * filename , int id );
utilisateur chercherutilisateur ( char* filename , int id);

#endif // HEADER_H_INCLUDED
