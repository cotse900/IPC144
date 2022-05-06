// ===================================================================================
//
//  Assignment:  1 
//  Milestone:   3
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
	printf("Account Data: New Record\n");
	printf("----------------------------------------\n");
	printf("Enter the account number: ");
	account->accountNumber = getPositiveInteger();

	char validChars[3] = "AC";
	printf("Enter the account type (A=Agent | C=Customer): ");
	account->type[0] = getCharOption(validChars);
	account->type[1] = '\0';
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
