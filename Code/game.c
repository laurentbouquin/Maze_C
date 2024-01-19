#include "game.h"





char XM = '\0';
char XP = '\0';
char YM = '\0';
char YP = '\0';

bool DEBUG = false;

int keys = 0;
int money = 5;
bool showStats = true;


bool trade = false;



chest_t chestKey = {false, 20};
chest_t chestOne = {false, 10};
chest_t chestTwo = {false, 10};
chest_t chestThree = {false, 10};
chest_t chestFour = {false, 5};
chest_t chestFive = {false, 10};
chest_t chestSix = {false, 10};
chest_t chestSeven = {false, 10};
chest_t chestEight = {false, 10};
chest_t chestNine = {false, 10};
chest_t chestTen = {false, 10};


int X = 9;
int Y = 17;

int main()
{
	char mov = ' ';
	printMaze(X, Y);
	while (mov != 'a')
	{
		mov = keyPressed();
		printf("%c\n", mov);
		
		system("cls");
		switch (mov)
		{
		case 'z':
			if (X > 9 && (XM == ' ' || XM == '\0')){
				X--;
			}
			else if (X <= 9){
				X = 9;
			}
			break;
		case 's':
			if (X < 80 && (XP == ' ' || XP == '\0')){
				X++;
			}
			else if (X >= 80){
				X = 80;
			}
			break;
		case 'q':
			if (Y > 10 && (YM == ' ' || YM == '\0')){
				Y-=2;
			}
			else if (Y <= 9){
				Y = 9;
			}
			break;
		case 'd':
			if (Y < 142 && (YP == ' ' || YP == '\0')){
				Y+=2;
			}
			else if (Y >= 142){
				Y = 140;
			}
			break;
		case 'i':
			money += 100;
			break;
		case 'e':
			if (XM == 'C' || XP == 'C' || YM == 'C' || YP == 'C'){
				if ((X >= 66 && X <= 68 && Y >= 21 && Y <= 25) && chestKey.open == false){
					getChestContent(&chestKey);
					money += chestKey.content;
					keys++;
				}
				else if ((X >= 44 && X <= 46 && Y >= 37 && Y <= 41) && chestOne.open == false){
					getChestContent(&chestOne);
					money += chestOne.content;
				}
				else if ((X >= 20 && X <= 24 && Y >= 33 && Y <= 41) && chestTwo.open == false){
					getChestContent(&chestTwo);
					money += chestTwo.content;
				}
				else if (( X == 23 && Y == 69 ) && chestThree.open == false){
					getChestContent(&chestThree);
					money += chestThree.content;
				}
				else if ((X >= 44 && X <= 46 && Y >= 37 && Y <= 41) && chestFour.open == false){
					getChestContent(&chestFour);
					money += chestFour.content;
				}
				else if ((X >= 56 && X <= 60 && Y >= 123 && Y <= 131) && chestFive.open == false){
					getChestContent(&chestFive);
					money += chestFive.content;
				}
				else if ((X >= 60 && X <= 66 && Y >= 93 && Y <= 105) && chestSix.open == false){
					getChestContent(&chestSix);
					money += chestSix.content;
				}
				else if ((X >= 62 && X <= 66 && Y >= 53 && Y <= 61) && chestSeven.open == false){
					getChestContent(&chestSeven);
					money += chestSeven.content;
				}
				else if ((X >= 11 && Y == 131 ) && chestEight.open == false){
					getChestContent(&chestEight);
					money += chestEight.content;
				}
				else if ((X >= 48 && Y == 127) && chestNine.open == false){
					getChestContent(&chestNine);
					money += chestNine.content;
				}
				else if ((X >= 24 && X <= 26 && Y >= 81 && Y <= 85) && chestTen.open == false){
					getChestContent(&chestTen);
					money += chestTen.content;
				}

			}
			else if (YP == 'T'){
				tradeKey();
			}
		case 'p':
			saveGame();
			break;
		case 'l':
			loadGame();
			break;
		case ' ':
			break;
		default:
			// printf("input: %c\n", mov);
			// printMaze(X, Y);
			break;
		}
		printMaze(X, Y);
		if (DEBUG){
			printf("XM:%c; XP:%c; YM:%c; YP:%c\n", XM, XP, YM, YP);
			printf("X:%d; Y:%d\n", X, Y);
			printf("trade: %s\n", trade ? "true" : "false");
		}
	}
	return 0;
}




