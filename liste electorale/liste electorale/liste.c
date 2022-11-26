#include "liste.h"
#include<stdio.h>
int ajouter(listeelectorale l , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d %d\n %d %s %s %s %d\n %d %s %s %s %d\n %d %s %s %s %d\n",l.idliste,l.orientation,l.dc.jj,l.dc.mm,l.dc.aaaa,l.c[0].id,l.c[0].nom,l.c[0].prenom,l.c[0].profession,l.c[0].age,l.c[1].id,l.c[1].nom,l.c[1].prenom,l.c[1].profession,l.c[1].age,l.c[2].id,l.c[2].nom,l.c[2].prenom,l.c[2].profession,l.c[2].age);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int id,listeelectorale nouv, char * filename)
{
listeelectorale l;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("test.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %d %d %d\n %d %s %s %s %d\n %d %s %s %s %d\n %d %s %s %s %d\n",&l.idliste,l.orientation,&l.dc.jj,&l.dc.mm,&l.dc.aaaa,&l.c[0].id,l.c[0].nom,l.c[0].prenom,l.c[0].profession,&l.c[0].age,&l.c[1].id,l.c[1].nom,l.c[1].prenom,l.c[1].profession,&l.c[1].age,&l.c[2].id,l.c[2].nom,l.c[2].prenom,l.c[2].profession,&l.c[2].age)!=EOF)
{
if(l.idliste!=id)
        fprintf(f2,"%d %s %d %d %d\n %d %s %s %s %d\n %d %s %s %s %d\n %d %s %s %s %d\n",l.idliste,l.orientation,l.dc.jj,l.dc.mm,l.dc.aaaa,l.c[0].id,l.c[0].nom,l.c[0].prenom,l.c[0].profession,l.c[0].age,l.c[1].id,l.c[1].nom,l.c[1].prenom,l.c[1].profession,l.c[1].age,l.c[2].id,l.c[2].nom,l.c[2].prenom,l.c[2].profession,l.c[2].age);
else

        fprintf(f2,"%d %s %d %d %d\n %d %s %s %s %d\n %d %s %s %s %d\n %d %s %s %s %d\n",nouv.idliste,nouv.orientation,nouv.dc.jj,nouv.dc.mm,nouv.dc.aaaa,nouv.c[0].id,nouv.c[0].nom,nouv.c[0].prenom,nouv.c[0].profession,nouv.c[0].age,nouv.c[1].id,nouv.c[1].nom,nouv.c[1].prenom,nouv.c[1].profession,nouv.c[1].age,nouv.c[2].id,nouv.c[2].nom,nouv.c[2].prenom,nouv.c[2].profession,nouv.c[2].age);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("test.txt", filename);
        return 1;
    }
}

int supprimer(int id, char * filename)
{
listeelectorale l;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("test.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %d %d %d\n %d %s %s %s %d\n %d %s %s %s %d\n %d %s %s %s %d\n",&l.idliste,l.orientation,&l.dc.jj,&l.dc.mm,&l.dc.aaaa,&l.c[0].id,l.c[0].nom,l.c[0].prenom,l.c[0].profession,&l.c[0].age,&l.c[1].id,l.c[1].nom,l.c[1].prenom,l.c[1].profession,&l.c[1].age,&l.c[2].id,l.c[2].nom,l.c[2].prenom,l.c[2].profession,&l.c[2].age)!=EOF)
{
if(l.idliste!=id)
        fprintf(f2,"%d %s %d %d %d\n %d %s %s %s %d\n %d %s %s %s %d\n %d %s %s %s %d\n",l.idliste,l.orientation,l.dc.jj,l.dc.mm,l.dc.aaaa,l.c[0].id,l.c[0].nom,l.c[0].prenom,l.c[0].profession,l.c[0].age,l.c[1].id,l.c[1].nom,l.c[1].prenom,l.c[1].profession,l.c[1].age,l.c[2].id,l.c[2].nom,l.c[2].prenom,l.c[2].profession,l.c[2].age);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("test.txt", filename);
        return 1;
    }
}



listeelectorale chercher(int id, char * filename)
{
listeelectorale l; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
        while(tr==0&& fscanf(f,"%d %s %d %d %d\n %d %s %s %s %d\n %d %s %s %s %d\n %d %s %s %s %d\n",&l.idliste,l.orientation,&l.dc.jj,&l.dc.mm,&l.dc.aaaa,&l.c[0].id,l.c[0].nom,l.c[0].prenom,l.c[0].profession,&l.c[0].age,&l.c[1].id,l.c[1].nom,l.c[1].prenom,l.c[1].profession,&l.c[1].age,&l.c[2].id,l.c[2].nom,l.c[2].prenom,l.c[2].profession,&l.c[2].age)!=EOF)
{if(id==l.idliste)
tr=1;
}
}
if(tr==0)
l.idliste=-1;
return l;

}


