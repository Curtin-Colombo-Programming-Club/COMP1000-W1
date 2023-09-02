#ifndef MAP_H
#define MAP_H

char **initMap(int mapSize[2], int pPos[2], int gPos[2]);
void printMap(char **map, int mapSize[2]);
void updateMap(char **map, int mapSize[2], int pPos[2], char input);
int winOrLose(char **map, int mapSize[2], int pPos[2], int gPos[2]);
void freeMap(char **map, int rows);

#endif