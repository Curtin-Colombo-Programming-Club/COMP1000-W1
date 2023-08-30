#ifndef MAP_H
#define MAP_H

void createPlayerGoalPos(int *pRow, int *pCol, int *gRow, int *gCol, int rows, int cols);
void createMap(char **map, int rows, int cols, int pRow, int pCol, int gRow, int gCol);
void printMap(char **map, int rows, int cols);
void movePlayer(char **map, int rows, int cols, int fRow, int fCol, int pRow, int pCol);
void breakFloor(char **map, int rows, int cols);
void freeMap(char **map, int rows);

#endif