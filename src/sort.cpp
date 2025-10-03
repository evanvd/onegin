#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "sort.h"

int StrcmpComparator(const void* n1, const void* n2)
{
    const char* string1 = *(const char**)n1; 
    const char* string2 = *(const char**)n2; 
    return strcmp(string1, string2);
}

int ReverseStrcmpComparator(const void* n1, const void* n2)
{
    const char* string1 = *(const char**)n1; 
    const char* string2 = *(const char**)n2; 
    const size_t string_len1 = strlen(string1);
    const size_t string_len2 = strlen(string2);

    for (size_t index_str1 = string_len1; index_str1 > 0; index_str1--)
    {
        if((int)string1[index_str1] == (int)string2[string_len2-(string_len1-index_str1)])
        {
            continue;
        }
        return (int)string1[index_str1] - (int)string2[string_len2-(string_len1-index_str1)];
    }
    return 0;
}

void swap(void** string1, void** string2)
{
    void* temp = *string1;
    *string1 = *string2;
    *string2 = temp;
}

void BubbleSort(void** data, size_t length, comparison_fn_t comparator) 
{
    for (size_t attempt = 0; attempt < length - 1; attempt++)
    {
        for (size_t index = 0; index < length - attempt - 1; index++)
        {
            if (comparator(&data[index], &data[index + 1]) > 0)
            {
                swap(&data[index], &data[index + 1]);
            }
        }
    }
}
