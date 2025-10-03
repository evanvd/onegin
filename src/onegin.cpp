#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "sort.h"

int main(int argc, char **argv)
{
    const char* filename = "poem.txt";
    
    poem_t onegin = {};
    poem_err err = InitPoem(&onegin, filename);

    switch (err)
    {
    case FileNull:
        printf("FileNull");
        return 0;
    case BadFilenameErr:
        return 0; // TODO print error
    case NoErr:
        break;
    default:
        break;
    }

    GetFromFile(&onegin);

    PrintStringMatrix(onegin.sort_poem, onegin.length);
    printf("\n\n\n\n");

    comparison_fn_t compare = StrcmpComparator;

    qsort(onegin.sort_poem, onegin.length, sizeof(onegin.sort_poem[-1]), compare);

    compare = ReverseStrcmpComparator;

    PrintStringMatrix(onegin.sort_poem,onegin.length);

    BubbleSort((void**)onegin.sort_poem, onegin.length, compare); 

    PrintStringMatrix(onegin.sort_poem, onegin.length);
    
    PrintStringMatrix(onegin.poem, onegin.length);
    PoemDestroy(&onegin);
    // TODO print(sorted)
    return 0;
}