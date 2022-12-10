#include <gtk/gtk.h>


void
on_buttonge_add_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonge_modiff_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttongeaffich_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonGEAjoutRetour_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonGEModifRetour_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonGEAjouter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewge_abir_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supp_abir_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherche_abir_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmod_abir_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkBox_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkBox_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btn_to_stat_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_calculer_nbe_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Calculer_tpe_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Calculer_tphf_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Quitter_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Retour_stat_clicked             (GtkButton       *button,
                                        gpointer         user_data);
