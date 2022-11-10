#include <stdio.h>
#include <string.h>
#include "function.h"

int main()
{
     observateur o1={"eya","zribi",12,10,"crud","eya","francais","hote",2,12,12,2000};
     observateur o2={"zribi","eya",11,12,"3b8","eya","tunisien","presse",1,06,06,2000};
     observateur o3;

     int x;


    x=ajouterobservateur("observateur.txt",o1);

    if(x==1)
        printf("\najout d'observeteur avec succees!!!!!!!!!");
    else printf("\nechec ajout");

   /* x=modifierobservateur("observeteur.txt",10,o2);

    if(x==1)
        printf("\nModification avec succ�s");
    else printf("\nechec Modification");*/
    /*x=supprimerobservateur("observateur.txt",12);
    if(x==1)
        printf("\nSuppression avec succ�s");
    else printf("\nechec Suppression");*/
   /*o3=chercherobservateur("observateur.txt",10);
    if(o3.id==-1)
    {
        printf("introuvable");
        }else if (o3.CIN!=-1)
     {
         printf("existe\n");

    }*/
    return 0;
}
