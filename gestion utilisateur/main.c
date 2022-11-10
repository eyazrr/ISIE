#include <stdio.h>
#include <string.h>
#include "function.h"

int main()
{
     utilisateur L1={"eya","zribi",12,10,"crud","eyaa",1,2,12,12,2000};
     utilisateur L2={"zribi","eya",11,12,"3b8","eyaaaa",2,1,06,06,2000};
     utilisateur L3;

     int x;


    x=ajouterutilisateur("utilisateur.txt",L1);

    if(x==1)
        printf("\najout d'électeur avec succees!!!!!!!!!");
    else printf("\nechec ajout");

   /* x=modifierutilisateur("utilisateur.txt",10,L2);

    if(x==1)
        printf("\nModification avec succés");
    else printf("\nechec Modification");*/
    /*x=supprimerutilisateur("utilisateur.txt",12);
    if(x==1)
        printf("\nSuppression avec succés");
    else printf("\nechec Suppression");*/
   L3=chercherutilisateur("utilisateur.txt",10);
    if(L3.id==-1)
    {
        printf("introuvable");
        }else if (L3.CIN!=-1)
     {
         printf("existe\n");

    }
    return 0;
}
