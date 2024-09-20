#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

typedef int (*compare_t)(const void* a_in, const void* b_in);
typedef void (*sorting_t)(void *arr, size_t n, size_t el_size, compare_t compare);

int compare (const void* a_in, const void* b_in);
int compare_from_end (const void* a_in, const void* b_in);
char* remove_punctuation(const char* input);

void sort(void *arr, size_t n, size_t el_size, compare_t compare, sorting_t sorting);
void bubble_sort(void *arr, size_t n, size_t el_size, compare_t compare) ;

#endif 