#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED
typedef struct {
int jour;
int mois;
int annee;
}date;

typedef struct {
int id ;
int CIN ;
char nom[20];
char prenom[20];
char login[20];
char mp[20];
int sexe;
int role;
int vote;
int idbv;
date d;

}observateur;

void trier(char * filename);
int nbobserver(char * filename);
#endif // STAT_H_INCLUDED
