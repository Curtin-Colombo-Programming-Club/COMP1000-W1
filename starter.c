#include <stdio.h> /* includes the printf function */

/* main function */
int main()
{
    /* vars */
    int n; /* declaring n */
    n = 1; /* initializing n */
    /* int m = 2; // declaring and initializing m (forbidden by ISO C90) */

    printf("Hello World!\n"); /* printing to the terminal */

    printf("\nProduct (n + 3) = %d\n", n + 3);

    return 0; /* return code 0 indicating execution ran completely without errors or interuptions */
}