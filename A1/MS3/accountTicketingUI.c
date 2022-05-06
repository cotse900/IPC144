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

void displayAccountSummaryHeader(void)
{
	printf("Acct# Acct.Type Birth\n");
	printf("----- --------- -----\n");
}

void displayAccountDetailHeader(void)
{
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

void displayAccountSummaryRecord(const struct Account* account)
{
    char accountTypeDisplayCustomer[9] = "CUSTOMER";
    char accountTypeDisplayAgent[6] = "AGENT";
    char *accountTypeDisplay;
    if(*account->type == 'C'){
        accountTypeDisplay = accountTypeDisplayCustomer;
    }
    if(*account->type == 'A'){
        accountTypeDisplay = accountTypeDisplayAgent;
    }

	printf("%05d %-9s %5d\n", account->accountNumber, accountTypeDisplay, account->demo.birthYear);
}

void displayAccountDetailRecord(const struct Account* account)
{
    char accountTypeDisplayCustomer[9] = "CUSTOMER";
    char accountTypeDisplayAgent[6] = "AGENT";
    char *accountTypeDisplay;
    if(*account->type == 'C'){
        accountTypeDisplay = accountTypeDisplayCustomer;
    }
    if(*account->type == 'A'){
        accountTypeDisplay = accountTypeDisplayAgent;
    }

    char hiddenPassword[31];
    int i=0;
    for(i=0;i<31;i++){
        if(i%2==0){
            hiddenPassword[i] = account->login.password[i];
        }else{
            hiddenPassword[i] = '*';
        }
    }

	printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->accountNumber, accountTypeDisplay, account->demo.birthYear, account->demo.income, account->demo.country, account->login.customerName, account->login.loginName, hiddenPassword);
}