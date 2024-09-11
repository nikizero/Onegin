#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

FILE * open_file (const char * file);
size_t size_file(FILE* file, int mode);
size_t how_man_str (FILE* file);
char** write_oneg(FILE * file);

int main()
{
    const char *name_file = "onegin.txt";
    FILE* file= open_file(name_file);

    fseek(file, 0, SEEK_SET);

    char** chars = write_oneg(file);
    if (chars == NULL) 
    {
        fclose(file);
        return 1; // Ошибка записи строк
    }
    
    int i = 0;
    while (chars[1][i] != '\0')  //почему выводится весь файл а не i строчка, будто \0 нет в строке
    {
        printf("%c", chars[1][i]);
        i++;
    }

    fclose(file);
    free (*chars);
    free (chars);
    return 0;
}

FILE * open_file (const char * name_file)
{
    FILE *file = fopen(name_file, "r");
    if (file == NULL) 
    {
        perror("Ошибка открытия файла 1!\n");
        return 0;
    }
    return file;
}

size_t size_file(FILE* file, int mode)
{    
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
        return how_man_str (file);
    }
    return 0;
}

size_t how_man_str (FILE* file)
{
{
    size_t i = 0;
    char buffer[100]; 

    while (fgets(buffer, sizeof(buffer), file))
    {
        i++;
    }
    
    return i + 1;
}

}

char** write_oneg(FILE * file)
{
    char * all_strings = (char *) calloc(size_file(file, 0), 1); //здесь хранятся все строки
    int num_of_char = 0;
    int num_of_string = 1;
    char ** str_adr = (char **) calloc(size_file(file, 1), sizeof(char *)); //здесь хранятся указатели на начала строк

    *str_adr = all_strings;
    fseek(file, 0, SEEK_SET);

    char * adr_of_char = all_strings + num_of_char;

    while(1)
    {
        adr_of_char = all_strings + num_of_char;
        *(adr_of_char) = fgetc(file);
        if (*(adr_of_char) == '\n')
        {
            adr_of_char ++;
            *(adr_of_char) = '\0';
            *(str_adr + num_of_string) = adr_of_char;
            num_of_string++;
        }
        else if (*(adr_of_char) == EOF)
        {
            break;
        }
        num_of_char++;
    }
    return str_adr;
}
// abcdefg/0afiakckok/0aslfoclo/0