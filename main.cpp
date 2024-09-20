#include "sorting.h"
#include "file_proc.h"
#include"util.h"

int main() 
{
    int hms = 0;
    const char *name_file   = "data/onegin.txt";
    const char *name_file_2 = "data/onegin++.txt";

    FILE *file    = open_file(name_file, "r");
    FILE *file_pp = open_file(name_file_2, "w");

    char** chars = run_write_file(file, &hms);
    
    sort((void*)chars, hms, sizeof(char*), compare_from_end, qsort);
    printing(hms, chars);

    save(chars, file_pp, hms);

    fclose(file);
    fclose(file_pp);
    free(chars);
    return 0;
}