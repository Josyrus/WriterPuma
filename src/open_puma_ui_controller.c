#include <gtk/gtk.h>
#include <open_puma_ui_controller.h>


void writter_puma_save_button_on_click(GtkApplication* app, gpointer data){

    g_print("Save pressed\n");
}
    void writter_puma_save_as_button_on_click(GtkApplication* app, gpointer data)
{
    g_print("Save As pressed\n");

}
void writter_puma_open_button_on_click(GtkApplication* app, gpointer data)
{
    g_print("Open pressed\n");
}
void writter_puma_search_word_button_on_click(GtkApplication* app, gpointer data)
{
    g_print("Search Word pressed\n");

}
void writter_puma_button_search_and_replace_button_on_click(GtkApplication* app, gpointer data)
{
    g_print("Search Word And Replace pressed\n");
}
void writter_puma_about_button_on_click(GtkApplication* app, gpointer data)
{
    g_print("About pressed\n");

}
void writter_puma_help_button_on_click(GtkApplication* app, gpointer data)
{
    g_print("Help pressed\n");

}

