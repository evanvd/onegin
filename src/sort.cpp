#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "sort.h"

int compare(const void* n1, const void* n2)
{
    const char* string1 = *(const char**)n1; // TODO rename
    const char* string2 = *(const char**)n2; // TODO rename
    return strcmp(string1, string2);
}

void swap(char** string1, char** string2)
{
    char* temp = *string1;
    *string1 = *string2;
    *string2 = temp;
}

void BubbleSort(char** data, size_t length)
{

    for (size_t attempt = 0; attempt < length - 1; attempt++)
    {
        for (size_t index = 0; index < length - attempt - 1; index++)
        {
            if (strcmp(data[index], data[index + 1]) > 0)
            {
                swap(&data[index], &data[index + 1]);
            }
        }
    }
}

