#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>



typedef struct chest{
	bool open;
	int content;
}chest_t;


void *printMaze(int locationX, int locationY);

void printMenu(bool isVictory);

void printMazeChar(char character, int X , int Y);

char keyPressed();

void printStats();

bool contains(int *arr, int *arr2, int X, int Y);

int getChestContent(chest_t *chest);

void tradeKey();

void saveGame();

void loadGame();

int chestState(chest_t *chest, bool state);