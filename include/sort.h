#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "io.h"

int FirstLetterCompare(const void* n1, const void* n2);
int LastLetterCompare(const void* n1, const void* n2);
void BubbleSort(void** data, size_t length, comparison_fn_t comparator); 
void swap(void** string1, void** string2);