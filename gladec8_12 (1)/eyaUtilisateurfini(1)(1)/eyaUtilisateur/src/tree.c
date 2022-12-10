#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "tree.h"
FILE *f;

GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/


void Afficherutilisateur(GtkWidget* treeview1,char*l)
{

utilisateur t;

adstore = gtk_tree_view_get_model(treeview1);
if (adstore ==NULL)
	{


       

	/* Creation de la 1ere colonne */
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ROLE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM ET PRENOM",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("username",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("password",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUM_BUREAU",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("VOTE",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

}

 /* Creation du modele */
        adstore = gtk_list_store_new(9,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
	if (f==NULL)
	{
		return;
	}
        else
	{
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,t.cin,
                            1,t.sexe,
                            2,t.role,
                            3,t.date,
                            4,t.nom,
			    5,t.user,
			    6,t.password,
			    7,t.numerobureau,
			    8,t.vote,
                          -1);}
	
        fclose(f);


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
	g_object_unref(adstore);
        }


}



//*********************************************************************


//********************************************************************


//*********************************************************************

int Chercherutilisateur(GtkWidget* treeview1,char*l,char*cin)
{

utilisateur t ;
int nb=0;

	adstore = gtk_tree_view_get_model(treeview1);
if (adstore ==NULL)
	{

        

	/* Creation de la 1ere colonne */

	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ROLE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("date",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM ET PRENOM",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("username",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("password",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NUM_BUREAU",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("VOTE",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        }

	/* Creation du modele */
        adstore = gtk_list_store_new(9,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
	if (f==NULL)
	{
		return;
	}
        else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote)!=EOF)
       	        {
			if( strcmp(cin,t.cin)==0){ nb++;
			GtkTreeIter pIter;
        		 /* Creation de la nouvelle ligne */
        		 gtk_list_store_append(adstore, &pIter);
        		 /* Mise a jour des donnees */
			 gtk_list_store_set(adstore, &pIter,
				            0,t.cin,
				            1,t.sexe,
				            2,t.role,
				            3,t.date,
				            4,t.nom,
					    5,t.user,
					    6,t.password,
		 			    7,t.numerobureau,
					    8,t.vote,
				            -1);}
		}
        fclose(f);
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
	g_object_unref(adstore);
      }
return nb;

}
