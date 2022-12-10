#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"CRUD.h"
GtkTreeSelection *selection1;

void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
gtk_widget_hide (acceuilw);
gestionw = create_gestionw ();
p=lookup_widget(gestionw,"treeview2w");
Afficherutilisateur(p,"utilisateur.txt");
gtk_widget_show (gestionw);
i=0;
j=0;
}


void
on_Ajouterutilisateur_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
utilisateur t;
GtkWidget *entrylog;
GtkWidget *entrypass;
GtkWidget *log;
GtkWidget *pass;

GtkWidget *voteb;
GtkWidget *numb;
GtkWidget *saisirvote;
GtkWidget *saisirnum;


GtkWidget *entrysexew;
GtkWidget *entryIdw;
GtkWidget *entrytypew;
//GtkWidget *entryDatew;
GtkWidget *entryPrixw;
GtkWidget *labelIdw;
GtkWidget *labelsexew;
GtkWidget *labelTypew;
GtkWidget *labelDatew;
GtkWidget *labelPrixw;
GtkWidget *existew;
GtkWidget* successw;
GtkWidget *calw;
int b=1;
int jj1,mm1,aa1;

FILE*f=NULL;

voteb=lookup_widget(gestionw,"voteb");
numb=lookup_widget(gestionw,"numb");

saisirvote=lookup_widget(gestionw,"saisirvote");
saisirnum=lookup_widget(gestionw,"saisirnum");

entryIdw=lookup_widget(gestionw,"entry5w");
entrysexew=lookup_widget(gestionw,"combobox1w");
entrytypew=lookup_widget(gestionw,"combobox2w");

entrylog=lookup_widget(gestionw,"entrylog");
entrypass=lookup_widget(gestionw,"entrypass");
log=lookup_widget(gestionw,"log");
pass=lookup_widget(gestionw,"pass");


entryPrixw=lookup_widget(gestionw,"entry3w");

labelIdw=lookup_widget(gestionw,"label13w");
labelsexew=lookup_widget(gestionw,"label7w");
labelTypew=lookup_widget(gestionw,"label8w");

labelPrixw=lookup_widget(gestionw,"label10w");
existew=lookup_widget(gestionw,"label34w");


successw=lookup_widget(gestionw,"label35w");
calw=lookup_widget(gestionw,"yawmia");
        strcpy(t.cin,gtk_entry_get_text(GTK_ENTRY(entryIdw) ) );
        strcpy(t.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexew)));
        strcpy(t.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrytypew)));
        strcpy(t.nom,gtk_entry_get_text(GTK_ENTRY(entryPrixw) ) );
        strcpy(t.user,gtk_entry_get_text(GTK_ENTRY(entrylog) ) );
        strcpy(t.password,gtk_entry_get_text(GTK_ENTRY(entrypass) ) );
        strcpy(t.numerobureau,gtk_entry_get_text(GTK_ENTRY(numb) ) );
        strcpy(t.vote,gtk_entry_get_text(GTK_ENTRY(voteb) ) );
 gtk_widget_hide (successw);

 gtk_calendar_get_date (GTK_CALENDAR(calw),
                       &aa1,
                       &mm1,
                       &jj1);
 gtk_widget_hide (successw);


// controle saisie
if(strcmp(t.cin,"")==0){
		  gtk_widget_show (labelIdw);
b=0;
}
else {
		  gtk_widget_hide(labelIdw);
}

if(strcmp(t.sexe,"")==0){
		  gtk_widget_show (labelsexew);
b=0;
}
else {
		  gtk_widget_hide(labelsexew);
}
if(strcmp(t.role,"")==0){
		  gtk_widget_show (labelTypew);
b=0;
}
else {
		  gtk_widget_hide(labelTypew);
}

if(strcmp(t.nom,"")==0){
		  gtk_widget_show (labelPrixw);
b=0;
}
else {
		  gtk_widget_hide(labelPrixw);
}

if(strcmp(t.user,"")==0){
		  gtk_widget_show (log);
b=0;
}
else {
		  gtk_widget_hide(log);
}

if(strcmp(t.password,"")==0){
		  gtk_widget_show (pass);
b=0;
}
else {
		  gtk_widget_hide(pass);
}



if(strcmp(t.numerobureau,"")==0){
		  gtk_widget_show (saisirnum);
b=0;
}
else {
		  gtk_widget_hide(saisirnum);
}


if(strcmp(t.vote,"")==0){
		  gtk_widget_show (saisirvote);
b=0;
}
else {
		  gtk_widget_hide(saisirvote);
}





if(b==1){

        if(exist_utilisateur(t.cin)==1)
        {

				  gtk_widget_show (existew);
                }
                else {
                     gtk_widget_hide (existew);

       f=fopen("utilisateur.txt","a+");
fprintf(f,"%s %s %s %d/%d/%d %s %s %s %s %s\n",t.cin,t.sexe,t.role,jj1,mm1+1,aa1,t.nom,t.user,t.password,t.numerobureau,t.vote);
fclose(f);
     
//ajouter_utilisateur(t);
                  gtk_widget_show (successw);


//mise a jour du treeView
        GtkWidget* p=lookup_widget(gestionw,"treeview2w");

        Afficherutilisateur(p,"utilisateur.txt");
}

}
}



void
on_Modifierutilisateur_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *combobox3w;
        GtkWidget *combobox4w;
     combobox3w=lookup_widget(button,"combobox3w");
     combobox4w=lookup_widget(button,"combobox4w");
       	 utilisateur t;

        strcpy(t.cin,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionw,"label20w"))));
        
   strcpy(t.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox3w"))));
   strcpy(t.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox4w"))));
        strcpy(t.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w"))));
        strcpy(t.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w"))));

   strcpy(t.user,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entrylogm"))));
   strcpy(t.password,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entrypassm"))));



 strcpy(t.numerobureau,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"numbrm"))));
   strcpy(t.vote,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"votem"))));

        supprimer_utilisateur(t.cin);
        ajouter_utilisateur(t);
