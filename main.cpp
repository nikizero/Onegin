#include "file_proc.cpp"
#include "sorting.cpp"

// fread 
// fwrite

// struct String {
//  char* str;
//  size_t len;
// }

// открыли файл и узнали размер                                        +
// выделили динамически buffer на размер файла // buffer = str\nstr2\n +
// берем и меняем \n на \0 и считаем колво \n // buffer = str\0str2\0  +
// выделил память char** adr = calloc (size = колво \n)                +
// while не \0 -> просто i++, как только встретили записали указатель на следующий элемент +

// два компаратора, слева направо и справа налево
// две сортировки свои и стандартный qsort (начать с него)

// добавить в папку data сортируемые файлы и выходной файл

// ПОТОМ:
// еще нужно структуру добавить, которая хранит char* и ее длину (5 пункт)

int main() 
{
    int hms = 0;
    const char *name_file = "onegin.txt";
    FILE *file = open_file(name_file);

    char** chars = write_oneg(file, &hms);
    if (chars == NULL) 
    {
        fclose(file);
        return 1;
    }
    
    printf("%s \n", chars[0]);
    bubble_sort(chars, hms);
    printf("%s \n", chars[0]);

    fclose(file);
    free(chars);
    return 0;
}