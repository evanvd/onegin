#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "io.h"

void PrintStringMatrix(char** data, const size_t size)
{
    for(size_t index = 0; index < size; index++)
    {
        printf("%s", data[index]);
    }
}

void GetFromFile(char** onegin, FILE* poem, size_t length)
{
    size_t buffer_size = 0;
    for (size_t index = 0; index < length; index++)
    {
        getline(&onegin[index], &buffer_size, poem);
        //onegin[index] = strdup(temp);
    }
}

size_t NumLines(const char* filename)
{
    FILE* file = fopen(filename, "r");
    int ch = 0;
    size_t lines = 0;
    while((ch = fgetc(file)) != EOF)
    {
        if(ch == '\n')
        {
            lines++;
        }
    }
    fclose(file);
    return lines;
}

void PoemDestroy(file onegin)
{
    for (size_t i = 0; i < onegin.length; i++)
    {
        free(onegin.sort_poem[i]);
    }
}