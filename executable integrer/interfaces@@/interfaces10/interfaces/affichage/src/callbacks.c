#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "function.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

float homme,femme;
election e;
int check=0;
void
on_buttonge_add_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *ajouter;
	GtkWidget *afficher_abir;
	afficher_abir=lookup_widget(button,"gestion_des_elections");
	gtk_widget_destroy(afficher_abir);
	ajouter=create_ajouter_election();
	gtk_widget_show (ajouter);
}


void
on_buttonge_modiff_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *ajouter;
	GtkWidget *afficher_abir;
	afficher_abir=lookup_widget(button,"gestion_des_elections");
	gtk_widget_destroy(afficher_abir);
	ajouter=create_modifier_election();
	gtk_widget_show (ajouter);
 GtkWidget* msgId=lookup_widget(ajouter,"label35");
 gtk_label_set_text(GTK_LABEL(msgId),e.id);
                gtk_widget_show(msgId);
}


void
on_buttongeaffich_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher, *w1;

GtkWidget *treeview1;

w1=lookup_widget(button,"gestion_des_elections");
fenetre_afficher=create_gestion_des_elections ();
gtk_widget_show(fenetre_afficher);

gtk_widget_hide (w1);
treeview1=lookup_widget(fenetre_afficher,"treeviewge_abir");
afficherelection (treeview1);
}


void
on_buttonGEAjoutRetour_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
	GtkWidget *afficher_abir;
	afficher_abir=lookup_widget(button,"ajouter_election");
	gtk_widget_destroy(afficher_abir);
	ajouter=create_gestion_des_elections();
	gtk_widget_show (ajouter);
}


void
on_buttonGEModifRetour_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *ajouter;
	GtkWidget *afficher_abir;
	afficher_abir=lookup_widget(button,"modifier_election");
	gtk_widget_destroy(afficher_abir);
	ajouter=create_gestion_des_elections();
	gtk_widget_show (ajouter);
}


void
on_buttonGEAjouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	GtkWidget* id;
	GtkWidget* Jour; //spinbuttun pour le choix du jour.
	GtkWidget* Mois; //spinbuttun pour Le choix du mois.
	GtkWidget* Annee; //spinbuttun pour le choix de l'année.
	GtkWidget* ComboboxM; //comobox pour Le choix de la municipalité.
	GtkWidget* Nbr_h ;
	GtkWidget* Nbr_c ;
	GtkWidget* outCheck;
	
//declarer la struct qui ajouter
        election E;
// associer les objets avec des variables
	id=lookup_widget(button,"entryy_id") ;
	Jour = lookup_widget(button,"spin_ge_A_jour") ;
	Mois = lookup_widget(button,"comboboxa_abir") ;
	Annee = lookup_widget(button,"spin_ge_A_annee") ;
	ComboboxM = lookup_widget(button,"combo_muni_abir") ;
	Nbr_h = lookup_widget(button,"entry_GE_A_nbh") ;
	Nbr_c = lookup_widget(button,"entry_GE_A_nbc") ;
	outCheck = lookup_widget(button,"labelCheck") ;
//recupurer les nbr
strcpy(E.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(E.m.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (ComboboxM)));
strcpy(E.m.nbrhabitants,gtk_entry_get_text(GTK_ENTRY(Nbr_h)));
strcpy(E.m.nbrconseiller,gtk_entry_get_text(GTK_ENTRY(Nbr_c)));

	
// récupérer les valeurs des spin buttons 
	
	E.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	strcpy(E.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX (Mois)));
	E.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));



//appel de la function ajouter

if(!verifier(E.id)){
	if (check!=0){
	 ajouterelection(E);
	 //traja3ni ltree view 
	 GtkWidget *ajouter101;
	 GtkWidget *destroy101;
	 destroy101=lookup_widget(button,"ajouter_election");
	 gtk_widget_destroy(destroy101);
	 ajouter101=create_gestion_des_elections();
	 gtk_widget_show (ajouter101);
	}
	else{
	 GdkColor color;
			gdk_color_parse("red",&color);
			gtk_widget_modify_fg(outCheck,GTK_STATE_NORMAL,&color);
			gtk_label_set_text(GTK_LABEL(outCheck),"Check s'il vous plait !");
	}
}
else{
GdkColor color;
			gdk_color_parse("red",&color);
			gtk_widget_modify_fg(outCheck,GTK_STATE_NORMAL,&color);
			gtk_label_set_text(GTK_LABEL(outCheck),"s'il vous plait changé l'identifiant !");
}
	

}



void
on_treeviewge_abir_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar* id;
gchar* municipalite;
gchar* nbrhabitants;
gchar* nbrconseiller;
gchar* jour;
gchar* mois;
gchar* annee;


