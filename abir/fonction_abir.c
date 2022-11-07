#include<stdlib.h>
#include"fonction.h"
#include<stdio.h>

int ajouterelection( char * filename ,election e)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %d %d %d\n",e.id,e.municipalite,e.nbrhabitants,e.nbrconseiller,e.date.jour,e.date.mois,e.date.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifierelection(int id, election nouv, char * filename)
{
election e;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
{return 0;}
else
    {
while(fscanf(f,"%d %d %d %d %d %d %d",&e.id,&e.municipalite,&e.nbrhabitants,&e.nbrconseiller,&e.date.jour,&e.date.mois,&e.date.annee)!=EOF)
{
if(e.id!=id)
        fprintf(f2,"%d %d %d %d %d %d %d\n",e.id,e.municipalite,e.nbrhabitants,e.nbrconseiller,e.date.jour,e.date.mois,e.date.annee);
else

  fprintf(f2,"%d %d %d %d %d %d %d\n",nouv.id,nouv.municipalite,nouv.nbrhabitants,nouv.nbrconseiller,nouv.date.jour,nouv.date.mois,nouv.date.annee);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }

}

int supprimerelection(int id, char * filename)
{
election e;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %d %d %d %d %d %d",&e.id,&e.municipalite,&e.nbrhabitants,&e.nbrconseiller,&e.date.jour,&e.date.mois,&e.date.annee)!=EOF)
{
if(e.id!=id)
        fprintf(f2,"%d %d %d %d %d %d %d\n",e.id,e.municipalite,e.nbrhabitants,e.nbrconseiller,e.date.jour,e.date.mois,e.date.annee);
else

fprintf(f2,"%d %d %d %d %d %d %d \n",e.id,e.municipalite,e.nbrhabitants,e.nbrconseiller,e.date.jour,e.date.mois,e.date.annee);
}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

election chercherelection( char * filename,int id)
{
election e; int tr=0;
    FILE * f=fopen(filename , "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %d %d %d %d %d %d",&e.id,&e.municipalite,&e.nbrhabitants,&e.nbrconseiller,&e.date.jour,&e.date.mois,&e.date.annee)!=EOF && tr==0)
{if(id==e.id)
tr=1;
}
}
if(tr==0)
e.id=-1;
return e;

}

