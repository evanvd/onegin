#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

void InitStringMatrix(char** data, const size_t size);
void PrintStringMatrix(char** data, const size_t size);
void GetFromFile(char** onegin, FILE* poem, size_t length);
size_t NumLines(const char* filename);

int main()
{
    size_t length = NumLines("poem.txt");
    char** sortpoem = (char**)calloc(length, sizeof(char*));


    FILE* poem = fopen("poem.txt", "r");
    assert(poem != NULL);
    GetFromFile(sortpoem, poem, length);

    //qsort(sortpoem, sizeof(poem), )

    PrintStringMatrix(sortpoem, length);
    free(sortpoem);
    fclose(poem);
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

// void InitStringMatrix(char** data, const size_t size)
// {
//     for (size_t index = 0; index < size; index++)
//     {
//         char* temp;
//         scanf("%s",temp);
//         data[index] = strdup(temp);
//     }
// }

void PrintStringMatrix(char** data, const size_t size)
{
    for(size_t index = 0; index < size; index++)
    {
        printf("%s", data[index]);
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

