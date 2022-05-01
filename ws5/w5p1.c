/*
	==================================================
	Workshop #5 (Part-1):
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

	return 0;

}
