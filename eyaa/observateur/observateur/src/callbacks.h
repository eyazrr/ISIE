#include <gtk/gtk.h>
  GtkWidget *acceuilw;
  GtkWidget *gestionw;
typedef struct observateur observateur ;
struct observateur{
char cin[30];
char sexe[30];
char nationalite[30];
char date[30];
char nom[30];
char user[30];
char password[30];
char appartenance[30];
};
int i,j;


void
on_AcceuilGestionw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_GestionAcceuilw_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_bmodifier_clickedw                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_bsupprimer_clickedw                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bafficher12w_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2w_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercherutilisateur_clicked          (GtkButton       *button,
                                        gpointer         user_data);



void
on_Ajouterutilisateur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierutilisateur_clicked           (GtkButton       *button,
                                        gpointer         user_data);



void
on_button_calcule_clicked              (GtkButton       *button,
                                        gpointer         user_data);

