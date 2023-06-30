// ===================================================================================
//
//  Assignment:  1 
//  Milestone:   4
//  Chungon Tse, 154928188, cotse@myseneca.ca
//  NFF
//  Description: account.c
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "commonHelpers.h"
#include "account.h"

void getAccount(struct Account* account)
{
	printf("\nAccount Data: New Record\n");
	printf("----------------------------------------\n");
	printf("Enter the account number: ");
	account->accountNumber = getPositiveInteger();

	char validChars[3] = "AC";
	printf("\nEnter the account type (A=Agent | C=Customer): ");
	account->type = getCharOption(validChars);
	printf("\n");
}

void getUserLogin(struct UserLogin* login)
{
	printf("User Login Data Input\n");
	printf("----------------------------------------\n");
	printf("Enter user login (10 chars max): ");
	getCString(login->loginName, 1, 10);
	printf("Enter the display name (30 chars max): ");
	getCString(login->customerName, 1, 30);
	printf("Enter the password (must be 8 chars in length): ");
	getCString(login->password, 8, 8);
	printf("\n");
}

void getDemographic(struct Demographic* demographic)
{
	printf("Demographic Data Input\n");
	printf("----------------------------------------\n");
	printf("Enter birth year (current age must be between 18 and 110): ");
	demographic->birthYear = getIntFromRange(currentYear() - 110, currentYear() - 18);
	printf("Enter the household Income: $");
	demographic->income = getPositiveDouble();
	printf("Enter the country (30 chars max.): ");
	getCString(demographic->country, 1, 30);
	printf("\n");
}

void updateUserLogin(struct UserLogin* login){
	int menuOption = -1;

	while(menuOption != 0){
		printf("\nUser Login: %s - Update Options\n", login->loginName);
		printf("----------------------------------------\n");
		printf("1) Display name (current value: %s)\n", login->customerName);
		printf("2) Password\n");
		printf("0) Done\n");
		printf("Selection: ");

		menuOption = getIntFromRange(0,2);

		switch(menuOption){
			case 1:
				printf("\nEnter the display name (30 chars max): ");
				getCString(login->customerName, 1, 30);
				break;
			case 2:
				printf("\nEnter the password (must be 8 chars in length): ");
				getCString(login->password, 8, 8);
				break;
		}
	}
}
void updateDemographic(struct Demographic* demo){
	int menuOption = -1;

	while(menuOption != 0){
		printf("\nDemographic Update Options\n");
		printf("----------------------------------------\n");
		printf("1) Household Income (current value: $%.2lf)\n", demo->income); //$%10.2lf
		printf("2) Country (current value: %s)\n", demo->country);
		printf("0) Done\n");
		printf("Selection: ");

		menuOption = getIntFromRange(0,2);

		switch(menuOption){
			case 1:
				printf("\nEnter the household Income: $");
				demo->income = getPositiveDouble();
				break;
			case 2:
				printf("\nEnter the country (30 chars max.): ");
				getCString(demo->country, 1, 30);
				break;
		}
	}
}

void updateAccount(struct Account* account){

	char validChars[3] = "AC";
	int menuOption = -1;

	while(menuOption != 0){
		printf("\nAccount: %05d - Update Options\n", account->accountNumber);
		printf("----------------------------------------\n");	
		printf("1) Update account type (current value: %c)\n", account->type);
		printf("2) Login\n");
		printf("3) Demographics\n");
		printf("0) Done\n");
		printf("Selection: ");

		menuOption = getIntFromRange(0,3);

		switch(menuOption){
			case 1:
				printf("\nEnter the account type (A=Agent | C=Customer): ");
				account->type = getCharOption(validChars);
				break;
			case 2:
				updateUserLogin(&account->login);
				break;
			case 3:
				updateDemographic(&account->demo);
				break;
			case 0:
				printf("\n");
				break;
		}
	}
}

