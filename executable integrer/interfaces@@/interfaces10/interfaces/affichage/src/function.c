#include<stdlib.h>
#include"function.h"
#include<stdio.h>
#include<string.h>
enum{

	ID,
	MUNI,
	NBRHAB,
	NBRCON,		        
        JOUR,
	MOIS,
	ANNEE,
	COLUMNS

};

void ajouterelection(  election E )
{
    
    FILE * f=fopen("election.txt", "a+");

    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %d %s %d\n",E.id,E.m.municipalite,E.m.nbrhabitants,E.m.nbrconseiller,E.d.jour,E.d.mois,E.d.annee);
        
    }
    fclose(f); 
}


void afficherelection(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",MUNI,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nbrhabitants",renderer,"text",NBRHAB,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nbrconseiller",renderer,"text",NBRCON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT);
f=fopen("election.txt.txt","r");

char id1[20];
char municipalite1[20];
char nbrhabitants1[20];
char nbrconseiller1[20];
int jour1;
char mois1[20];
int annee1;
{f=fopen("election.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %s %d		 \n",id1,municipalite1,nbrhabitants1,nbrconseiller1,&jour1,mois1,&annee1)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID,id1,MUNI,municipalite1,NBRHAB,nbrhabitants1,NBRCON,nbrconseiller1,JOUR,jour1,MOIS,mois1,ANNEE,annee1,-1);
}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);
}
}
}
void modifierelection(election nouvL)
{
   
    election e;
    FILE * f=fopen("election.txt", "r");
    FILE * f2=fopen("nouv.txt", "w+");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf (f,"%s %s %s %s %d %s %d\n",e.id,e.m.municipalite,e.m.nbrhabitants,e.m.nbrconseiller,&e.d.jour,e.d.mois,&e.d.annee)!=EOF)
        {
           if(strcmp(nouvL.id,e.id)==0)
            {
                fprintf(f2,"%s %s %s %s %d %s %d\n",nouvL.id,nouvL.m.municipalite,nouvL.m.nbrhabitants,nouvL.m.nbrconseiller,nouvL.d.jour,nouvL.d.mois,nouvL.d.annee);
              
            }
            else

                fprintf(f2,"%s %s %s %s %d %s %d\n",e.id,e.m.municipalite,e.m.nbrhabitants,e.m.nbrconseiller,e.d.jour,e.d.mois,e.d.annee);


        }
    }
    fclose(f);
    fclose(f2);
    remove("election.txt");
    rename("nouv.txt","election.txt");


}

void supprimerelection(char *id)
{
    
   election e;
    FILE * f=fopen("election.txt", "r");
    FILE * f2=fopen("nouv.txt", "w+");
    if(f!=NULL && f2!=NULL)
   {
        while(fscanf (f,"%s %s %s %s %d %s %d\n",e.id,e.m.municipalite,e.m.nbrhabitants,e.m.nbrconseiller,&e.d.jour,e.d.mois,&e.d.annee)!=EOF)
        {
            if(strcmp(id,e.id)!=0)
            {
                 fprintf(f2,"%s %s %s %s %d %s %d\n",e.id,e.m.municipalite,e.m.nbrhabitants,e.m.nbrconseiller,e.d.jour,e.d.mois,e.d.annee);
            }

        }
    }
    fclose(f);
    fclose(f2);
    remove("election.txt");
    rename("nouv.txt", "election.txt");
}



 void chercherelection( GtkWidget *liste,char ch[30])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",MUNI,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nbrhabitants",renderer,"text",NBRHAB,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nbrconseiller",renderer,"text",NBRCON,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT);
f=fopen("election.txt.txt","r");

char id1[20];
char municipalite1[20];
char nbrhabitants1[20];
char nbrconseiller1[20];
int jour1;
char mois1[20];
int annee1;
{f=fopen("election.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %s %d\n",id1,municipalite1,nbrhabitants1,nbrconseiller1,&jour1,mois1,&annee1)!=EOF)
{if((strcmp(ch,id1)==0) )
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID,id1,MUNI,municipalite1,NBRHAB,nbrhabitants1,NBRCON,nbrconseiller1,JOUR,jour1,MOIS,mois1,ANNEE,annee1,-1);
}}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);
   
    
}
}
//function pour verifier
int verifier(char id[])
{
    election e;
    int tr=0;
    FILE * f=fopen("election.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf (f,"%s %s %s %s %d %s %d\n",e.id,e.m.municipalite,e.m.nbrhabitants,e.m.nbrconseiller,&e.d.jour,e.d.mois,&e.d.annee)!=EOF)
        {
            if(strcmp(id,e.id)==0)
                tr=1;
        }
    }
    fclose(f);
    return tr;
}
/*taux de participation de electeur*/
float TPE(char * filename)
{
    utilisateur L;
    int nbEvote=0,nbEtotale=0;
    float TPE;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
    while(fscanf(f,"%s %s %d %d %s %s %d %d %d %d %d %d %d\n",L.nom,L.prenom,&L.CIN,&L. id,L.login,L.mp,&L.role,&L.sexe,&L.d.jour,&L.d.mois,&L.d.annee,&L.vote,&L.idbv)!=EOF)
        {


            nbEtotale=nbEtotale+1;

            if(L.vote != -1)
            {
                nbEvote=nbEvote+1;
            }

        }


        TPE=(float)nbEvote/nbEtotale;


        fclose(f);

        return TPE;}
    }


    /* taux de participation des hommes et des femmes */
    void TPHF(char * filename, float * fe,float * h)
    {
        utilisateur L;
        int nbEvote=0,nbEvoteH=0,nbEvoteF=0;
        FILE * f=fopen(filename, "r");
        if(f!=NULL)
        {
            while(fscanf(f,"%s %s %d %d %s %s %d %d %d %d %d %d %d\n",L.nom,L.prenom,&L.CIN,&L. id,L.login,L.mp,&L.role,&L.sexe,&L.d.jour,&L.d.mois,&L.d.annee,&L.vote,&L.idbv)!=EOF)
            {
                if(L.vote != -1)
                {
                    nbEvote=nbEvote+1;
                    switch(L.sexe)
                    {
                    case 0:
                    {
                        nbEvoteF=nbEvoteF+1;
                        break;
                    }
                    case 1:
                    {
                        nbEvoteH=nbEvoteH+1;
                        break;
                    }
                    }
                }
                *fe=(float)nbEvoteF/nbEvote;
                *h=(float)nbEvoteH/nbEvote;
            }
            fclose(f);
        }
    }

/*le nombre d'electeur par bureau de vote*/
int nbe(char * filename,int id)
{
    int nbr_electeur=0;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %s %s %d %d %d %d %d %d %d\n",L.nom,L.prenom,&L.CIN,&L. id,L.login,L.mp,&L.role,&L.sexe,&L.d.jour,&L.d.mois,&L.d.annee,&L.vote,&L.idbv)!=EOF)
        {
            if(L.idbv==id)
                nbr_electeur++;
        }
    }
    fclose(f);
    return nbr_electeur;
}