void *printMaze(int locationX, int locationY)
{	

	int i;
	int j;
	if (locationX < 7)
	{
		i = 0;
	}
	else 
	{
		i = locationX - 7;
	}
	if (locationY < 14)
	{
		j = 0;
	}
	else 
	{
		j = locationY - 14;
	}



	FILE *fp;
	fp = fopen("./maze", "r");
	
	if (fp == NULL)
	{
		perror("Error opening file");
		// printf("File does not exist.\n");
		// exit(EXIT_FAILURE);
	}
	else
	{
		char ch;
		int lineNum = 0;
		int charNum = 0;
		while ((ch = fgetc(fp)) != EOF)
		{
			if (ch != '\n'){
				if (lineNum >= i && lineNum <= i + 14){
					if (charNum >= j && charNum <= j + 29){
						if (lineNum == locationX && charNum == locationY+2){
							printf("\033[1;35m%s\033[0m", "$$");
							ch = '\0';
						}
						else if (lineNum == locationX && charNum == locationY+1){
							ch = '\0';
						}
						else if (lineNum == locationX-1 && charNum == locationY+2){
							printMazeChar(ch, lineNum, charNum);
							XM = ch;
						}
						else if (lineNum == locationX+1 && charNum == locationY+2){
							printMazeChar(ch, lineNum, charNum);
							XP = ch;
						}
						else if (lineNum == locationX && charNum == locationY){
							printMazeChar(ch, lineNum, charNum);
							YM = ch;
						}
						else if (lineNum == locationX && charNum == locationY+4){
							printMazeChar(ch, lineNum, charNum);
							YP = ch;
						}
						else if (ch != '\0' && ((lineNum != 25 && charNum != 29) || (lineNum != 25 && charNum != 28)))
						{
							printMazeChar(ch, lineNum, charNum);
						}
						else if (ch != '\0' && ((lineNum == 25 && charNum != 29) || (lineNum == 25 && charNum != 28)))
						{
							printMazeChar(ch, lineNum, charNum);
						}
						// Special event's locations and actions
						if (((locationY >= 65 && locationY <= 81 ) && (locationX >= 30 && locationX <= 32))){
							system("cls");
							if (keys == 2){
								printf("You have enough keys to open the door.\n");
								printf("You win!\n");
								printMenu(true);
								exit(EXIT_SUCCESS);
							}
							else {
								printf("You don't have enough keys to open the door.\n");
								X -=1;
								break;
							}
						}
					}
				}
				charNum++;
			}
			else if (ch != '\n' && charNum == 0){
				charNum++;
			}
			else if (ch == '\n'){
				if (lineNum >= i && lineNum <= i + 14){
						printf("\n");
				}
				lineNum++;
				charNum = 0;
			}
		}
	}
	if (showStats){
		printStats();
	}
	fclose(fp);
}


char keyPressed(){
	
    int ch;
    clock_t start_time = clock();
    const int timeout = 60000;  // Timeout in milliseconds

    while ((clock() - start_time) < timeout) {
        if (_kbhit()) {
            // Key pressed
            ch = _getch();
			if (DEBUG){
				printf("Key pressed: %c\n", ch);
			}
			return ch;
            break;
        }

        // Add a small delay to avoid high CPU usage
        Sleep(10);
    }

    if ((clock() - start_time) >= timeout) {
        // Timeout reached, no key pressed
		if (DEBUG){
			printf("No key pressed within 1 minute.\n");
		}
		return ' ';
    }
}



void printMenu(bool isVictory){
	FILE *fp;
	if (isVictory){
		fp = fopen("./victory", "r");
	}
	else {
		fp = fopen("./gameOver", "r");
	}
		if (fp == NULL)
		{
			printf("File does not exist.\n");
			exit(EXIT_FAILURE);
		}
		else 
		{
			char ch;
			while ((ch = fgetc(fp)) != EOF){
				if (ch == '#'|| ch == '\''){
					printf("\033[1;36m%c\033[0m", ch);
				}
				else {
					printf("\033[1;31m%c\033[0m", ch);
				}
			}
		}
}


void printMazeChar(char character, int X , int Y)
{
	if (character == '#'){
		printf("\033[1;34m%c\033[0m", character);
	}
	else if (character == '='){
		printf("\033[1;32m%c\033[0m", character);
	}
	else if (character == '|'){
		printf("\033[1;32m%c\033[0m", character);
	}
	else if (character == '*'){
		printf("\033[1;30m%c\033[0m", character);
	}
	else if ((character == 'L' || character == 'C')){
		printf("\033[1;33m%c\033[0m", character);
	}
	else if ((character == 'K' || character == 'T')){
		printf("\033[1;36m%c\033[0m", character);
	}
	else{
		printf("%c", character);
	}
}


void printStats(){
	printf("\033[1;35mKeys: ");
	printf("\033[1;34m%d\033[0m\n", keys);
	printf("\033[1;35mMoney: ");
	printf("\033[1;34m%d gold coins\033[0m\n", money);
}


int getChestContent(chest_t *chest){
	chest->open = true;
	return chest->content;
}

void tradeKey(){
	if (money >= 100){
		money -= 100;
		keys++;
		trade = true;
	} else {
		printf("You don't have enough money.\n");
		printf("You need 100 gold coins to trade for a key.\n");
	}
}


void saveGame(){
	FILE *fp;
	fp = fopen("./save", "w");

	fprintf(fp, "%d\n", X);
	fprintf(fp, "%d\n", Y);
	fprintf(fp, "%d\n", keys);
	fprintf(fp, "%d\n", money);
	fprintf(fp, "%d\n", trade);
	fprintf(fp, "%d\n", chestKey.open);
	fprintf(fp, "%d\n", chestOne.open);
	fprintf(fp, "%d\n", chestTwo.open);
	fprintf(fp, "%d\n", chestThree.open);
	fprintf(fp, "%d\n", chestFour.open);
	fprintf(fp, "%d\n", chestFive.open);
	fprintf(fp, "%d\n", chestSix.open);
	fprintf(fp, "%d\n", chestSeven.open);
	fprintf(fp, "%d\n", chestEight.open);
	fprintf(fp, "%d\n", chestNine.open);
	fprintf(fp, "%d\n", chestTen.open);

	fclose(fp);

}

void loadGame(){
	FILE *fp;
	fp = fopen("./save", "r");
}