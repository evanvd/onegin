#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "sort.h"

int compare(const void* n1, const void* n2)
{
    const char* string1 = *(const char**)n1; 
    const char* string2 = *(const char**)n2; 
    return strcmp(string1, string2);
}

void swap(void** string1, void** string2)
{
    void* temp = *string1;
    *string1 = *string2;
    *string2 = temp;
}

void BubbleSort(void** data, size_t length, comparison_fn_t __compar) 
{
    
    for (size_t attempt = 0; attempt < length - 1; attempt++)
    {
        for (size_t index = 0; index < length - attempt - 1; index++)
        {

            if (__compar(&data[index], &data[index + 1]) > 0)
            {
                swap(&data[index], &data[index + 1]);
            }
        }
    }
}

