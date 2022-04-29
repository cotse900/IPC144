/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   :Chungon Tse
	ID     :154928188
	Email  :cotse@myseneca.ca
	Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double cash;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("\nEnter dollars and cents amount to convert to coins: $");
	scanf("%lf", &cash);

	cash = cash * 100;
	int toonies = cash / 100;
	float remainder = cash / 100 - toonies;
	remainder = remainder * 100;
	printf("$2.00 Toonies X %d (remaining $%.2lf)\n", toonies, (float)remainder / 100);

	int loonies = (remainder / 100);
	float remainder2 = cash / 100 - loonies;
	printf("$1.00 Loonies X %d, (remaining $%.2f)\n", loonies, (float)remainder2 / 100);

	int quarters = (remainder2 / 100) / 0.25;
	int remainder3 = (int)remainder2 / 25;
	printf("$0.25 Quarters X %d, (remaining $%.2f)\n", quarters, (float)remainder3 / 100);
	printf("Machine error! Thank you for letting me keep $%.2f!\n");
	return 0;
}