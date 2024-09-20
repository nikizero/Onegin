#include "sorting.h"

void bubble_sort(void *arr, size_t n, size_t el_size, compare_t compare) 
{
    assert(arr);

    for (size_t i = 0; i < n - 1; i++) 
    {
        for (size_t j = 0; j < n - i - 1; j++) 
        {
            if (compare((char*)arr + j*el_size, (char*)arr + (j + 1)*el_size) > 0) 
            {
                void *temp = calloc(el_size, 1);

                if (temp == NULL) 
                {
                    perror("Ошибка выделения памяти");
                    break;
                }

                memcpy(temp, (char*)arr + j*el_size, el_size);
                memcpy((char*)arr + j*el_size, (char*)arr + (j + 1)*el_size, el_size);
                memcpy((char*)arr + (j + 1)*el_size, temp, el_size);
                free(temp);
            }
        }
    }
}

void sort(void *arr, size_t n, size_t el_size, compare_t compare, sorting_t sorting)
{
    assert(arr);

    sorting(arr, n, el_size, compare);
} 

int compare (const void* a_in, const void* b_in)
{
    assert(a_in);
    assert(b_in);

    int i = 0;
    const char *str_a = *(const char **)a_in;
    const char *str_b = *(const char **)b_in;

    char *buf_punkt_a = remove_punctuation(str_a);
    char *buf_punkt_b = remove_punctuation(str_b);


    while (1)
    {
        if ((int) *(buf_punkt_a + i) - (int) *(buf_punkt_b + i) < 0)
        {
            return -1;
        }

        else if (*(buf_punkt_a + i) == *(buf_punkt_b + i))
        {
            i++;
        }

        else if (*(buf_punkt_a + i) == '\n')
        {
            if (*(buf_punkt_b + i) != '\n')
            {
                return -1;
            }

            else if (*(buf_punkt_b + i) == '\n')
            {
                return 0;
            }
        }

        else
        {
            return 1;
        }
    }
}

int compare_from_end (const void* a_in, const void* b_in)
{
    assert(a_in);
    assert(b_in);

    const char *str_a = *(const char **)a_in;
    const char *str_b = *(const char **)b_in;

    char *buf_punkt_a = remove_punctuation(str_a);
    char *buf_punkt_b = remove_punctuation(str_b);
    int i = strlen(buf_punkt_a) - 1;
    int j = strlen(buf_punkt_b) - 1;


    while (1)
    {
        if ((int) *(buf_punkt_a + i) - (int) *(buf_punkt_b + j) < 0)
        {
            return -1;
        }

        else if (*(buf_punkt_a + i) == *(buf_punkt_b + i))
        {
            i--;
            j--;
        }

        else if (i == 0)
        {
            if (j==0)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }

        else
        {
            return 1;
        }
    }
}

char* remove_punctuation(const char* input) 
{
    assert(input);

    size_t len = strlen(input);
    int j = 0; 
    char* new_str = (char*) calloc(len + 1, sizeof(char));

    if (new_str == NULL) 
    {
        perror("Ошибка выделения памяти");
        return NULL;
    }

    for (int i = 0; i < len; i++) 
    {
        if (ispunct((unsigned char)input[i]) == 0) 
        {
            new_str[j++] = input[i];
        }
    }

    new_str[j] = '\0';
    len = strlen(new_str);

    int i = 0;

    while (i < len) 
    {
        *(new_str + i) = tolower((unsigned char) *(new_str + i));
        i++;
    }

    return new_str;
}
