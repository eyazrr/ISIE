#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"CRUD.h"
//selection men treeview 
GtkTreeSelection *selection1;
// tod5el l gestion 
void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data)  //signal yahbet par defaut  type clicked 
{
/*preparation du treeView*/
GtkWidget *p;
gtk_widget_hide (acceuilw); // 5abina page gestion
gestionw = create_gestionw (); // page lbarania taaml creation taa page gestion 
p=lookup_widget(gestionw,"treeview2w"); // aaytna ll treeview 
Afficherobservateur(p,"observateur.txt"); //affichina donnee fi treeview 
gtk_widget_show (gestionw); // afficher pge gestion
i=0; // affichage mrra wahda
j=0;
}


void
on_Ajouterutilisateur_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
observateur o;
GtkWidget *entrylog; 
GtkWidget *entrypass;
GtkWidget *log;
GtkWidget *pass;
//declaration des entry selon nti shnia samithom fl glade 
GtkWidget *numb;
GtkWidget *saisirnum;


GtkWidget *entrysexew;
GtkWidget *entryIdw;
GtkWidget *entrynatw;
//GtkWidget *entryDatew;
GtkWidget *entrynomw;
GtkWidget *labelIdw;
GtkWidget *labelsexew;
GtkWidget *labelnatw;
GtkWidget *labelDatew;
GtkWidget *labelnomw;
//controle de saisie declaration 
GtkWidget *existew;
GtkWidget* successw;
GtkWidget *calw;
int b=1;
//calendar 
int jj1,mm1,aa1;
//pointeur aal fichier obs.txt
FILE*f=NULL;

numb=lookup_widget(gestionw,"numb");

saisirnum=lookup_widget(gestionw,"saisirnum");

entryIdw=lookup_widget(gestionw,"entry5w");
entrysexew=lookup_widget(gestionw,"combobox1w");
entrynatw=lookup_widget(gestionw,"combobox2w");

entrylog=lookup_widget(gestionw,"entrylog");
entrypass=lookup_widget(gestionw,"entrypass");
log=lookup_widget(gestionw,"log");
pass=lookup_widget(gestionw,"pass");


entrynomw=lookup_widget(gestionw,"entry3w");

labelIdw=lookup_widget(gestionw,"label13w");
labelsexew=lookup_widget(gestionw,"label7w");
labelnatw=lookup_widget(gestionw,"label8w");

labelnomw=lookup_widget(gestionw,"label10w");
existew=lookup_widget(gestionw,"label34w");


successw=lookup_widget(gestionw,"label35w");
calw=lookup_widget(gestionw,"yawmia");
        strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(entryIdw) ) ); // copier coller
        strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexew)));
        strcpy(o.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrynatw)));
        strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(entrynomw) ) );
        strcpy(o.user,gtk_entry_get_text(GTK_ENTRY(entrylog) ) );
        strcpy(o.password,gtk_entry_get_text(GTK_ENTRY(entrypass) ) );
        strcpy(o.appartenance,gtk_entry_get_text(GTK_ENTRY(numb) ) );
    
 gtk_widget_hide (successw); //n5abou message success 
//calendar getdate 
 gtk_calendar_get_date (GTK_CALENDAR(calw),
                       &aa1,
                       &mm1,
                       &jj1);



 gtk_widget_hide (successw); 


// controle saisie 5pts 
if(strcmp(o.cin,"")==0){ // comparer bin champs o li mesh tektbou enti fl emput 
		  gtk_widget_show (labelIdw); // ykolk ekteb rao  champ fera4
b=0;
}
else {
		  gtk_widget_hide(labelIdw); // ykhabi message erreur 
}

if(strcmp(o.sexe,"")==0){
		  gtk_widget_show (labelsexew);
b=0;
}
else {
		  gtk_widget_hide(labelsexew);
}
if(strcmp(o.nationalite,"")==0){
		  gtk_widget_show (labelnatw);
b=0;
}
else {
		  gtk_widget_hide(labelnatw);
}

if(strcmp(o.nom,"")==0){
		  gtk_widget_show (labelnomw);
b=0;
}
else {
		  gtk_widget_hide(labelnomw);
}

if(strcmp(o.user,"")==0){
		  gtk_widget_show (log);
b=0;
}
else {
		  gtk_widget_hide(log);
}

