#include <stdio.h>
#include <stdlib.h>
#include "random.h"

char **initMap(int mapSize[2], int pPos[2], int gPos[2])
{
    int wCon = 1;

    /* initializing player position */
    pPos[0] = randomUCP(0, mapSize[0] - 1);
    pPos[1] = randomUCP(0, mapSize[1] - 1);

    while (dontBreak)
    {
        /* initializing player position */
        gPos[0] = randomUCP(0, mapSize[0] - 1);
        gPos[1] = randomUCP(0, mapSize[1] - 1);

        if (*pRow != *gRow && *pCol != *gCol)
        {
            wCon = 0; /* stops the loop */
        }
    }
}