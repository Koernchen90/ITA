#include <gtk/gtk.h>
#include <stdlib.h>

struct gui_t
{
	GtkWidget *fenster;
	GtkWidget *schachtel;
	GtkWidget *weg;
	GtkWidget *iweg;
	GtkWidget *verbrauch;
	GtkWidget *iverbrauch;
	GtkWidget *berechnen;
	GtkWidget *ausgabe;
	GtkWidget *ende;
};

void eingabe1(GtkWidget *fenster, gpointer daten)
{
	const char *p;
	struct gui_t *pgui=daten;
	p=gtk_entry_get_text(GTK_ENTRY(pgui->iweg));
	g_print("Erste EIngabe: %lf\n",atof(p));
	
	return;
}

void eingabe2(GtkWidget *fenster, gpointer daten)
{
	const char *p;
	struct gui_t *pgui=daten;
	p=gtk_entry_get_text(GTK_ENTRY(pgui->iverbrauch));
	g_print("Zweite Eingabe: %lf\n",atof(p));
	
	return;
}

void output(GtkWidget *fenster, gpointer daten)
{
	const char *pweg;
	const char *pverbrauch;
	double weg, verbrauch, durchschnitt;
	char berechnung[80];
	struct gui_t *pgui=daten;
	
	pweg=gtk_entry_get_text(GTK_ENTRY(pgui->iweg));
	weg=atof(pweg);
	g_print("Weg: %lf\n",weg);
	
	pverbrauch=gtk_entry_get_text(GTK_ENTRY(pgui->iverbrauch));
	verbrauch=atof(pverbrauch);
	g_print("Verbrauch: %lf\n",verbrauch);
	
	durchschnitt=weg/verbrauch;
	g_print("Durchschnittsverbauch: %lf\n",durchschnitt);
	sprintf(berechnung, "Durchschnittsverbauch: %.2lf l/km", durchschnitt);
	gtk_label_set_text(GTK_LABEL(pgui->ausgabe), berechnung);	
	
	return;
}

int main(int argc, char *argv[])
{
	struct gui_t gui;
	const char *mweg;
	gtk_init(&argc, &argv);
	
	gui.fenster=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gui.schachtel=gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
	gui.weg=gtk_label_new("Weg in km:");
	gui.iweg=gtk_entry_new();
	gui.verbrauch=gtk_label_new("Verbrauch in l:");
	gui.iverbrauch=gtk_entry_new();
	gui.berechnen=gtk_button_new_with_label("Berechnen");
	gui.ausgabe=gtk_label_new("Durchschnittsverbauch");
	gui.ende=gtk_button_new_with_label("Beenden");
	
	gtk_container_add(GTK_CONTAINER(gui.fenster), gui.schachtel);
	
	gtk_box_pack_start(GTK_BOX(gui.schachtel), gui.weg, TRUE, TRUE, 2);
	gtk_box_pack_start(GTK_BOX(gui.schachtel), gui.iweg, TRUE, TRUE, 2);
	gtk_box_pack_start(GTK_BOX(gui.schachtel), gui.verbrauch, TRUE, TRUE, 2);
	gtk_box_pack_start(GTK_BOX(gui.schachtel), gui.iverbrauch, TRUE, TRUE, 2);
	gtk_box_pack_start(GTK_BOX(gui.schachtel), gui.berechnen, TRUE, TRUE, 2);
	gtk_box_pack_start(GTK_BOX(gui.schachtel), gui.ausgabe, TRUE, TRUE, 2);
	gtk_box_pack_start(GTK_BOX(gui.schachtel), gui.ende, TRUE, TRUE, 2);
	
	g_signal_connect(G_OBJECT(gui.fenster),"delete_event", gtk_main_quit, NULL);
	g_signal_connect(G_OBJECT(gui.ende),"clicked", gtk_main_quit, NULL);
	g_signal_connect(G_OBJECT(gui.iweg),"changed", G_CALLBACK(eingabe1), &gui);
	g_signal_connect(G_OBJECT(gui.iverbrauch),"changed", G_CALLBACK(eingabe2), &gui);
	g_signal_connect(G_OBJECT(gui.berechnen), "clicked", G_CALLBACK(output), &gui);	
	
	gtk_widget_show_all(gui.fenster);
	gtk_main();
	
	return 0;
}
	
