#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "sort.h"

int main(int argc, char **argv)
{
    // TODO enter filename from console/CLI args/local const variable
    const char* filename = "poem.txt";
    poem_t onegin =
    {
        onegin.length = NumLines("poem.txt"),
        onegin.sort_poem = (char**)calloc(onegin.length, sizeof(char*)),
        onegin.file = fopen("poem.txt", "r")
    };
    
    assert(onegin.file != NULL); // use if
    GetFromFile(&onegin);

    PrintStringMatrix(onegin.sort_poem, onegin.length);
    printf("\n");

    if (search_flag(argc, argv, "--qsort"))
    {
        qsort(onegin.sort_poem, onegin.length, sizeof(onegin.sort_poem[-1]), compare);

    }
    if (search_flag(argc, argv, "--bubble"))
    {
        BubbleSort(onegin.sort_poem, onegin.length);
    }
    

    PrintStringMatrix(onegin.sort_poem, onegin.length);
    
    PoemDestroy(&onegin);
    
    fclose(onegin.file);
    return 0;
}