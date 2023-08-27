#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = NULL; /* int pointer */
    int n;
    int i;

    printf("\033[33mEnter the number of size of int bytes to be allocated in memory: \033[39m");
    scanf(" %d", &n); /* taking user input */

    array = (int *)malloc(sizeof(int) * n); /* mallocing */

    /* initializing the array */
    for (i = 0; i < n; i++)
    {
        array[i] = i+n;
    }

    /* printing the values in array */
    printf("\n\033[36mPrinting items in array:\033[39m\n");
    for (i = 0; i < n; i++)
    {
        printf("\033[35m[%d]\033[39m %d\n", i, array[i]);
    }

    free(array); /* freeing manually allocated memory */

    /* try using valgrind to see if there is any memory leaks */

    return 0;
}