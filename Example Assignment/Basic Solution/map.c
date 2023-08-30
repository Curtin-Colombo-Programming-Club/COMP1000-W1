#include <stdio.h>
#include <stdlib.h>
#include "random.h"

void createPlayerGoalPos(int *pRow, int *pCol, int *gRow, int *gCol, int rows, int cols)
{
    int dontBreak = 1;

    /* initializing player position */
    *pRow = randomUCP(0, rows - 1);
    *pCol = randomUCP(0, cols - 1);

    while (dontBreak)
    {
        /* initializing player position */
        *gRow = randomUCP(0, rows - 1);
        *gCol = randomUCP(0, cols - 1);

        if (*pRow != *gRow && *pCol != *gCol)
        {
            dontBreak = 0; /* stops the loop */
        }
    }
}

void createMap(char **map, int rows, int cols, int pRow, int pCol, int gRow, int gCol)
{
    int i;
    int j;

    /* mallocing for each row */
    for (i = 0; i < rows; i++)
    {
        map[i] = (char *)malloc(sizeof(char) * cols);
    }

    /* initializing map */
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (i == pRow && j == pCol)
            {
                map[i][j] = 'P';
            }
            else if (i == gRow && j == gCol)
            {
                map[i][j] = 'G';
            }
            else
            {
                map[i][j] = ' ';
            }
        }
    }
}

void printMap(char **map, int rows, int cols)
{
    int i;
    int j;

    system("clear");
    for (i = 0; i < rows + 2; i++)
    {
        for (j = 0; j < cols + 2; j++)
        {
            if (i == 0 || j == 0 || i == rows + 1 || j == cols + 1)
            {
                printf("*");
            }
            else
            {
                printf("%c", map[i - 1][j - 1]);
            }
        }
        printf("\n");
    }
    printf("Press w to move up\n");
    printf("Press s to move down\n");
    printf("Press a to move left\n");
    printf("Press d to move right\n");
}

void movePlayer(char **map, int rows, int cols, int fRow, int fCol, int pRow, int pCol)
{
    map[pRow][pCol] = ' ';
    map[fRow][fCol] = 'P';
}

void breakFloor(char **map, int rows, int cols)
{
    /* broken floor data */
    int xRow;
    int xCol;

    /* while loop condition */
    int dontBreak = 1;

    while (dontBreak)
    {
        /* initializing broken floor position */
        xRow = randomUCP(0, rows - 1);
        xCol = randomUCP(0, cols - 1);

        if (map[xRow][xCol] == ' ')
        {
            map[xRow][xCol] = 'X';
            dontBreak = 0; /* stops the loop */
        }
    }
}

void freeMap(char **map, int rows)
{
    int i;

    for (i = 0; i < rows; i++)
    {
        free(map[i]);
    }

    free(map);
}