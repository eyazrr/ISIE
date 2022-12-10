#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>

//Ajouter un observateur 

void ajouter_observateur( observateur o){
FILE*f=NULL; //flot de donnée
f=fopen("observateur.txt","a+");// creation du fichier observateur .txt et ouverture en  mode lecture et ecriture a la fin
fprintf(f,"%s %s %s %s %s %s %s %s\n",o.cin,o.sexe,o.nationalite,o.date,o.nom,o.user,o.password,o.appartenance); //f variable de type file 
fclose(f);
 //retour NULL si operation fini 
}
//********************************************************




//verifier l'existance 

int exist_observateur(char*cin){
FILE*f=NULL;
observateur o;
f=fopen("observateur.txt","r");// ouverture du fichier obsr en  mode lecture 
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",o.cin,o.sexe,o.nationalite,o.date,o.nom,o.user,o.password,o.appartenance)!=EOF){
if(strcmp(o.cin,cin)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//*****************************************************************




//supprimer tr
void supprimer_observateur(char*cin){
FILE*f=NULL;
FILE*f1=NULL;
observateur o ;
f=fopen("observateur.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture 
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",o.cin,o.sexe,o.nationalite,o.date,o.nom,o.user,o.password,o.appartenance)!=EOF){
if(strcmp(cin,o.cin)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s\n",o.cin,o.sexe,o.nationalite,o.date,o.nom,o.user,o.password,o.appartenance);
}
fclose(f);
fclose(f1);
remove("observateur.txt");
rename("ancien.txt","observateur.txt");
}

//******************************************************************









