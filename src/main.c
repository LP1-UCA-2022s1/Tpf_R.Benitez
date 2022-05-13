/*
 ===========================================================================
 Name        : TPF_D&B.c
 Author      : Rosana Benitez
 Version     :
 Copyright   : Your copyright notice
 Description : Definicion de funciones declaradas en "declaraciones.h"
 ============================================================================
 */
#include <stdio.h>
#include "declaracionesGTK.h"
#include "declaraciones.h"


int main(int argc, char *argv[]){

	GError *error=NULL;
	gtk_init(&argc,&argv);
	builder=gtk_builder_new();

	//Se carga el builder
	if(gtk_builder_add_from_file(builder,"D&B grafics.glade",&error)==0) {
		g_print("Error en la funcion gtk_builder_add_from_file: \n");
		return 1;
	}


	/*VENTANAS*/
	win_entrada = GTK_WIDGET(gtk_builder_get_object(builder,"win_entrada"));
	g_signal_connect(win_entrada,"destroy",gtk_main_quit,NULL);

	win_modo_juego = GTK_WIDGET(gtk_builder_get_object(builder,"win_modo_juego"));
	g_signal_connect(win_modo_juego,"destroy",gtk_main_quit,NULL);

	win_principal = GTK_WIDGET(gtk_builder_get_object(builder,"win_principal"));
	g_signal_connect(win_principal,"destroy",gtk_main_quit,NULL);

	win_juego = GTK_WIDGET(gtk_builder_get_object(builder,"win_game"));
	g_signal_connect(win_juego,"destroy",gtk_main_quit,NULL);


	/*BOTONES*/
	btn_newgame = GTK_WIDGET(gtk_builder_get_object(builder,"btn_star"));
	g_signal_connect(btn_newgame,"button-press-event", G_CALLBACK(JuegoNuevo),NULL);

	menu_juego_nuevo = GTK_WIDGET(gtk_builder_get_object(builder,"imagemenuitem6"));
	g_signal_connect(menu_juego_nuevo,"activate", G_CALLBACK(NuevaPartida),NULL);

	menu_salir = GTK_WIDGET(gtk_builder_get_object(builder,"imagemenuitem10"));
	g_signal_connect(menu_salir,"activate", G_CALLBACK(Salir),NULL);

	btn_stats = GTK_WIDGET(gtk_builder_get_object(builder,"btn_est"));
	g_signal_connect(btn_stats,"button-press-event", G_CALLBACK(ShowStats),NULL);

	btn_help = gtk_builder_get_object(builder, "btn_ver");
	g_signal_connect(btn_help, "button-press-event", G_CALLBACK (mostrar_ayuda), NULL);

	btn_exit = GTK_WIDGET(gtk_builder_get_object(builder,"btn_exi"));
	g_signal_connect(btn_exit,"button-press-event", G_CALLBACK(Salir),NULL);

	btn_HvsPC = GTK_WIDGET(gtk_builder_get_object(builder,"btn_humano_vs_pc"));
	g_signal_connect(btn_HvsPC,"button-press-event", G_CALLBACK(ModoUSRvsPC), NULL);

	btn_PCvsPC = GTK_WIDGET(gtk_builder_get_object(builder,"btn_pc_vs_pc"));
	g_signal_connect(btn_PCvsPC,"button-press-event", G_CALLBACK(ModoPCvsPC), NULL);

	btn_iniciar = GTK_WIDGET(gtk_builder_get_object(builder,"btn_inicio"));
	g_signal_connect(btn_iniciar,"clicked", G_CALLBACK(IniciarPartida),NULL);

	btn_atras1 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_atras1"));
	g_signal_connect(btn_atras1,"clicked", G_CALLBACK(VolverAInicio),NULL);

	btn_atras2 = GTK_WIDGET(gtk_builder_get_object(builder,"btn_atras2"));
	g_signal_connect(btn_atras2,"clicked", G_CALLBACK(VolverAModoJuego),NULL);

	dialogAcerca = gtk_builder_get_object(builder, "win_acercad");


	menu_mostrar_acerca = gtk_builder_get_object(builder, "about");
	g_signal_connect(menu_mostrar_acerca, "activate", G_CALLBACK (mostrar_acerca), NULL);


	menu_mostrar_ayuda = gtk_builder_get_object(builder, "jelp");
	g_signal_connect(menu_mostrar_ayuda, "activate", G_CALLBACK (mostrar_ayuda), NULL);


	/*ENTRIES*/
	name_entry1 = GTK_WIDGET(gtk_builder_get_object(builder,"txt_jugador1"));
	name_entry2 = GTK_WIDGET(gtk_builder_get_object(builder,"txt_jugador2"));
	matrix_dim = GTK_WIDGET(gtk_builder_get_object(builder,"txt_m"));
	entry_compartida = GTK_WIDGET(gtk_builder_get_object(builder,"entry_compartida"));

	/*COMBO_BOX*/
	quien_inicia = GTK_WIDGET(gtk_builder_get_object(builder,"cb_jug_inicial"));
	g_signal_connect(quien_inicia,"changed", G_CALLBACK(QuienInicia),NULL);

	colour = GTK_WIDGET(gtk_builder_get_object(builder,"cb_color"));
	g_signal_connect(colour,"changed", G_CALLBACK(Color),NULL);

	/*LABELS*/
	lbl_puntos1 = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_pts1"));
	lbl_name1 = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_name1"));
	lbl_puntos2 = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_pts2"));
	lbl_name2 = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_name2"));

	lbl_estado = GTK_WIDGET(gtk_builder_get_object(builder,"lbl_infos"));


	gtk_widget_show_all(win_entrada);
	gtk_main();

	return 0;
}
