#include <gtk/gtk.h>
#include "open_puma_ui_controller.h"
#include "glib-object.h"


static void name_app_tittle(gpointer data){
    open_puma_context_app *ctx = (open_puma_context_app*) data;
    if(!ctx)
        return;
    GtkWindow *window = gtk_application_get_active_window(ctx->app);
    if(!window)
        return;
    gtk_window_set_title(GTK_WINDOW(window), (*ctx->file)->name_file );
}
static void on_save_response(GObject *source, GAsyncResult *result, gpointer data) {
    open_puma_context_app *ctx = (open_puma_context_app *) data;
    GtkFileDialog *dialog = GTK_FILE_DIALOG(source);
    GError *error = NULL;
    GFile *file = gtk_file_dialog_save_finish(dialog, result, &error);
    GtkTextIter start, end;
    if (error) {
        g_clear_error(&error);
        return;
    }
    if((*ctx->file))
        destroy_file_puma(ctx->file);
    char *path = g_file_get_path(file);
    gtk_text_buffer_get_bounds(ctx->buffer, &start, &end);
    char *tex_label = gtk_text_buffer_get_text(ctx->buffer, &start, &end, FALSE);
    g_print("on_save_response (file)on save %s\n", path);
    char *name = g_file_get_basename(file);
    if (file) 
        *ctx->file = create_file_puma(path, tex_label, name);
    name_app_tittle(data);
    g_free(path);
    g_object_unref(file); 
    g_free(name);
    g_free(tex_label);
}
static void on_open_response(GObject *source, GAsyncResult *result, gpointer data){
    open_puma_context_app *ctx = (open_puma_context_app *) data;
    GtkFileDialog *dialog = GTK_FILE_DIALOG(source);
    GError *error = NULL;
    GFile *file = gtk_file_dialog_open_finish(dialog, result, &error);
    if(error)
    {
        g_clear_error(&error);
        return;
    }
    if (*ctx->file) {
        destroy_file_puma(ctx->file);
    }
    char *path = g_file_get_path(file);
    char *name = g_file_get_basename(file);
    *ctx->file = create_file_puma(path, NULL, name);
    g_free(path);
    g_free(name);
    char *text = get_text_from_file(*ctx->file);
    if (text) {
        gtk_text_buffer_set_text(ctx->buffer, text, -1);
        free(text);
    }
    g_object_unref(file);
}
void writter_puma_destroy_files_app(GtkApplication* app, gpointer data){
    open_puma_context_app *ctx = (open_puma_context_app *) data;
    g_print("\nwritter_puma_destroy_files_app (fp) %p\n", ctx->file);
    destroy_file_puma(ctx->file);
    free(ctx->file);  
    free(ctx);  
}
void writter_puma_save_button_on_click(GtkWidget* widget, gpointer data){
    open_puma_context_app *ctx = (open_puma_context_app*) data;
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(ctx->buffer, &start, &end);
    char* tex_label= gtk_text_buffer_get_text(ctx->buffer,&start,&end,FALSE);
    g_print("Save pressed\n");
    if(!*ctx->file)
        writter_puma_save_as_button_on_click(widget,data);
    else
    {
        save_file(*ctx->file,FALSE,(char*) tex_label);
    }
    g_free(tex_label);
}
void writter_puma_save_as_button_on_click(GtkWidget *widget, gpointer data) {   
    GtkWindow *parent = GTK_WINDOW(gtk_widget_get_root(widget));
    GtkFileDialog *dialog = gtk_file_dialog_new();
    gtk_file_dialog_save(dialog, parent, NULL, on_save_response, data);
    g_object_unref(dialog);
}
void writter_puma_open_button_on_click(GtkWidget *widget, gpointer data){
    GtkWindow *parent = GTK_WINDOW(gtk_widget_get_root(widget));
    GtkFileDialog * dialog = gtk_file_dialog_new();
    gtk_file_dialog_open(dialog,parent,NULL,on_open_response,data);
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
