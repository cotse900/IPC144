/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00
#define MIN_COST 100.00
#define MAX_ITEM 10

int main(void)
{
	double incomeInput = 0;
	int wishListSize = 0;
	int i = 0;
	int j = 0;

	double cost[MAX_ITEM]; //cost
	int priority[MAX_ITEM]; //importance
	char options[MAX_ITEM]; //financial options y or n

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	//1. Enter income within range 2. Enter wish list items 3. wish list item details 4. cost priority option
	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf(" %lf", &incomeInput);
		if (incomeInput < MIN_INCOME) //too low
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		else if (incomeInput > MAX_INCOME) //too high
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");

	} while (incomeInput < MIN_INCOME || incomeInput > MAX_INCOME);

	do
	{ 
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf(" %d", &wishListSize);
		if (wishListSize <= 0 || wishListSize >= MAX_ITEM) {
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
	} while (wishListSize <= 0 || wishListSize >= MAX_ITEM);

	for (i = 0; i < wishListSize; i++) {
		printf("\nItem-%d Details:\n", i + 1); //first i = 0, so +1 to display "Item-1 Details"
		
		do {
			printf("   Item cost: $");
			scanf(" %lf", &cost[i]);
			if (cost[i] < 100.00) 
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (cost[i] < 100.00);

		do {
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &priority[i]);
			if (priority[i] < 1 || priority[i] > 3)
				{
					printf("      ERROR: Value must be between 1 and 3\n");
				}
		} while (priority[i] < 1 || priority[i] > 3);

		do {
			printf("   Does this item have financing options? [y/n]: ");//options
			scanf(" %c", &options[i]);
			if (options[i] != 'y' && options[i] != 'n')
			{
				printf("   ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (options[i] != 'y' && options[i] != 'n');
	}
	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	double costSum = 0;
	for (j = 0; j < wishListSize; j++)
		{
		printf("%3d  %5d    %5c    %11.2lf\n", j+1, priority[j], options[j], cost[j]);
		costSum += cost[j];
		}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", costSum);

	printf("\nBest of luck in all your future endeavours!");

	return 0;
}