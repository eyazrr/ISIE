
#include "function.h"
#include <string.h>
#include <stdio.h>

int ajouterobservateur ( char * filename , observateur o )
{
    FILE * f=fopen(filename, "a"); //add ;ajouter
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.id,o.CIN,o.login,o.mp,o.nationnalite,o.appartenance,o.sexe,o.d.jour,o.d.mois,o.d.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifierobservateur( char * filename, int id, observateur nouvl )
{
    int tr=0;
    observateur o;
    FILE * f=fopen(filename, "r"); //read
    FILE * f2=fopen("nouv.txt", "w");//write
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,&o.id,&o.CIN,o.login,o.mp,o.nationnalite,o.appartenance,&o.sexe,&o.d.jour,&o.d.mois,&o.d.annee)!=EOF) //end of file
        {
            if(o.id== id)
            {
                fprintf(f2,"%s %s %d %d %s %s %s %s %d %d %d %d \n",nouvl.nom,nouvl.prenom,nouvl.id,nouvl.CIN,nouvl.login,nouvl.mp,nouvl.nationnalite,nouvl.appartenance,nouvl.sexe,nouvl.d.jour,nouvl.d.mois,nouvl.d.annee);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %d %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.id,o.CIN,o.login,o.mp,o.nationnalite,o.appartenance,o.sexe,o.d.jour,o.d.mois,o.d.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimerobservateur (char * filename , int id )
{
    int tr=0;
    observateur o;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,&o.id,&o.CIN,o.login,o.mp,o.nationnalite,o.appartenance,&o.sexe,&o.d.jour,&o.d.mois,&o.d.annee)!=EOF)
        {
            if(o.id== id)
                tr=1;
            else
                fprintf(f2,"%s %s %d %d %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,o.id,o.CIN,o.login,o.mp,o.nationnalite,o.appartenance,o.sexe,o.d.jour,o.d.mois,o.d.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
observateur chercherobservateur ( char* filename, int id)
{
    observateur o;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %d %s %s %s %s %d %d %d %d \n",o.nom,o.prenom,&o.id,&o.CIN,o.login,o.mp,o.nationnalite,o.appartenance,&o.sexe,&o.d.jour,&o.d.mois,&o.d.annee)!=EOF)
        {
            if(o.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        o.id=-1;
    return o;

}