election L;
GtkTreeIter iter;
GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id,1,&municipalite,3,&nbrhabitants,4,&nbrconseiller,5, &jour,6, &mois,7, &annee,-1);
	strcpy(e.id,id);
	}


}


void
on_supp_abir_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
char z[30];


strcpy(z,e.id);
	supprimerelection(z);

GtkWidget *fenetre_afficher, *w1;

GtkWidget *treeview1;

w1=lookup_widget(button,"gestion_des_elections");
fenetre_afficher=create_gestion_des_elections ();
gtk_widget_show(fenetre_afficher);

gtk_widget_hide (w1);
treeview1=lookup_widget(fenetre_afficher,"treeviewge_abir");
afficherelection (treeview1);
}


void
on_recherche_abir_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *cherch;
char ch[40];
GtkWidget *treeview1_a;
GtkWidget *afficher_a;
afficher_a=lookup_widget(button,"gestion_des_elections");

treeview1_a=lookup_widget(afficher_a,"treeviewge_abir");
cherch = lookup_widget (button ,"entry_recher_abir");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 chercherelection(treeview1_a,ch);
}


void
on_buttonmod_abir_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget* Jour; //spinbuttun pour le choix du jour.
	GtkWidget* Mois; //spinbuttun pour Le choix du mois.
	GtkWidget* Annee; //spinbuttun pour le choix de l'année.
	GtkWidget* ComboboxM; //comobox pour Le choix de la municipalité.
	GtkWidget* Nbr_h ;
	GtkWidget* Nbr_c ;
	
//declarer la struct qui ajouter
        election L;
// associer les objets avec des variables
	strcpy(L.id,e.id);
	Jour = lookup_widget(button,"spinm_jour") ;
	Mois = lookup_widget(button,"comboboxm_mois") ;
	Annee = lookup_widget(button,"spinm_annee") ;
	ComboboxM = lookup_widget(button,"combobox2_abir") ;
	Nbr_h = lookup_widget(button,"entrym_nbhabitant") ;
	Nbr_c = lookup_widget(button,"entrygem_nbcons") ;
//recupurer les nbr
strcpy(L.m.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (ComboboxM)));
strcpy(L.m.nbrhabitants,gtk_entry_get_text(GTK_ENTRY(Nbr_h)));
strcpy(L.m.nbrconseiller,gtk_entry_get_text(GTK_ENTRY(Nbr_c)));

	
// récupérer les valeurs des spin buttons 
	
	L.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	strcpy(L.d.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX (Mois)));
	L.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));

	modifierelection(L);
//traja3ni ltree view 
	GtkWidget *ajouter101;
	GtkWidget *destroy101;
	destroy101=lookup_widget(button,"modifier_election");
	gtk_widget_destroy(destroy101);
	ajouter101=create_gestion_des_elections();
	gtk_widget_show (ajouter101);
}


void
on_checkBox_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{check=1;}
}


void
on_btn_to_stat_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter101;
	GtkWidget *destroy101;
	destroy101=lookup_widget(button,"gestion_des_elections");
	gtk_widget_destroy(destroy101);
	ajouter101=create_Statistique();
	gtk_widget_show (ajouter101);
}


void
on_btn_calculer_nbe_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id a chercher
	  GtkWidget* output;
//declarer des variables
	int result;
	char idch[10]; 
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"entry_idL_nbe") ;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//appel function nbv
int idint;
idint=atoi(idch);
	result=nbe("utilisateur.txt",idint);
	char resch[20];
sprintf(resch,"%d",result);
//*************************************
	 output=lookup_widget(button,"label_R_nbe");
	 gtk_label_set_text(GTK_LABEL(output),resch);
}


void
on_btn_Calculer_tpe_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* output;
float tpe;
tpe=TPE("utilisateur.txt");
char resch[20];
gcvt(tpe, 6, resch);
 output=lookup_widget(button,"label_R_tpe");
 gtk_label_set_text(GTK_LABEL(output),resch);
}


void
on_btn_Calculer_tphf_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* outputH;
GtkWidget* outputF;
TPHF("utilisateur.txt",&homme,&femme);
char resH[20];
char resF[20];
gcvt(homme, 6, resH);
gcvt(femme, 6, resF);
 	outputH=lookup_widget(button,"label_R_homme");
 	outputF=lookup_widget(button,"label_femme");
 	gtk_label_set_text(GTK_LABEL(outputH),resH);
 	 gtk_label_set_text(GTK_LABEL(outputF),resF);
}


void
on_btn_Quitter_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_btn_Retour_stat_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter101;
	GtkWidget *destroy101;
	destroy101=lookup_widget(button,"Statistique");
	gtk_widget_destroy(destroy101);
	ajouter101=create_gestion_des_elections();
	gtk_widget_show (ajouter101);
}

