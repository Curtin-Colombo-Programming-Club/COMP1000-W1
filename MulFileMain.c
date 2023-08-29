/* this file contains main function for the multiple files example */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "MulFileMath.h"
#include "MulFileStr.h"

int main()
{
    int a = 2, b = 9, input;

    srand(time(NULL));

    printf("a + b = %d\n", add(a, b));

    printf("a * b = %d\n", mul(a, b));

    printf("Enter length of random string to generate: ");
    scanf(" %d", &input);
    randStr((size_t)input);

    return 0;
}