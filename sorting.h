#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compare (const void* a_in, const void* b_in);
char* remove_punctuation(const char* input);
void bubble_sort(void **arr, int n, size_t el_size, int (*compare)(const void* a_in, const void* b_in));

#endif // SORTING_H