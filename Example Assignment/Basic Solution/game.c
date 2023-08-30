#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "terminal.h"
#include "map.h"

int main(int argc, char **argv)
{
    int playing = 1; /* for while loop */

    char input; /* for user input */

    /* map data */
    int mapCols;
    int mapRows;
    char **map = NULL;

    /* player data */
    int pRow;
    int pCol;

    /* tmp data */
    int fRow;
    int fCol;

    /* goal data */
    int gRow;
    int gCol;

    /* argument checking */
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
        initRandom(); /* initiaing random */

        /* initializing map size vars */
        mapRows = atoi(argv[1]);
        mapCols = atoi(argv[2]);

        /* initializing player and goal positions */
        createPlayerGoalPos(&pRow, &pCol, &gRow, &gCol, mapRows, mapCols);

        /* creating initial map array for size of map rows */
        map = (char **)malloc(sizeof(char *) * mapRows);
        /* initializing map */
        createMap(map, mapRows, mapCols, pRow, pCol, gRow, gCol);

        /* first map print */
        printMap(map, mapRows, mapCols);

        while (playing)
        {
            disableBuffer();
            scanf(" %c", &input); /* getting user input */
            enableBuffer();

            /* updating tmp data */
            fRow = pRow;
            fCol = pCol;

            /* updating tmp data according to user input */
            if (input == 'w')
            {
                fRow--;
            }
            else if (input == 's')
            {
                fRow++;
            }
            else if (input == 'a')
            {
                fCol--;
            }
            else if (input == 'd')
            {
                fCol++;
            }

            /* checking if movable */
            if (fRow >= 0 && fCol >= 0 && fRow < mapRows && fCol < mapCols && (map[fRow][fCol] == ' ' || map[fRow][fCol] == 'G'))
            {
                movePlayer(map, mapRows, mapCols, fRow, fCol, pRow, pCol); /* moving player in the map */
                breakFloor(map, mapRows, mapCols);                         /* breaking random floor */

                /* updating data */
                pRow = fRow;
                pCol = fCol;

                /* printing map */
                printMap(map, mapRows, mapCols);
            }

            /* while loop end condition */
            /* losing */
            /* if((        player above is blocked        and              player below is blocked               and       player left side is blocked        and            player right side is blocked            ) or (          goal above is blocked          and               goal below is blocked                and        goal left side is blocked         and            goal right side is blocked            ))*/
            if (((pRow == 0 || map[pRow - 1][pCol] == 'X') && (pRow == mapRows - 1 || map[pRow + 1][pCol] == 'X') && (pCol == 0 || map[pRow][pCol - 1] == 'X') && (pCol == mapCols - 1 || map[pRow][pCol + 1] == 'X')) || ((gRow == 0 || map[gRow - 1][gCol] == 'X') && (gRow == mapRows - 1 || map[gRow + 1][gCol] == 'X') && (gCol == 0 || map[gRow][gCol - 1] == 'X') && (gCol == mapCols - 1 || map[gRow][gCol + 1] == 'X')))
            {
                printf("You Lose!\n");
                playing = 0;
            }
            else if (pRow == gRow && pCol == gCol) /* winning */
            {
                printf("You Win!\n");
                playing = 0;
            }
        }

        freeMap(map, mapRows);
    }

    return 0; /* return code success */
}