#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "sort.h"

int compare(const void* n1, const void* n2)
{
    const char* s1 = *(const char**)n1;
    const char* s2 = *(const char**)n2;
    return strcmp(s1, s2);
}

void BubbleSort(char** data, size_t length)
{

    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < length - i - 1; j++)
        {
            if (strcmp(data[j], data[j + 1]) > 0)
            {
                char* tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}
