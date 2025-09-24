#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
//#include "io.h"
#include "sort.h"



int main()
{
    //size_t length = NumLines("poem.txt");
    file onegin;
    
    onegin.length = NumLines("poem.txt");
    onegin.sort_poem = (char**)calloc(onegin.length, sizeof(char*));

    FILE* poem = fopen("poem.txt", "r");
    assert(poem != NULL);
    GetFromFile(onegin.sort_poem, poem, onegin.length);

    PrintStringMatrix(onegin.sort_poem, onegin.length);
    printf("\n");

    //qsort(sortpoem, length, sizeof(sortpoem[-1]), compare);
    BubbleSort(onegin.sort_poem, onegin.length);

    PrintStringMatrix(onegin.sort_poem, onegin.length);
    
    PoemDestroy(onegin);

    fclose(poem);
    return 0;
}

