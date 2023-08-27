#include <stdio.h>

int main()
{
    int i = 0;

    /* int arrays */
    int intArray1[5];                  /* Declaring an int array of size 5 */
    int intArray2[] = {1, 2, 3, 4, 5}; /* Declaring an int array and initializing with 5 elements */

    /* char arrays */
    char charArray1[10];                                /* Declaring an char array of size 10 */
    char charArray2[] = "programming club";             /* Declaring an char array and initializing with value "programming club" */
    char charArray3[] = {'c', 'u', 'r', 't', 'i', 'n'}; /* Declaring an char array and initializing with value "curtin" */

    /* debugging */
    printf("\n\033[33m===== DEBUGGING =====\033[39m\n\n");

    /* int arrays */
    /* intArray1 */
    printf("\033[36mElements in intArray1:\033[39m\n");
    for (i = 0; i < 5; i++)
    {
        printf(" \033[35m[%d]\033[39m %d\n", i, intArray1[i]);
    }

    /* intArray2 */
    printf("\n\033[36mElements in intArray2:\033[39m\n");
    for (i = 0; i < 5; i++)
    {
        printf(" \033[35m[%d]\033[39m %d\n", i, intArray2[i]);
    }

    /* char arrays */
    /* charArray1 */
    printf("\n\033[36mElements in charArray1:\033[39m\n");
    for (i = 0; i < 10; i++)
    {
        printf(" \033[35m[%d]\033[39m %c\n", i, charArray1[i]);
    }

    /* charArray2 */
    printf("\n\033[36mElements in charArray2:\033[39m\n");
    for (i = 0; i < 17; i++)
    {
        printf(" \033[35m[%d]\033[39m %c\n", i, charArray2[i]);
    }

    /* charArray3 */
    printf("\n\033[36mElements in charArray3:\033[39m\n");
    for (i = 0; i < 6; i++)
    {
        printf(" \033[35m[%d]\033[39m %c\n", i, charArray3[i]);
    }
    printf("\n");

    return 0;
}