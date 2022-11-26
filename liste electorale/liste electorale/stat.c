#include "stat.h"
#include<stdio.h>
#include<string.h>

int nbobserver( char * filename)
{
int i=0;
observateur o;
    FILE * f=fopen(filename, "r");

    if(f==NULL)
       return 0;
else
    {
while(fscanf(f,"%d %d %s %s %s %s %d %d %d %d %d %d %d\n",&o.id,&o.CIN,o.nom,o.prenom,o.login,o.mp,&o.sexe,&o.role,&o.vote,&o.idbv,&o.d.jour,&o.d.mois,&o.d.annee)!=EOF)
{
i++;

}
        fclose(f);
        return i ;
    }

}




void trier(char * Filename){
int i=0,k=0,j=0,l=0;
observateur tab[100];
observateur o,aux;
    FILE * f=fopen( Filename, "r");
    FILE * f2 =fopen("essai.txt", "w");

	if(f==NULL)
		printf("impossible d'ouvrir le fichier");
	else{
		while(fscanf(f,"%d %d %s %s %s %s %d %d %d %d %d %d %d\n",&o.id,&o.CIN,o.nom,o.prenom,o.login,o.mp,&o.sexe,&o.role,&o.vote,&o.idbv,&o.d.jour,&o.d.mois,&o.d.annee)!=EOF){
			tab[i]=o;
			i++;	}

		while (l<i){
			for(k=0;k<i-1;k++)
						{
				if (strcmp(tab[k].nom,tab[k+1].nom)>0){
					aux=tab[k+1];
					tab[k+1]=tab[k];
					tab[k]=aux;	}
						}
			l++;	}
		while (j<i){
			fprintf(f2,"%d %d %s %s %s %s %d %d %d %d %d %d %d\n",tab[j].id,tab[j].CIN,tab[j].nom,tab[j].prenom,tab[j].login,tab[j].mp,tab[j].sexe,tab[j].role,tab[j].vote,tab[j].idbv,tab[j].d.jour,tab[j].d.mois,tab[j].d.annee);
			j++; 	}


		fclose(f);
        fclose(f2);
remove(Filename);
rename("essai.txt", Filename);
}
}






