#include "function.h"
#include <string.h>
#include <stdio.h>

int ajouterutilisateur ( char * filename , utilisateur u)
{
    FILE * f=fopen(filename, "a"); //add ;ajouter
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %s %s %d %d %d %d %d \n",u.nom,u.prenom,u.CIN,u.id,u.login,u.mp,u.role,u.sexe,u.d.jour,u.d.mois,u.d.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifierutilisateur( char * filename, int id, utilisateur nouvl )
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r"); //read
    FILE * f2=fopen("nouv.txt", "w");//write
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %s %s %d %d %d %d %d \n",u.nom,u.prenom,&u.CIN,&u.id,u.login,u.mp,&u.role,&u.sexe,&u.d.jour,&u.d.mois,&u.d.annee)!=EOF) //end of file
        {
            if(u.id== id)
            {
                fprintf(f2,"%s %s %d %d %s %s %d %d %d %d %d \n",nouvl.nom,nouvl.prenom,nouvl.CIN,nouvl.id,nouvl.login,nouvl.mp,nouvl.role,nouvl.sexe,nouvl.d.jour,nouvl.d.mois,nouvl.d.annee);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %d %s %s %d %d %d %d %d \n",u.nom,u.prenom,u.CIN,u.id,u.login,u.mp,u.role,u.sexe,u.d.jour,u.d.mois,u.d.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimerutilisateur (char * filename , int id )
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %s %s %d %d %d %d %d \n",u.nom,u.prenom,&u.CIN,&u.id,u.login,u.mp,&u.role,&u.sexe,&u.d.jour,&u.d.mois,&u.d.annee)!=EOF)
        {
            if(u.id== id)
                tr=1;
            else
                fprintf(f2,"%s %s %d %d %s %s %d %d %d %d %d \n",u.nom,u.prenom,u.CIN,u.id,u.login,u.mp,u.role,u.sexe,u.d.jour,u.d.mois,u.d.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
utilisateur chercherutilisateur ( char* filename, int id)
{
    utilisateur u;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %d %s %s %d %d %d %d %d \n",u.nom,u.prenom,&u.CIN,&u.id,u.login,u.mp,&u.role,&u.sexe,&u.d.jour,&u.d.mois,&u.d.annee)!=EOF)
        {
            if(u.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.id=-1;
    return u;

}
