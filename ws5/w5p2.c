/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NFF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PATH_LENGTH 1000
#define MAX_PLAYER_LIVES 10
#define GAME_PATH_MIN 10
#define GAME_PATH_MAX 70
#define GAME_PATH_IS_MULTIPLE_OF 5

struct PlayerInfo
{
	int lives;
	char symbol;
	int treasureFound;
	int enteredPosition[GAME_PATH_MAX]; //history of moves saved as entered position
	int remainingMoves;
	int lastPosition;
};

struct GameInfo
{
	int pathLength;
	int maxNoOfMoves;
	int bombPlacement[GAME_PATH_MAX];
	int treasurePlacement[GAME_PATH_MAX];
};

int main() {
	int i = 0;
	int j = 0;
	printf("================================\n");
	printf("         ""Treasure Hunt!""         \n");
	printf("================================\n");
	printf("\nPLAYER Configuration\n");
	printf("--------------------\n");

	struct PlayerInfo playerInfo;

	//get symbol
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &playerInfo.symbol);

	//get lives
	do {
		printf("Set the number of lives: ");
		scanf(" %d", &playerInfo.lives);

		if (playerInfo.lives < 1 || playerInfo.lives > MAX_PLAYER_LIVES) {
			printf("     ""Must be between 1 and %d!\n", MAX_PLAYER_LIVES);
		}
	} while (playerInfo.lives < 1 || playerInfo.lives > MAX_PLAYER_LIVES);

	printf("Player configuration set-up is complete\n");

	printf("\nGAME Configuration\n");
	printf("------------------\n");

	struct GameInfo gameInfo;
	playerInfo.treasureFound = 0;
	for (i = 0; i < GAME_PATH_MAX; i++) {
		playerInfo.enteredPosition[i] = 0;
		gameInfo.treasurePlacement[i] = 0;
		gameInfo.bombPlacement[i] = 0;
	}
	//Get path length
	do {
		printf("Set the path length (a multiple of %d between %d-%d): ", GAME_PATH_IS_MULTIPLE_OF, GAME_PATH_MIN, GAME_PATH_MAX);
		scanf(" %d", &gameInfo.pathLength);

		if ((gameInfo.pathLength < GAME_PATH_MIN) || (gameInfo.pathLength > GAME_PATH_MAX) || (gameInfo.pathLength % GAME_PATH_IS_MULTIPLE_OF != 0)) {
			printf("     ""Must be a multiple of %d and between %d-%d!!!\n", GAME_PATH_IS_MULTIPLE_OF, GAME_PATH_MIN, GAME_PATH_MAX);
		}
	} while ((gameInfo.pathLength < GAME_PATH_MIN) || (gameInfo.pathLength > GAME_PATH_MAX) || (gameInfo.pathLength % GAME_PATH_IS_MULTIPLE_OF != 0));

	//Get path length
	int maxNoOfMoveAllowed = (int)(gameInfo.pathLength * 0.75f);
	do {
		printf("Set the limit for number of moves allowed: ");
		scanf(" %d", &gameInfo.maxNoOfMoves);

		if ((gameInfo.maxNoOfMoves < playerInfo.lives) || (gameInfo.maxNoOfMoves > maxNoOfMoveAllowed)) {
			printf("    ""Value must be between %d and %d\n", playerInfo.lives, maxNoOfMoveAllowed);
		}
		else {
			playerInfo.remainingMoves = gameInfo.maxNoOfMoves;
		}
	} while ((gameInfo.maxNoOfMoves < playerInfo.lives) || (gameInfo.maxNoOfMoves > maxNoOfMoveAllowed));

	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameInfo.pathLength);

	for (i = 0; i < gameInfo.pathLength / GAME_PATH_IS_MULTIPLE_OF; i++) {
		printf("   ""Positions [%2d-%2d]: ", i * GAME_PATH_IS_MULTIPLE_OF + 1, i * GAME_PATH_IS_MULTIPLE_OF + GAME_PATH_IS_MULTIPLE_OF);
		for (j = 0; j < GAME_PATH_IS_MULTIPLE_OF; j++) {
			scanf("%d", &gameInfo.bombPlacement[i * GAME_PATH_IS_MULTIPLE_OF + j]);
		}
	}
	printf("BOMB placement set\n");

	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameInfo.pathLength);

	for (i = 0; i < gameInfo.pathLength / GAME_PATH_IS_MULTIPLE_OF; i++) {
		printf("   ""Positions [%2d-%2d]: ", i * GAME_PATH_IS_MULTIPLE_OF + 1, i * GAME_PATH_IS_MULTIPLE_OF + GAME_PATH_IS_MULTIPLE_OF);
		for (j = 0; j < GAME_PATH_IS_MULTIPLE_OF; j++) {
			scanf("%d", &gameInfo.treasurePlacement[i * GAME_PATH_IS_MULTIPLE_OF + j]);
		}
	}
	printf("TREASURE placement set\n");

	printf("\nGAME configuration set-up is complete...\n");
	printf("\n------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   ""Symbol""    "" : %c\n", playerInfo.symbol);
	printf("   ""Lives""     "" : %d\n", playerInfo.lives);
	printf("   ""Treasure""  "" : [ready for gameplay]\n");
	printf("   ""History""   "" : [ready for gameplay]\n");
	printf("\nGame:\n");
	printf("   ""Path Length: %d\n", gameInfo.pathLength);
	printf("   ""Bombs""      "": ");
	for (i = 0; i < gameInfo.pathLength; i++) {
		printf("%d", gameInfo.bombPlacement[i]);
	}
	printf("\n");
	printf("   ""Treasure""   "": ");
	for (i = 0; i < gameInfo.pathLength; i++) {
		printf("%d", gameInfo.treasurePlacement[i]);
	}
	printf("\n");
	printf("\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");



	//p2 code start
	int shouldGameContinue = 1;
	playerInfo.lastPosition = -1;

	while (shouldGameContinue == 1) {
		//print position if player is moved
		if (playerInfo.lastPosition != -1) {
			printf("\n");
			for (i = 0; i < gameInfo.pathLength; i++) {
				if (i == playerInfo.lastPosition) {
					printf("  ");
					printf("%c", playerInfo.symbol);
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");

		//print path
		printf("  ");
		for (i = 0; i < gameInfo.pathLength; i++)
			 {
			if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 0 && gameInfo.treasurePlacement[i] == 0) {
				printf(".");
			}
			else if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 1 && gameInfo.treasurePlacement[i] == 1) {
				printf("&");
			}
			else if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 1) {
				printf("!");
			}
			else if (playerInfo.enteredPosition[i] == 1 && gameInfo.treasurePlacement[i] == 1) {
				printf("$");
			}
			else {
				printf("-");
			}
		}
		printf("\n");
		printf("  ");
		for (i = 1; i < gameInfo.pathLength + 1; i++)
			 {
			int firstNumber = i;
			while (firstNumber >= 10) {
				firstNumber = firstNumber / 10;
			}

			if (i % 10 == 0) {
				printf("%d", firstNumber);
			}
			else {
				printf("|");
			}
		}
		printf("\n");

		printf("  ");
		for (i = 1; i < gameInfo.pathLength + 1; i++) {
			printf("%d", i % 10);
		}
		printf("\n");//

		//print stats
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", playerInfo.lives, playerInfo.treasureFound, playerInfo.remainingMoves);
		printf("+---------------------------------------------------+\n");

		int nextMove = -1;
		do {
			printf("Next Move [%d-%d]: ", 1, gameInfo.pathLength);
			scanf(" %d", &nextMove);
			if ((nextMove < 1) || (nextMove > gameInfo.pathLength)) {
				printf("  ""Out of Range!!!\n");
			}
		} while ((nextMove < 1) || (nextMove > gameInfo.pathLength));

		nextMove = nextMove - 1; //enter by i.e. 1-20, but we treat it as 0-19 for array indexing

		if (playerInfo.enteredPosition[nextMove] == 0) {
			if (gameInfo.bombPlacement[nextMove] == 1 && gameInfo.treasurePlacement[nextMove] == 1) {
				printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
				playerInfo.lives--;
				printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
				playerInfo.treasureFound++;
				playerInfo.enteredPosition[nextMove] = 1;
				playerInfo.remainingMoves--;
				playerInfo.lastPosition = nextMove;
			}
			else if (gameInfo.bombPlacement[nextMove] == 1) {
				printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
				playerInfo.lives--;
				playerInfo.enteredPosition[nextMove] = 1;
				playerInfo.remainingMoves--;
				playerInfo.lastPosition = nextMove;
			}
			else if (gameInfo.treasurePlacement[nextMove] == 1) {
				printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
				playerInfo.treasureFound++;
				playerInfo.enteredPosition[nextMove] = 1;
				playerInfo.remainingMoves--;
				playerInfo.lastPosition = nextMove;
			}
			else {
				printf("\n===============> [.] ...Nothing found here... [.]\n");
				playerInfo.enteredPosition[nextMove] = 1;
				playerInfo.remainingMoves--;
				playerInfo.lastPosition = nextMove;
			}
		}
		else {
			printf("\n===============> Dope! You've been here before!\n");
			playerInfo.enteredPosition[nextMove] = 1;
			playerInfo.lastPosition = nextMove;
		}

		//determine if we need to continue the game
		if (playerInfo.lives == 0 || playerInfo.remainingMoves == 0) {
			if (playerInfo.lives == 0) {
				printf("\nNo more LIVES remaining!\n");
				//FOR DISPLAYING POSITION UPON ZERO LIFE BELOW
				if (playerInfo.lastPosition != -1) {
					printf("\n");
					for (i = 0; i < gameInfo.pathLength; i++) {
						if (i == playerInfo.lastPosition) {
							printf("  ");
							printf("%c", playerInfo.symbol);
						}
						else {
							printf(" ");
						}
					}
				}
				printf("\n");
				printf("  ");
				for (i = 0; i < gameInfo.pathLength; i++)
				{
					if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 0 && gameInfo.treasurePlacement[i] == 0) {
						printf(".");
					}
					else if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 1 && gameInfo.treasurePlacement[i] == 1) {
						printf("&");
					}
					else if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 1) {
						printf("!");
					}
					else if (playerInfo.enteredPosition[i] == 1 && gameInfo.treasurePlacement[i] == 1) {
						printf("$");
					}
					else {
						printf("-");
					}
				}
				printf("\n");
				printf("  ");
				for (i = 1; i < gameInfo.pathLength + 1; i++)
				{
					int firstNumber = i;
					while (firstNumber >= 10) {
						firstNumber = firstNumber / 10;
					}

					if (i % 10 == 0) {
						printf("%d", firstNumber);
					}
					else {
						printf("|");
					}
				}
				printf("\n");
				printf("  ");
				for (i = 1; i < gameInfo.pathLength + 1; i++) {
					printf("%d", i % 10);
				}
				//FOR DISPLAYING POSITION UPON ZERO LIFE ABOVE
				printf("\n+---------------------------------------------------+\n");
				printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", playerInfo.lives, playerInfo.treasureFound, playerInfo.remainingMoves);
				printf("+---------------------------------------------------+\n");
			}
			if (playerInfo.remainingMoves == 0) {
				printf("\nNo more MOVES remaining!\n");
				//FOR DISPLAYING POSITION UPON ZERO MOVE BELOW
				if (playerInfo.lastPosition != -1) {
					printf("\n");
					for (i = 0; i < gameInfo.pathLength; i++) {
						if (i == playerInfo.lastPosition) {
							printf("  ");
							printf("%c", playerInfo.symbol);
						}
						else {
							printf(" ");
						}
					}
				}
				printf("\n");
				printf("  ");
				for (i = 0; i < gameInfo.pathLength; i++)
				{
					if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 0 && gameInfo.treasurePlacement[i] == 0) {
						printf(".");
					}
					else if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 1 && gameInfo.treasurePlacement[i] == 1) {
						printf("&");
					}
					else if (playerInfo.enteredPosition[i] == 1 && gameInfo.bombPlacement[i] == 1) {
						printf("!");
					}
					else if (playerInfo.enteredPosition[i] == 1 && gameInfo.treasurePlacement[i] == 1) {
						printf("$");
					}
					else {
						printf("-");
					}
				}
				printf("\n");
				printf("  ");
				for (i = 1; i < gameInfo.pathLength + 1; i++)
				{
					int firstNumber = i;
					while (firstNumber >= 10) {
						firstNumber = firstNumber / 10;
					}

					if (i % 10 == 0) {
						printf("%d", firstNumber);
					}
					else {
						printf("|");
					}
				}
				printf("\n");
				printf("  ");
				for (i = 1; i < gameInfo.pathLength + 1; i++) {
					printf("%d", i % 10);
				}
				//FOR DISPLAYING POSITION UPON ZERO MOVE ABOVE
				printf("\n+---------------------------------------------------+\n");
				printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", playerInfo.lives, playerInfo.treasureFound, playerInfo.remainingMoves);
				printf("+---------------------------------------------------+\n");
			}

			printf("\n##################\n");
			printf("#   Game over!   #\n");
			printf("##################\n\n");
			printf("You should play again and try to beat your score!\n");
			shouldGameContinue = 0;
		}
	}
	return 0;

}