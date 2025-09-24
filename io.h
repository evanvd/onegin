#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

struct file
{
    size_t length = -1;
    char** sort_poem = {};
};

void PrintStringMatrix(char** data, const size_t size);
void GetFromFile(char** onegin, FILE* poem, size_t length);
size_t NumLines(const char* filename);
void PoemDestroy(file onegin);
