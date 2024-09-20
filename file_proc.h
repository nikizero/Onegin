#ifndef FILE_PROC_H
#define FILE_PROC_H

#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

FILE *open_file(const char *file, const char * mode);
size_t size_file(FILE* file);
char** run_write_file(FILE* file, int* hms);
char** write_oneg(FILE *file, int* hms);
void save(char** chars, FILE* file, int hms);


#endif 