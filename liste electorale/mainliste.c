#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main()
{
listeelectorale l1={1,"droite",17,01,2000,10,"nom0","prenom0","profession0",21,11,"nom1","prenom1","profession1",21,12,"nom2","prenom2","profession2",21};
listeelectorale l2={2,"gauche",25,06,1999,20,"nom10","prenom10","profession10",51,21,"nom11","prenom11","profession11",21,22,"nom12","prenom12","profession12",21};
listeelectorale l3={3,"droite",29,01,1996,30,"nom20","prenom20","profession20",61,31,"nom21","prenom21","profession21",21,32,"nom22","prenom22","profession22",21};
/*
 int x=ajouter(l3,"liste.txt");
   if(x==1)
        printf("\najout de point avec succés");
  else printf("\nechec ajout");


int x=modifier(2,l3,"liste.txt");

    if(x==1)
        printf("\nModification de point avec succés");
    else printf("\nechec Modification");



int  x=supprimer(3,"liste.txt");
    if(x==1)
        printf("\nSuppression de point avec succés");
    else printf("\nechec Suppression");
*/


 listeelectorale l = chercher(1,"liste.txt");
if(l.idliste==-1)
printf("inexistant");
else
    printf("%d %s %d %d %d\n %d %s %s %s %d\n %d %s %s %s %d\n %d %s %s %s %d\n",l.idliste,l.orientation,l.dc.jj,l.dc.mm,l.dc.aaaa,l.c[0].id,l.c[0].nom,l.c[0].prenom,l.c[0].profession,&l.c[0].age,l.c[1].id,l.c[1].nom,l.c[1].prenom,l.c[1].profession,l.c[1].age,l.c[2].id,l.c[2].nom,l.c[2].prenom,l.c[2].profession,l.c[2].age);
}
