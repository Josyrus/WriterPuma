#include <gtk/gtk.h>
#include <libintl.h>
#include <stdbool.h>   
#define _(STRING) gettext(STRING)
/*|Archive|View|about|Help...|*/
void on_activate(GtkApplication* app, gpointer data)
{
    // Window
    GtkWidget* window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "WriterPuma");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    // UI
    /*boxs*/
    GtkWidget* box_buttons_container = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
    GtkWidget* box_file_popover = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget* box_view_popover = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
    /*buttons*/
    GtkWidget* menu_button_file = gtk_menu_button_new ();
    GtkWidget* menu_button_view= gtk_menu_button_new();
    GtkWidget* button_about= gtk_button_new_with_label(_("ABOUT"));
    GtkWidget* button_help= gtk_button_new_with_label(_("HELP"));
    GtkWidget* button_open = gtk_button_new_with_label(_("OPEN"));
    GtkWidget* button_save = gtk_button_new_with_label(_("SAVE"));
    GtkWidget* button_save_as = gtk_button_new_with_label(_("SAVE_AS"));    
    GtkWidget* button_search_word = gtk_button_new_with_label(_("SEARCH_WORD"));
    GtkWidget* button_search_and_replace = gtk_button_new_with_label(_("REPLACE"));    
    GtkWidget* popover_file=gtk_popover_new();
    GtkWidget* popover_view= gtk_popover_new();
    //file config
    gtk_box_append(GTK_BOX(box_file_popover), button_save);
    gtk_box_append(GTK_BOX(box_file_popover), button_open);
    gtk_box_append(GTK_BOX(box_file_popover), button_save_as);
    gtk_popover_set_child(GTK_POPOVER(popover_file), box_file_popover);
    gtk_menu_button_set_label(GTK_MENU_BUTTON(menu_button_file), _("FILE"));
    gtk_menu_button_set_direction(GTK_MENU_BUTTON(menu_button_file), GTK_ARROW_DOWN);
    //view
    gtk_box_append(GTK_BOX(box_view_popover),button_search_word);
    gtk_box_append(GTK_BOX(box_view_popover),button_search_and_replace);
    gtk_popover_set_child(GTK_POPOVER(popover_view),box_view_popover);
    gtk_menu_button_set_label(  GTK_MENU_BUTTON(menu_button_view), _("VIEW"));
    gtk_menu_button_set_direction(GTK_MENU_BUTTON(menu_button_view), GTK_ARROW_DOWN);
    // Text writer
    GtkWidget* box_background = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    GtkWidget* tex_view_label = gtk_text_view_new();
    GtkTextBuffer* text_view_label_buffer = gtk_text_view_get_buffer((GtkTextView*)tex_view_label);
    gtk_widget_set_hexpand(tex_view_label, TRUE);
    gtk_widget_set_vexpand(tex_view_label, TRUE);
    gtk_text_buffer_set_text(text_view_label_buffer, "", -1);
    gtk_box_append(GTK_BOX(box_background), box_buttons_container);
    gtk_box_append(GTK_BOX(box_background), tex_view_label);

    //build UI buttons 
    gtk_menu_button_set_popover(GTK_MENU_BUTTON(menu_button_file), popover_file);
    gtk_menu_button_set_popover(GTK_MENU_BUTTON(menu_button_view),popover_view);
    gtk_box_append(GTK_BOX(box_buttons_container), menu_button_file);
    gtk_box_append(GTK_BOX(box_buttons_container), menu_button_view );
    gtk_box_append(GTK_BOX(box_buttons_container),button_about);
    gtk_box_append(GTK_BOX(box_buttons_container),button_help);
    // Window open
    gtk_window_set_child(GTK_WINDOW(window), box_background);
    gtk_window_present(GTK_WINDOW(window));
}