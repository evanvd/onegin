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
    case ERR:
        return 0;
    default:
        break;
    }

    GetFromFile(&onegin);

    PrintStringMatrix(onegin.sort_poem, onegin.length);
    printf("\n\n\n\n");

    if (SearchFlag(argc, argv, "--qsort"))
    {
        qsort(onegin.sort_poem, onegin.length, sizeof(onegin.sort_poem[-1]), compare);

    }
    if (SearchFlag(argc, argv, "--bubble"))
    {
        BubbleSort(onegin.sort_poem, onegin.length);
    }
    

    PrintStringMatrix(onegin.sort_poem, onegin.length);
    
    PoemDestroy(&onegin);
    
    fclose(onegin.file);
    return 0;
}