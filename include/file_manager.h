#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct {
    char* name_file;
    char* path_file;
    FILE* file;
} file_puma;
void create_file(file_puma* puma_tmp);
void remove_file(const char* path);
void set_path_file(file_puma* puma_tmp, char* path);
char* get_path_file(file_puma* puma_tmp);
void set_name__file(file_puma* puma_tmp, char* name_file);
char* get_name__file(file_puma* puma_tmp);
void save_file(file_puma* puma_tmp, bool autosave);
