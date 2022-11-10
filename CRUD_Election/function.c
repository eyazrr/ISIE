#include<stdlib.h>
#include"function.h"
#include<stdio.h>
#include<string.h>
int ajouterelection( char * filename, election e )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s %d %d %d\n",e.id,e.m.idm,e.m.nbrhabitants,e.m.nbrconseiller,e.m.nom,e.d.jour,e.d.mois,e.d.annee);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modifierelection(int id, election nouv, char * filename)
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
         while(fscanf (f,"%d %d %d %d %s %d %d %d\n",&e.id,&e.m.idm,&e.m.nbrhabitants,&e.m.nbrconseiller,e.m.nom,&e.d.jour,&e.d.mois,&e.d.annee)!=EOF)
        {
              if(e.id==id)
            {
                 fprintf(f2,"%d %d %d %d %s %d %d %d\n",nouv.id,nouv.m.idm,nouv.m.nbrhabitants,nouv.m.nbrconseiller,nouv.m.nom,nouv.d.jour,nouv.d.mois,nouv.d.annee);
                tr=1;
            }
            else

                fprintf(f2,"%d %d %d %d %s %d %d %d\n",e.id,e.m.idm,e.m.nbrhabitants,e.m.nbrconseiller,e.m.nom,e.d.jour,e.d.mois,e.d.annee);


        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

int supprimerelection(int id, char * filename)
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
         while(fscanf (f,"%d %d %d %d %s %d %d %d\n",&e.id,&e.m.idm,&e.m.nbrhabitants,&e.m.nbrconseiller,e.m.nom,&e.d.jour,&e.d.mois,&e.d.annee)!=EOF)
        {
              if(e.id==id)
            {
                tr=1;
            }
            else

                fprintf(f2,"%d %d %d %d %s %d %d %d\n",e.id,e.m.idm,e.m.nbrhabitants,e.m.nbrconseiller,e.m.nom,e.d.jour,e.d.mois,e.d.annee);


        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

election chercherelection( char * filename,int id)
{
     election e;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf (f,"%d %d %d %d %s %d %d %d\n",&e.id,&e.m.idm,&e.m.nbrhabitants,&e.m.nbrconseiller,e.m.nom,&e.d.jour,&e.d.mois,&e.d.annee)!=EOF)
        {
            if(e.id==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        e.id=-1;
    return e;

}









