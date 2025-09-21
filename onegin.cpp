#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

// TODO file struct

void InitStringMatrix(char** data, const size_t size);
void PrintStringMatrix(char** data, const size_t size);
void GetFromFile(char** onegin, FILE* poem, size_t length);
size_t NumLines(const char* filename);
int compare(const void* n1, const void* n2);
void BubbleSort(char** data, size_t length);

int main()
{
    size_t length = NumLines("poem.txt");
    char** sortpoem = (char**)calloc(length, sizeof(char*));


    FILE* poem = fopen("poem.txt", "r");
    assert(poem != NULL);
    GetFromFile(sortpoem, poem, length);

    PrintStringMatrix(sortpoem, length);
    printf("\n");

    //qsort(sortpoem, length, sizeof(sortpoem[-1]), compare);
    BubbleSort(sortpoem, length);

    PrintStringMatrix(sortpoem, length);
    for (size_t i = 0; i < length; i++)
    {
        free(sortpoem[i]);
    }
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

int compare(const void* n1, const void* n2)
{
    const char* s1 = *(const char**)n1;
    const char* s2 = *(const char**)n2;
    return strcmp(s1, s2);
}

// int compare(const void* n1, const void* n2)
// {
//
// }

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
//TODO Bubble Sort
