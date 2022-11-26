#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

typedef struct
{
int jj;
int mm;
int aaaa;
}Date;

typedef struct
{
int id;
char nom[30];
char prenom[30];
char profession[30];
int age;
}condidat;

typedef struct
{
int idliste;
char orientation[30];
Date dc;
condidat c[3];
}listeelectorale;


int ajouter(listeelectorale l , char filename []);
int modifier(int id, listeelectorale nouv, char * filename);
int supprimer(int id, char * filename);
listeelectorale chercher(int id , char * filename);


#endif // LISTE_H_INCLUDED
