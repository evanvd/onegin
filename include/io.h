#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

struct poem_t
{
    size_t length = 0;
    char** poem = NULL;
    char** sort_poem = NULL;
    FILE* file = NULL;
};

enum poem_err
{
    BadFilenameErr = 0, // TODO what is that?
    NoErr = -1,
    FileNull = 1,
};

poem_err InitPoem(poem_t* data, const char* filename);
void PrintStringMatrix(char** data, const size_t size);
void GetFromFile(poem_t* poem);
size_t NumLines(const char* filename);
void PoemDestroy(poem_t* onegin);
bool SearchFlag(int argc, char** argv, const char* flags);
