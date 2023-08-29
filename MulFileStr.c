/* this file has a string genarator functions */
#include <stdio.h>
#include <stdlib.h>
#include "MulFileStr.h"

/* initialization of the function randStr */
void randStr(size_t size)
{
    int key;
    size_t n;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size)
    {
        for (n = 0; n < size; n++)
        {
            key = rand() % (int)(sizeof charset - 1);
            printf("%c", charset[key]);
        }
        printf("\n");
    }
}