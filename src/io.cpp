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

void GetFromFile(poem_t* poem)
{
    size_t buffer_size = 0;
    for (size_t index = 0; index < poem->length; index++)
    {
        getline(&poem->sort_poem[index], &buffer_size, poem->file);
    }
    PoemDup(poem->sort_poem, poem->poem, poem->length);
}

void PoemDup(char** data, char** duplicate, size_t length)
{
    for (size_t index = 0; index < length; index++)
    {
        duplicate[index] = strdup(data[index]);
    }
    
}

poem_err InitPoem(poem_t* data, const char* filename)
{
    data->length = NumLines(filename);
    if (data->length == 0) 
    {
        return BadFilenameErr;
    }
    data->file = fopen("poem.txt","r");
    if (data->file == NULL)
    {
        data->sort_poem = NULL;
        return FileNull;
    }

    data->sort_poem = (char**)calloc(data->length, sizeof(char*));
    data->poem = (char**)calloc(data->length, sizeof(char*));

    return NoErr;
}


size_t NumLines(const char* filename)
{
    FILE* file = fopen(filename, "r");
    assert(file != NULL);
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

void PoemDestroy(poem_t* onegin)
{
    for (size_t i = 0; i < onegin->length; i++)
    {
        free(onegin->sort_poem[i]);
        free(onegin->poem[i]);
    }
    free(onegin->sort_poem);
    free(onegin->poem);
    fclose(onegin->file);
    onegin->file = NULL;    
}

bool SearchFlag(int argc, char** argv, const char* flags)
{
    for (int num_flags = 1; num_flags < argc; num_flags++)
    if (strcmp(argv[num_flags], flags) == 0)
    {
        return true;
    }
    return false;
}