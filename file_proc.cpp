#include "file_proc.h"

size_t how_man_str (char *all_chars)
{
    int how_man_str = 1;
    for (int i = 0; all_chars[i] != EOF; i++)
    {
        if ((int) all_chars[i] == '\n' || all_chars[i] == EOF)
        {
            all_chars[i] = '\0';
            how_man_str++;
        }
    }
    return how_man_str;
}

size_t how_man_chars (FILE* file)
{
    return size_file(file, 0)/sizeof(char);
}

char** write_oneg(FILE * file, int* hms)
{
    int num_of_str  = 0;
    char *all_chars = (char *)  calloc(size_file(file, 0) + 2, 1); //здесь хранятся все символы

    size_t bytesRead = fread(all_chars, 1, size_file(file, 1), file);

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

size_t size_file(FILE* file, int mode)
{    
    fseek(file, 0, SEEK_SET);
    int sys_file = fileno(file);
    if (sys_file == -1) 
    {
        perror("Ошибка открытия файла 2!\n");
        return 0;
    }

    struct stat st;                                    //st инициализруется при запуске функции на следущей строке
    if (fstat(sys_file, &st) == -1) 
    {
        perror("Ошибка получения информации о файле");
        close(sys_file); 
        return 0;
    }

    if (mode == 0)
    {
        return st.st_size;
    }

    else if (mode == 1)
    {
        return how_man_chars (file);
    }
    return 0;
}

FILE * open_file(const char *name_file) // норм
{
    FILE *file = fopen(name_file, "r");
    if (file == NULL) 
    {
        perror("Ошибка открытия файла 1!\n");
        return 0;
    }
    return file;
}