#include"util.h"

size_t how_man_str (char *all_chars)
{
    assert(all_chars);

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

void printing(int hms, char** chars)
{
    for (int i = 0; i < hms; i++)
    {
        if (chars[i][0] != EOF)
        {
            printf("%s \n", chars[i]);
        }
    }
}