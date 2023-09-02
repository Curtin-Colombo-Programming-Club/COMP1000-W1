#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"

char **initMap(int mapSize[2], int pPos[2], int gPos[2])
{
    int Break = 0, row;
    char **map = NULL;

    /* initializing player position */
    pPos[0] = randomUCP(0, mapSize[0] - 1);
    pPos[1] = randomUCP(0, mapSize[1] - 1);

    while (!Break)
    {
        /* initializing player position */
        gPos[0] = randomUCP(0, mapSize[0] - 1);
        gPos[1] = randomUCP(0, mapSize[1] - 1);

        if (pPos[0] != gPos[0] && pPos[1] != gPos[1])
        {
            Break = 1; /* stops the loop */
        }
    }

    map = (char **)malloc(sizeof(char *) * mapSize[0]); /* mallocing for size of rows */

    /* iterating through each row */
    for (row = 0; row < mapSize[0]; row++)
    {
        map[row] = (char *)malloc(sizeof(char) * mapSize[1]); /* mallocing for each row */
        memset(map[row], ' ', sizeof(char) * mapSize[1]);     /* initializing array items to ' ' */
    }

    map[pPos[0]][pPos[1]] = 'P'; /* initializing player position in map */
    map[gPos[0]][gPos[1]] = 'G'; /* initializing goal position in map */

    return map; /* returning map */
}

void printMap(char **map, int mapSize[2])
{
    int row, col, rows, cols;

    /* shifting rows and cols by 2 (for borders ***) */
    rows = mapSize[0] + 2;
    cols = mapSize[1] + 2;

    system("clear"); /* clearing terminal */
    for (row = 0; row < rows; row++)
    {
        /* if border */
        if (row == 0 || row == rows - 1)
        {
            for (col = 0; col < cols; col++)
                printf("*");
            printf("\n");
        }
        else
        {
            printf("*%s*\n", map[row - 1]); /* prints row array */
        }
    }
    /* controls */
    printf("Press w to move up\nPress s to move down\nPress a to move left\nPress d to move right\n");
}

void updateMap(char **map, int mapSize[2], int pPos[2], char input)
{
    int fPos[2], X[2], Break = 0;

    /* updating current player postion -> future position */
    memcpy(fPos, pPos, sizeof fPos);

    /* using switch case to proper computing */
    switch (input)
    {
    case 'w': /* up */
        fPos[0]--;
        break;

    case 's': /* down */
        fPos[0]++;
        break;

    case 'a': /* left */
        fPos[1]--;
        break;

    case 'd': /* right */
        fPos[1]++;
        break;

    default:
        break;
    }

    /* if movable */
    if (fPos[0] >= 0 && fPos[1] >= 0 && fPos[0] < mapSize[0] && fPos[1] < mapSize[1] && map[fPos[0]][fPos[1]] != 'X')
    {
        map[pPos[0]][pPos[1]] = ' '; /* set previuos position to ' ' */
        map[fPos[0]][fPos[1]] = 'P'; /* set current position to 'P' */

        /* updating current position data */
        memcpy(pPos, fPos, sizeof fPos);

        /* breaking a random floor */
        while (!Break)
        {
            /* initializing broken floor position */
            X[0] = randomUCP(0, mapSize[0] - 1);
            X[1] = randomUCP(0, mapSize[1] - 1);

            if (map[X[0]][X[1]] == ' ')
            {
                map[X[0]][X[1]] = 'X';
                Break = 1; /* stops the loop */
            }
        }

        /* printing updated map */
        printMap(map, mapSize);
    }
}

int _isNeighbourBlocked(char **map, int mapSize[2], int pos[2])
{
    /*   if((            above is blocked                  and                      below is blocked                       and              left side is blocked              and                   right side is blocked                    )) */
    return ((pos[0] == 0 || map[pos[0] - 1][pos[1]] == 'X') && (pos[0] == mapSize[0] - 1 || map[pos[0] + 1][pos[1]] == 'X') && (pos[1] == 0 || map[pos[0]][pos[1] - 1] == 'X') && (pos[1] == mapSize[1] - 1 || map[pos[0]][pos[1] + 1] == 'X')) ? 1 : 0;
}

int winOrLose(char **map, int mapSize[2], int pPos[2], int gPos[2])
{
    int re = 0;
    printf("\n%s\n", (char*)pPos);
    /* losing */
    /* if(    player neighbours are blocked     or     goal neighbours are blocked      )*/
    if (_isNeighbourBlocked(map, mapSize, pPos) || _isNeighbourBlocked(map, mapSize, gPos))
    {
        printf("You Lose!\n");
        re = 1;
    }
    else if (pPos[0] == gPos[0] && pPos[1] == gPos[1]) /* winning */
    {
        printf("You Win!\n");
        re = 1;
    }

    return re;
}

void freeMap(char **map, int rows)
{
    int row;

    /* freeing each row */
    for (row = 0; row < rows; row++)
    {
        free(map[row]);
    }

    /* freeing the variable */
    free(map);
}