if(strcmp(o.password,"")==0){
		  gtk_widget_show (pass);
b=0;
}
else {
		  gtk_widget_hide(pass);
}



if(strcmp(o.appartenance,"")==0){
		  gtk_widget_show (saisirnum);
b=0;
}
else {
		  gtk_widget_hide(saisirnum);
}




if(b==1){

//existance 

        if(exist_observateur(o.cin)==1)  //cin daltou enti o les cin li mawjoudin fl fichier txt yshoufhom ken mawjoud 
        {

				  gtk_widget_show (existew); //rao mawjoud 
                }
                else {                     gtk_widget_hide (existew); // maykharjlk shy

       f=fopen("observateur.txt","a+"); //ken mawjoud yhel fichier text  ken moush mawjoud aamlou creation whelou 
fprintf(f,"%s %s %s %d/%d/%d %s %s %s %s\n",o.cin,o.sexe,o.nationalite,jj1,mm1+1,aa1,o.nom,o.user,o.password,o.appartenance); //baad ma thelou ekteb fih
//li zednehom lkol
fclose(f);
     
//ajouter_observateur(o);
                  gtk_widget_show (successw); // c bon tzed 


//mise a jour du treeView
        GtkWidget* p=lookup_widget(gestionw,"treeview2w");

        Afficherobservateur(p,"observateur.txt");
}

}
}



void
on_Modifierutilisateur_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
//declaration input/ label messaget combo
      GtkWidget *combobox3w;
        GtkWidget *combobox4w;
     combobox3w=lookup_widget(button,"combobox3w");
     combobox4w=lookup_widget(button,"combobox4w");
       	 observateur o;
//copier m trreeview ---> coller  page modifer : strcpy
        strcpy(o.cin,gtk_label_get_text(GTK_LABEL(lookup_widget(gestionw,"label20w"))));
        
     strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox3w"))));
     strcpy(o.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestionw,"combobox4w"))));
        strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w"))));
        strcpy(o.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w"))));

   strcpy(o.user,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entrylogm"))));
   strcpy(o.password,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"entrypassm"))));



 strcpy(o.appartenance,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestionw,"numbrm"))));
   
        supprimer_observateur(o.cin);
        ajouter_observateur(o);
//mise ajour du tree view 
        Afficherobservateur(lookup_widget(gestionw,"treeview1"),"observateur.txt"); //afficher baad ma badelt fih 
	gtk_widget_show(lookup_widget(gestionw,"label37w"));
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherobservateur(p,"observateur.txt");
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

nb=Chercherobservateur(p1w,"observateur.txt",cin);
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
        gchar *nationalite;
        gchar *date;
        gchar *nom;
 gchar *user;
 gchar *password;
 gchar *appartenance;
  
        GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

        gtk_widget_hide(lookup_widget(gestionw,"label37w"));//cacher label modifier avec succees
                gtk_tree_model_get (model,&iter,0,&cin,1,&sexe,2,&nationalite,3,&date,4,&nom,5,&user,6,&password,7,&appartenance,-1);//recuperer les information de la ligne selectionneé   
        // //remplir les champs de entry  
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox3w")),sexe);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"combobox4w")),nationalite);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry9w")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entry8w")),nom);


		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entrylogm")),user);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"entrypassm")),password);

		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestionw,"numbrm")),appartenance);
		


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
    gchar *nationalite;
    gchar *date;
    gchar *nom;
   gchar *user;
 gchar *password;
 gchar *appartenance;
    GtkTreeModel     *model;
    GtkTreeIter iter;
       if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {
            gtk_tree_model_get (model,&iter,0,&cin,1,&sexe,2,&nationalite,3,&date,4,&nom,5,&user,6,&password,7,&appartenance,-1);//recuperer les information de la ligne selectionneé
            supprimer_observateur(cin);
            Afficherobservateur(lookup_widget(gestionw,"treeview2w"),"observateur.txt");        
        }
}


void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        Afficherobservateur(p,"observateur.txt");
}


void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
    	gchar *cin;
        gchar *sexe;
        gchar *nationalite;
        gchar *date;
        gchar *nom;
        gchar *user;
        gchar *password;
 gchar *appartenance;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestionw,"treeview2w");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
       
}












