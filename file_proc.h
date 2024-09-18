#ifndef FILE_PROC_H
#define FILE_PROC_H

#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

FILE *open_file(const char *file);
size_t size_file(FILE* file, int mode);
size_t how_man_chars(FILE* file);
size_t how_man_str(char *all_chars);
char** write_oneg(FILE *file, int* hms);

#endif // FILE_PROC_H