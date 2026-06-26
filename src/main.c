#include <gtk/gtk.h>
#include <core.h>

int main(int argc, char** argv)
{
    GtkApplication* app = gtk_application_new("io.github.josyrus.WriterPuma.app", G_APPLICATION_DEFAULT_FLAGS);
    //g_signal_connect(app, "begin", G_CALLBACK(),NULL);
    gpointer data=NULL;
    g_print("Iniciando App\n");
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), &data);
    //g_signal_connect(app, "shutdown", G_CALLBACK(on_destroy), &data);
    int status = g_application_run(G_APPLICATION(app), argc,argv);
    g_print("exit estatus %d",status);
    g_object_unref(app);
}
