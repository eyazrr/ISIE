#include <stdio.h>
#include <stdlib.h>
#include"function.h"
#include<string.h>
int main()
{
election nouv;

election e1={12,1,1500,2000,"taborba",12,8,2000};
election e2={10,2,1600,5000,"babsawika",27,12,1996},e3;
election e4={20,5,1800,9000,"bardo",12,5,1996};
int x,y;



x=ajouterelection("fileelection.txt",e2);
if(x==1)
        printf("\najout election avec succees!!!!!!!!!");
    else printf("\nechec ajout");

y=ajouterelection("fileelection.txt",e1);
if(y==1)
        printf("\najout election avec succees!!!!!!!!!");
    else printf("\nechec ajout");

 /*


 x=modifierelection(10, e4,"fileelection.txt");
    if(x==1)
        printf("\nModification de election avec succes");
    else printf("\nechec Modification");

 x=supprimerelection(20,"fileelection.txt");
    if(x==1)
        printf("\nSuppression de election avec succes");
    else printf("\nechec Suppression");
        */
        e3=chercherelection("fileelection.txt",12);
        if(e3.id==-1)
    {
        printf("introuvable");
    }
    else if (e3.id!=-1)
     {
         printf("existe!!!\n");
    }


    return 0;

}

