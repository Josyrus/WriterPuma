#include "file_manager.h"
#define MAX_FILES 1
#define TRUE_AUTOSAVE true
#define FALSE_AUTOSAVE false

void create_file(file_puma* puma_tmp)
{
    if (!puma_tmp->path_file) {
        save_file(puma_tmp, TRUE_AUTOSAVE);
    } else {
        fprintf(stdout, "Creating file at: %s\n", puma_tmp->path_file);
        fopen(strcat(puma_tmp->path_file, puma_tmp->name_file), "w");
    }
}

void save_file(file_puma* puma_tmp, bool autosave)
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
    puma_tmp->file = fopen(puma_tmp->path_file, "a");
    if (!puma_tmp->file)
    {
        fprintf(stderr, "Error abriendo archivo: %s\n", puma_tmp->path_file);
    }
}

void remove_file(const char* path)
{
    if (!path) {
        fprintf(stderr, "Error $path: %s\n", "");
        return;
    }
    remove(path);
}

static file_puma* create_file_puma(char* path)
{
    file_puma* tmp = (file_puma*)calloc(MAX_FILES, sizeof(file_puma));
    if (tmp) {
        fprintf(stdout, "Creating puma file...");
        return tmp;
    }
    tmp->path_file = path;
    return NULL;
}
static void destroy_file_puma(file_puma** tmp)
{
    free((*tmp)->name_file);
    free((*tmp)->path_file);
    if(!(*tmp)->file)
    {
    fclose((*tmp)->file);
    free((*tmp)->file);
    (*tmp)->file=NULL;
    }
    free(*tmp);
    tmp = NULL;
}
void set_path_file(file_puma* puma_tmp, char* path)
{
    size_t size = sizeof(path)+1;
    puma_tmp->path_file = (char*)malloc(size);
    snprintf(puma_tmp->path_file, size, "%s", path);
}
char* get_path_file(file_puma* puma_tmp)
{
    return puma_tmp->path_file;
}
void set_name__file(file_puma* puma_tmp, char* name_file)
{
    size_t size = sizeof(name_file);
    puma_tmp->path_file = (char*)malloc(size) + 1;
    snprintf(puma_tmp->name_file, size, "%s", name_file);
}
char* get_name__file(file_puma* puma_tmp)
{
    return puma_tmp->path_file;
}