//mise ajour du tree view 
        Afficherutilisateur(lookup_widget(gestionw,"treeview1"),"utilisateur.txt");
	gtk_widget_show(lookup_widget(gestionw,"label37w"));
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherutilisateur(p,"utilisateur.txt");
}





void
on_chercherutilisateur_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1w;
GtkWidget *entryw;
GtkWidget *labelidw;
GtkWidget *nbResultatw;
GtkWidget *messagew;
char cin[30];
char chnb[30];
int b=0,nb; //b=0  entry  cherche vide 
entryw=lookup_widget(gestionw,"entry10w");
labelidw=lookup_widget(gestionw,"label28w");
p1w=lookup_widget(gestionw,"treeview2w");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entryw)));

if(strcmp(cin,"")==0){
  gtk_widget_show (labelidw);b=0;
}else{
b=1;
gtk_widget_hide (labelidw);}

if(b==0)
    {return;
    }
    else
    {

nb=Chercherutilisateur(p1w,"utilisateur.txt",cin);
// afficher le sexebre de resultats obtenue par la recherche
 

sprintf(chnb,"%d",nb);        //conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultatw=lookup_widget(gestionw,"label27");
messagew=lookup_widget(gestionw,"label26w");
gtk_label_set_text(GTK_LABEL(nbResultatw),chnb);

gtk_widget_show (nbResultatw);
gtk_widget_show (messagew);
}
}


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuilw);
gtk_widget_destroy (gestionw);

}




void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data)
{
        gchar *cin;
        gchar *sexe;
        gchar *role;
        gchar *date;
        gchar *nom;
 gchar *user;
 gchar *password;
 gchar *numerobureau;
 gchar *vote;
  
        GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

        gtk_widget_hide(lookup_widget(gestionw,"label37w"));//cacher label modifier avec succees
                gtk_tree_model_get (model,&iter,0,&cin,1,&sexe,2,&role,3,&date,4,&nom,5,&user,6,&password,7,&numerobureau,8,&vote,-1);//recuperer les information de la ligne selectionneé   
        // //remplir les champs de entry  
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox3w")),sexe);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox4w")),role);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w")),nom);


		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entrylogm")),user);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entrypassm")),password);

		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"numbrm")),numerobureau);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"votem")),vote);


                GtkWidget* msgId=lookup_widget(gestionw,"label20w");
                GtkWidget* msg1=lookup_widget(gestionw,"label36w");
                gtk_label_set_text(GTK_LABEL(msgId),cin);
                gtk_widget_show(msgId);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestionw,"button4w"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestionw,"notebook1w")));//redirection vers la page precedente
        gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
        }

}


void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data)
{
    gchar *cin;
    gchar *sexe;
    gchar *role;
    gchar *date;
    gchar *nom;
   gchar *user;
 gchar *password;
 gchar *numerobureau;
 gchar *vote;
    GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&cin,1,&sexe,2,&role,3,&date,4,&nom,5,&user,6,&password,7,&numerobureau,8,&vote,-1);//recuperer les information de la ligne selectionneé
            supprimer_utilisateur(cin);
            Afficherutilisateur(lookup_widget(gestionw,"treeview2w"),"utilisateur.txt");        
        }
}


void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherutilisateur(p,"utilisateur.txt");
}


void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
    	gchar *cin;
        gchar *sexe;
        gchar *role;
        gchar *date;
        gchar *nom;
        gchar *user;
        gchar *password;
 gchar *numerobureau;
 gchar *vote;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       
}


void
on_validersomme_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
int nbr;
 char msg[120]="";
  char type[30];
 GtkWidget *output;
 GtkWidget *combobox;
   //GtkWidget *gestion; 
  //gestion=lookup_widget(button,"gestion");

combobox=lookup_widget(button,"comboboxchoix");
    output=lookup_widget(button,"labelnombre");
    strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
     nbr=Somme(type); sprintf(msg,"la somme vaut %d",nbr); gtk_label_set_text(output,msg);
}













void
on_nbrvt_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *b;
float nbrv=0 ,nbrd=0,nbrt=0;
 
FILE*f=NULL;
utilisateur t;
char max[30];
char msgs[120]="";
char ta[30];



f=fopen("utilisateur.txt","r");// ouverture du fichier utilisateur en  mode lecture 

while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",t.cin,t.sexe,t.role,t.date,t.nom,t.user,t.password,t.numerobureau,t.vote)!=EOF)
	{
		if(strcmp(t.vote,"0")==0)
		nbrv++;
		else if(strcmp(t.vote,"0")==1)
		nbrd++;

		
	}
fclose(f);



b=lookup_widget (button,"alo");
nbrt=nbrv+nbrd;
float tvb = (nbrv/nbrt)*100 ;
g_print ("%f",tvb);	


sprintf(msgs,"taux de vote blanc : %.2f   ",tvb);
gtk_label_set_text(GTK_LABEL(b),msgs);



}


void
on_validerts_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
int nbrs;
 char msga[120]="";
  char sexe[30];
 GtkWidget *output;
 GtkWidget *combobox;
   //GtkWidget *gestion; 
  //gestion=lookup_widget(button,"gestion");

combobox=lookup_widget(button,"comboboxchoixs");
    output=lookup_widget(button,"labelnombres");
    strcpy(sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
     nbrs=Sommes(sexe); sprintf(msga,"la somme vaut %d",nbrs); gtk_label_set_text(output,msga);
}

