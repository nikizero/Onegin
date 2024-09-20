#include "file_proc.h"
#include "util.h"

char** write_oneg(FILE * file, int* hms)
{
    assert(hms);
    assert(file);

    int num_of_str  = 0;
    char *all_chars = (char *)  calloc(size_file(file) + 1, 1); //здесь хранятся все символы

    size_t bytesRead = fread(all_chars, 1, size_file(file), file);

    all_chars[bytesRead] = EOF;

    *hms =  how_man_str(all_chars);

    char **str_adr  = (char **) calloc(*hms, sizeof(char *)); //Здесь хранятся указатели на начала строк
    
    *(str_adr) = all_chars;
    num_of_str++;
    for (int i = 0; all_chars[i] != EOF; i++)
    {
        if (all_chars[i] == '\0')
        {
            *(str_adr + num_of_str) = all_chars + i + 1;
            num_of_str++;
        }
    }
    return str_adr;
}

size_t size_file(FILE* file)
{    
    assert(file);

    fseek(file, 0, SEEK_SET);
    int sys_file = fileno(file);
    if (sys_file == -1) 
    {
        perror("Ошибка открытия файла 2!\n");
        return 1;
    }

    struct stat st = {};                                  
    if (fstat(sys_file, &st) == -1) 
    {
        perror("Ошибка получения информации о файле");
        close(sys_file); 
        return 1;
    }

    return st.st_size;
    
}

FILE * open_file(const char *name_file, const char* mode) // норм
{
    assert(name_file);
    assert(mode);
    
    FILE *file = fopen(name_file, mode);
    if (file == NULL) 
    {
        perror("Ошибка открытия файла 1!\n");
        return 0;
    } 
    return file;
}

char** run_write_file(FILE* file, int* hms)
{
    assert(hms);
    assert(file);
    
    char** chars = write_oneg(file, hms);
    if (chars == NULL) 
    {
        fclose(file);
        return NULL;
    }
    return chars;
}

// void save (char** chars, FILE* file)
// {
//     fwrite(chars, sizeof(char), size_file(file), file);
// }

void save(char** chars, FILE* file, int hms)
{
    for (int i = 0; i < hms; i++)
    {
        fprintf(file, "%s\n", chars[i]);
    }
}