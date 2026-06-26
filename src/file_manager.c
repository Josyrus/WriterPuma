#include "file_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_FILES 1
#define TRUE_AUTOSAVE true
#define FALSE_AUTOSAVE false
static void create_file(FilePuma* puma_tmp,const char* text_file ){
    if (!puma_tmp || !puma_tmp->path_file || !text_file){
        g_printerr("No hay nada que guardar\n");
        return;
    }
    g_print("create_file (puma_tmp)%p ",puma_tmp);
        g_print("Creating file at: %s\n", puma_tmp->path_file);
        puma_tmp->file = fopen(puma_tmp->path_file, "w");
        if (!puma_tmp->file) {
            g_printerr("Error al crear el archivo\n");
            return;
        }
        fputs((char*)text_file,puma_tmp->file);
        fclose(puma_tmp->file);
        puma_tmp->file = NULL;
}
char* get_text_from_file(FilePuma* file_tmp){
    if (!file_tmp || !file_tmp->path_file)  
        return NULL;
    file_tmp->file = fopen(file_tmp->path_file, "r");
    if (!file_tmp->file)  
        return NULL;
    fseek(file_tmp->file,0,SEEK_END);
    long size = ftell(file_tmp->file);
    rewind(file_tmp->file);
    char*buffer= malloc(size+1);
    fread(buffer, sizeof(char), size, file_tmp->file);
    buffer[size] = '\0';
    fclose(file_tmp->file);
    file_tmp->file=NULL;
    return buffer;
}
void save_file(FilePuma* puma_tmp, bool autosave, char* text){
    if (autosave) {
        g_print("Autosaving...");
        char* prefix = "autosave";
        char date[15];
        time_t now = time(NULL); 
        strftime(date, sizeof(date), "%Y%m%d%H%M%S", localtime(&now));
        set_name__file(puma_tmp, strcat(prefix,date));
        char *route = g_build_filename(g_get_user_data_dir(), "writerpuma", NULL);
        set_path_file(puma_tmp,route);
        g_free(route);
    }
    puma_tmp->file = fopen(puma_tmp->path_file, "w");
    if (!puma_tmp->file)
    {
        g_print("Error opening this: %s\n", puma_tmp->path_file);
        return;
    }
    fputs(text,puma_tmp->file);
    fclose(puma_tmp->file);
    puma_tmp->file=NULL;
    g_print("File saved");
}
FilePuma* create_file_puma(char* path, const char* text_file, const char* name_file){
    FilePuma* tmp = (FilePuma*)calloc(MAX_FILES, sizeof(FilePuma));
    g_print("create_file_puma (tmp)Creating %p\n",tmp);

    if (tmp) {
        set_path_file(tmp,path);
        set_name__file(tmp,(char*)name_file);
        if (text_file) 
            create_file(tmp, (char*)text_file);
        g_print("create_file_puma (tmp->path_file)Creating... %s\n",tmp->path_file);
        return tmp;
    }
    return NULL;
}
void destroy_file_puma(FilePuma** tmp){
    g_print("destroy_file_puma (tmp)destroying struct [%p]\n",(tmp));
    g_print("destroy_file_puma (*tmp)destroying struct [%p]\n",(*tmp));
    
    if((*tmp))
    {
        //free((*tmp)->name_file);
        g_print("destroy_file_puma (*tmp)->path_file)destroying [%p]\n",(*tmp)->path_file);
        free((*tmp)->path_file);
        if((*tmp)->file)
        {
            fclose((*tmp)->file);
            g_print("destroy_file_puma (*tmp)->file)destroying [%p]\n",(*tmp)->file);
            (*tmp)->file=NULL;        
        }
        free(*tmp);
        *tmp = NULL; 
    }
}
void set_path_file(FilePuma* puma_tmp,const char* path){
    if (!path || !puma_tmp)
        return;
    size_t size = strlen(path) + 1;  
    puma_tmp->path_file = malloc(size);
    memcpy(puma_tmp->path_file, path, size);
}
char* get_path_file(FilePuma* puma_tmp)
{
    return puma_tmp->path_file;
}
void set_name__file(FilePuma* puma_tmp, char* name_file){
    if(!puma_tmp || !name_file)
        return;
    size_t size = strlen(name_file) +1 ;
    puma_tmp->name_file = (char*)malloc(size);
    snprintf(puma_tmp->name_file, size, "%s", name_file);
}
char* get_name__file(FilePuma* puma_tmp){
    return puma_tmp->path_file;
}
