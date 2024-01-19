#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>




char getInput(){
	
    int ch;
    clock_t start_time = clock();
    const int timeout = 60000;  // Timeout in milliseconds

    while ((clock() - start_time) < timeout) {
        if (_kbhit()) {
            // Key pressed
            ch = _getch();
			return ch;
            break;
        }

        // Add a small delay to avoid high CPU usage
        Sleep(10);
    }

    if ((clock() - start_time) >= timeout) {
        // Timeout reached, no key pressed
		printf("No key pressed within 1 minute.\n");
		return ' ';
    }
}



int showRules(){
	int coins = 0;
	char choice;
	Sleep(500);
	printf("##=====================================================================================================================================##\n");
	printf("You fell in a maze and now want to get out of here.                                                                                    ||\n");
	printf("You chech your surroundings and see something written                                                                                  ||\n");
	Sleep(1500);
	printf("##=====================================================================================================================================##\n");
	printf("\"This an ancient maze where there is only one way out.\"                                                                                ||\n");
	printf("...                                                                                                                                    ||\n");
	Sleep(1500);
	printf("You may be able to get out of here if find the room where lies an ancient telepoter.                                                   ||\n");
	printf("##=====================================================================================================================================##\n");
	Sleep(1500);
	printf("What do you want to do?                                                                                                                ||\n");
	printf("You seem to start panicking, and only have two choices left.                                                                           ||\n");
	printf("1. Try to calm yourself.                                                                                                               ||\n");
	printf("2. PANICK!!!                                                                                                                           ||\n");
	printf("##=====================================================================================================================================##\n");
	choice:
	choice = getInput();
	switch (choice){
		case '1':
			printf("You try to calm yourself.                                                                                                              ||\n");
			printf("...                                                                                                                                    ||\n");
			Sleep(1500);
			printf("It works.                                                                                                                              ||\n");
			Sleep(1500);
			printf("You seem in abetter shape than earlier.                                                                                                ||\n");
			printf("##=====================================================================================================================================##\n");
			Sleep(1500);
			printf("You concentrate on the writing and you notice that it says that you may need to find or BUY items in the maze.                         ||\n");
			Sleep(2000);
			printf("You see that a part of the wall seem half broken...                                                                                    ||\n");
			printf("##=====================================================================================================================================##\n");
			Sleep(1500);
			printf("What do you do?                                                                                                                        ||\n");
			printf("1. Nothing. It should not be important.                                                                                                ||\n");
			printf("2. Try to break the wall.                                                                                                              ||\n");
			printf("3. Cry for help.                                                                                                                       ||\n");
			printf("##=====================================================================================================================================##\n");

			choice2:
			choice = getInput();
			switch (choice){
				case '1':
					printf("You decide to ignore it and go into the maze.                                                                                          ||\n");
					printf("##=====================================================================================================================================##\n");
				break;
				case '2':
					printf("You try to break the wall and it works.                                                                                                ||\n");
					Sleep(1500);  
					printf("You see a chest and open it.                                                                                                           ||\n");
					Sleep(1500);
					printf("You find 5 gold coins and a note.                                                                                                      ||\n");
					coins = 5;
					printf("##=====================================================================================================================================##\n");
					Sleep(1500);
					printf("The note says that you can trade the coins for a key.                                                                                  ||\n");
					Sleep(1500);
					printf("A part of the note seem partially erased.                                                                                              ||\n");
					Sleep(1500);
					printf("\"Y.. .an e..han.e ..0 g..d c.i.. ..r . k.., ... h...ng ..o k.ys a.l.ws .ou .o t.k. t.e t...p.rt..r\"                                    ||\n");
					printf("##=====================================================================================================================================##\n");
					Sleep(1500);
					printf("You decide to keep the coins and start this new journey into this maze.                                                                ||\n");
					Sleep(2000);
				break;
				case '3':
					printf("You cry for longer that you will ever admit but decide to bypass it and go into the maze.                                              ||\n");
					printf("##=====================================================================================================================================##\n");
				break;
				default: 
					printf("Please select a valid choice!                                                                                                          ||\n");
					goto choice2; 
				break;
			}


			
			Sleep(2000);

			printf("You start walking around the maze and then...                                                                                          ||\n");
			Sleep(1500);
			printf("A voice rises frome the deepest part of the maze.                                                                                      ||\n");
			Sleep(1500);
			printf("\"Find gold coins in the Loot Chests (LC) and find the Key trader (KT).\"                                                              ||\n");
			Sleep(2000);
			printf("Then you may be able to get out...                                                                                                     ||\n");
			Sleep(1500);
			printf("IF YOU ARE LUCKY!                                                                                                                      ||\n");
			printf("##=====================================================================================================================================##\n");
			Sleep(1000);
			printf("Move using Z: up / Q: left / S: down / D: right / P: Save / L: load                                                                    ||\n");
			printf("Press any key to start!\n");
			Sleep(1000);
			char key = getInput();
			switch (key)
			{			
			default:
				printf("GOOOOO!!!!!\n");
				Sleep(1500);
				break;
			}
			system("cls");
			if (coins == 0){
				return 2;
			}
			else {
				return 1;
			}


			break;
		case '2':
			printf("You start panicking and run around the maze.                                                                                           ||\n");
			printf("##=====================================================================================================================================##\n");
			printf("After some hours, you are so tired that you close your eyes... Forever.                                                                ||\n");
			Sleep(2000);
			printf("##=====================================================================================================================================##\n");
			return 0;
			break;
		default:
			printf("Please select a valid choice!\n");
			goto choice;
			break;
	}
}




// Show menu
int showMenu()
{
	char choice;
	printf("##=====================================================================================================================================##\n");
	printf("Please choose:                                                                                                                         ||\n");
	printf("1. Play game                                                                                                                           ||\n");
	printf("2. Quit                                                                                                                                ||\n");
	printf("##=====================================================================================================================================##\n");
	choice = getInput();
	switch (choice){
		case '1':
			return showRules();
		case '2':
			printf("Goodbye!                                                                                                                               ||\n");
			printf("##=====================================================================================================================================##\n");
			exit(0);
		default:
			printf("Invalid choice!\n");
			return false;
	}
}

