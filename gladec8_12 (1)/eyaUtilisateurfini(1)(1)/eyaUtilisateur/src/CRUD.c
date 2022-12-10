#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>

//Ajouter un utilisateur 

void ajouter_utilisateur( utilisateur t){
FILE*f=NULL; //flot de donnée
f=fopen("utilisateur.txt","a+");// creation du fichier utilisateur .txt et ouverture en  mode lecture et ecriture a la fin
fprintf(f,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote); //f variable de type file 
fclose(f);
 //retour NULL si operation fini 
}
//********************************************************




//verifier l'existance 

int exist_utilisateur(char*cin){
FILE*f=NULL;
utilisateur t;
f=fopen("utilisateur.txt","r");// ouverture du fichierutilisateur en  mode lecture 
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote)!=EOF){
if(strcmp(t.cin,cin)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//*****************************************************************




//supprimer tr
void supprimer_utilisateur(char*cin){
FILE*f=NULL;
FILE*f1=NULL;
utilisateur t ;
f=fopen("utilisateur.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote)!=EOF){
if(strcmp(cin,t.cin)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote);
}
fclose(f);
fclose(f1);
remove("utilisateur.txt");
rename("ancien.txt","utilisateur.txt");
}

//******************************************************************


int Somme (char role[]) 
{
 FILE *f;
  utilisateur t; 
  int nbr=0; 
  f=fopen("utilisateur.txt","r"); 
if((f!=NULL))
 {
  while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote)!=EOF) 
	{
	 if(strcmp(t.role,role)==0)
	  { 
	  	nbr++; 
	  } 
	} 
} 
fclose(f); 
return nbr; 
}

int Sommes (char sexe[]) 
{
 FILE *f;
  utilisateur t; 
  int nbrs=0; 
  f=fopen("utilisateur.txt","r"); 
if((f!=NULL))
 {
  while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote)!=EOF) 
	{
	 if(strcmp(t.sexe,sexe)==0)
	  { 
	  	nbrs++; 
	  } 
	} 
} 
fclose(f); 
return nbrs; 
}











