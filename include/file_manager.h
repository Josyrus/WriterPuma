#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gtk/gtk.h>
typedef struct {
    char* name_file;
    char* path_file;
    FILE* file;
} FilePuma;

char* get_text_from_file(FilePuma* puma_tmp);
void set_path_file(FilePuma* puma_tmp,const char* path);
char* get_path_file(FilePuma* puma_tmp);
void set_name__file(FilePuma* puma_tmp, char* name_file);
char* get_name__file(FilePuma* puma_tmp);
void save_file(FilePuma* puma_tmp, bool autosave, char* text);
void destroy_file_puma(FilePuma** tmp);
FilePuma* create_file_puma(char* path, const char* text_file, const char* name_file);
