#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

struct poem_t
{
    size_t length = -1;
    char** sort_poem = NULL;
    FILE* file = NULL;
};

void PrintStringMatrix(char** data, const size_t size);
void GetFromFile(poem_t* poem);
size_t NumLines(const char* filename);
void PoemDestroy(poem_t* onegin);
