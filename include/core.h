#ifndef CORE_H
#define CORE_H
#include <gtk/gtk.h>
#include <open_puma_ui_controller.h>


void on_destroy(GObject *obj, gpointer data);
void on_activate(GtkApplication* app, gpointer data);
void darkmode();
void lightmode();
#endif
