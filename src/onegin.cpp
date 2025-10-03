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
        printf("BadFilename");
        return 0;
    case NoErr:
        break;
    default:
        break;
    }

    GetFromFile(&onegin);


    comparison_fn_t compare = StrcmpComparator;

    qsort(onegin.sort_poem, onegin.length, sizeof(onegin.sort_poem[-1]), compare);
    
    PrintStringMatrix(onegin.sort_poem,onegin.length);

    compare = ReverseStrcmpComparator;

    BubbleSort((void**)onegin.sort_poem, onegin.length, compare); 

    printf("\n\nREVERSE SORT\n\n");    
    PrintStringMatrix(onegin.sort_poem, onegin.length);
    
    printf("\n\nRAW\n\n");

    PrintStringMatrix(onegin.poem, onegin.length);
    PoemDestroy(&onegin);
    return 0;
}