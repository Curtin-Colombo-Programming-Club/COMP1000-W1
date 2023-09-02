#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "terminal.h"
#include "map.h"

int argParser(int argc, char **argv, int mapSize[2]);

int main(int argc, char **argv)
{
    int mapSize[2], pPos[2], gPos[2], playing = 1;
    char **map, input;

    if (argParser(argc, argv, mapSize))
    {
        initRandom(); /* initializing random */

        map = initMap(mapSize, pPos, gPos); /* initializing map */

        printMap(map, mapSize); /* printing initial map */

        while (playing)
        {
            /* getting user input */
            disableBuffer();
            scanf(" %c", &input);
            enableBuffer();

            /* updating map */
            updateMap(map, mapSize, pPos, input);

            /* chck playing conditions and updating */
            playing = !winOrLose(map, mapSize, pPos, gPos);
        }

        /* free map */
        freeMap(map, mapSize[0]);
    }

    return 0;
}

int argParser(int argc, char **argv, int mapSize[2])
{
    int re = 0; /* return value */

    if (argc != 3) /* if argument count isnt 3 */
    {
        printf("Not enough arguments!\n");
    }
    else if (atoi(argv[1]) < 5 || atoi(argv[2]) < 5) /* if map rows or map cols less than 5 */
    {
        printf("Number of map rows and map columns cannot be less than 5\n");
    }
    else if (atoi(argv[1]) % 2 != 0 || atoi(argv[2]) % 2 != 0) /* if map rows or map cols not even */
    {
        printf("Number of map rows and map columns should be even\n");
    }
    else
    {
        /* initializing map data */
        mapSize[0] = atoi(argv[1]);
        mapSize[1] = atoi(argv[2]);

        re = 1;
    }
    return re;
}