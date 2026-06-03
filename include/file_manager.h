#include <stdbool.h>
#include <stdio.h>
typedef struct {
    char* name_file;
    char* path_file;
    FILE* file;
} File_puma;
void create_file(File_puma* puma_tmp);
void remove_file(const char* path);
void set_path_file(File_puma* puma_tmp, char* path);
char* get_path_file(File_puma* puma_tmp);
void set_name__file(File_puma* puma_tmp, char* name_file);
char* get_name__file(File_puma* puma_tmp);
void save_file(File_puma* puma_tmp, bool autosave);
