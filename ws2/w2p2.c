/*
	==================================================
	Workshop #2 (Part-2):
	==================================================
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double cash;
	int cash2;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &cash);
	printf("Service fee (5.0 percent): %.2lf", cash*0.05);
	printf("\nBalance to dispense: $%.2lf\n\n", cash*0.95);

	cash2 = cash * 0.95 * 100;
	int toonies = cash2 / 200;
	int remainder = cash2 % 200;
	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies, (double)remainder / 100);

	int loonies = remainder / 100;
	int remainder2 = cash2 % 100;
	printf("$1.00 Loonies  X %d (remaining: $%.2f)\n", loonies, (double)remainder2 / 100);

	int quarters = remainder2 / 25;
	int remainder3 = remainder2 % 25;
	printf("$0.25 Quarters X %d (remaining: $%.2f)\n", quarters, (double)remainder3 / 100);

	int dimes = remainder3 / 10;
	int remainder4 = remainder3 % 10;
	printf("$0.10 Dimes    X %d (remaining: $%.2f)\n", dimes, (double)remainder4 / 100);

	int nickels = remainder4 / 5;
	int remainder5 = remainder4 % 5;
	printf("$0.05 Nickels  X %d (remaining: $%.2f)\n", nickels, (double)remainder5 / 100);

	int pennies = remainder5 / 1;
	int remainder6 = remainder5 % 1;
	printf("$0.01 Pennies  X %d (remaining: $%.2f)\n", pennies, (double)remainder6 / 100);

	printf("\nAll coins dispensed!");
	return 0;
}
