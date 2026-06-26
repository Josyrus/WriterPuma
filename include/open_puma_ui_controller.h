#include <gtk/gtk.h>
#include <libintl.h>
#include <stdbool.h>   
#include <file_manager.h>


typedef struct {
    GtkApplication  *app;
    FilePuma       **file;  
    GtkTextBuffer   *buffer;
} open_puma_context_app;

void writter_puma_open_button_on_click(GtkWidget *widget, gpointer data);
void writter_puma_save_button_on_click(GtkWidget* widget, gpointer data);
void writter_puma_save_as_button_on_click(GtkWidget *widget, gpointer data);
void writter_puma_destroy_files_app(GtkApplication* app, gpointer darkmode);
void writter_puma_search_word_button_on_click(GtkApplication* app, gpointer data);
void writter_puma_button_search_and_replace_button_on_click(GtkApplication* app, gpointer data);
void writter_puma_about_button_on_click(GtkApplication* app, gpointer data);
void writter_puma_help_button_on_click(GtkApplication* app, gpointer data);
