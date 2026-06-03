#include "../include/file_manager.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_FILES 1
#define TRUE_AUTOSAVE true
#define FALSE_AUTOSAVE false

void create_file(File_puma* puma_tmp)
{

    if (puma_tmp->path_file) {
        save_file(puma_tmp, TRUE_AUTOSAVE);
    } else {
        fprintf(stdout, "Creating file at: %s\n", puma_tmp->path_file);
        fopen(strcat(puma_tmp->path_file, puma_tmp->name_file), "w");
    }
}

void save_file(File_puma* puma_tmp, bool autosave)
{
    size_t size;
    size = strlen(puma_tmp->name_file);
    if (autosave) {
        char* prefix = "autosave";
        char date[15];
        time_t now = time(NULL); 
        strftime(date, sizeof(date), "%Y%m%d%H%M%S", localtime(&now));
        size = strlen(prefix) + strlen(date) + 1;
        puma_tmp->name_file = (char*)malloc(size);
        snprintf(puma_tmp->name_file, size, "%s%s", prefix, date);
    }
    fopen(puma_tmp->path_file, "a");
}

void remove_file(const char* path)
{
    if (!path) {
        fprintf(stderr, "Error $path: %s\n", "");
        return;
    }
    remove(path);
}

static File_puma* create_file_puma(char* path)
{
    File_puma* tmp = (File_puma*)calloc(MAX_FILES, sizeof(File_puma));
    if (tmp) {
        fprintf(stdout, "Creating puma file...");
        return tmp;
    }
    return NULL;
}
static void destroy_file_puma(File_puma** tmp)
{
    free((*tmp)->name_file);
    free((*tmp)->path_file);
    fclose((*tmp)->file);
    free(*tmp);
    tmp = NULL;
}
void set_path_file(File_puma* puma_tmp, char* path)
{
    size_t size = sizeof(path);
    puma_tmp->path_file = (char*)malloc(size) + 1;
    snprintf(puma_tmp->name_file, size, "%s", path);
}
char* get_path_file(File_puma* puma_tmp)
{
    return puma_tmp->path_file;
}
void set_name__file(File_puma* puma_tmp, char* name_file)
{
    size_t size = sizeof(name_file);
    puma_tmp->path_file = (char*)malloc(size) + 1;
    snprintf(puma_tmp->name_file, size, "%s", name_file);
}
char* get_name__file(File_puma* puma_tmp)
{
    return puma_tmp->path_file;
}
