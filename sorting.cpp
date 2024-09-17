#include "sorting.h"

void bubble_sort(char **arr, int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (compare(arr[j], arr[j + 1]) >= 0) 
            {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int compare (char * a, char* b)
{
    int i = 0;

    char* buf_punkt_a = remove_punctuation(a);
    char* buf_punkt_b = remove_punctuation(b);

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

char* remove_punctuation(const char* input) 
{
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
