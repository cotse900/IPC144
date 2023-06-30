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

#include "accountTicketingUI.h"

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
    if(account->type == 'C'){
        accountTypeDisplay = accountTypeDisplayCustomer;
    }
    if(account->type == 'A'){
        accountTypeDisplay = accountTypeDisplayAgent;
    }

	printf("%05d %-9s %5d\n", account->accountNumber, accountTypeDisplay, account->demo.birthYear);
}

void displayAccountDetailRecord(const struct Account* account)
{
    char accountTypeDisplayCustomer[9] = "CUSTOMER";
    char accountTypeDisplayAgent[6] = "AGENT";
    char *accountTypeDisplay;
    if(account->type == 'C'){
        accountTypeDisplay = accountTypeDisplayCustomer;
    }
    if(account->type == 'A'){
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

void menuAgent(struct Account* account, int numberOfAccounts, const struct Account* loggedInUser){
    int menuOption = -1;
    do{
        printf("AGENT: %s (%05d)\n", loggedInUser->login.customerName, loggedInUser->accountNumber);
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf("1) Add a new account\n");
        printf("2) Modify an existing account\n");
        printf("3) Remove an account\n");
        printf("4) List accounts: summary view\n");
        printf("5) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n");
        printf("\nSelection: ");

        menuOption = getIntFromRange(0,5);

        int i;
        int full = 1;
        int accountIndex = 0;
        switch(menuOption){
            case 1:
                for(i=0; i < numberOfAccounts; i++){
                    if(account[i].accountNumber == 0){
                        getAccount(&account[i]);
                        getUserLogin(&account[i].login);
                        getDemographic(&account[i].demo);
                        printf("*** New account added! ***\n");
                        pauseExecution();
                        full = 0;
                        break;
                    }
                }
                if(full) printf("ERROR: Account listing is FULL, call ITS Support!\n");
                break;
            case 2:
                accountIndex = findAccountIndexByAcctNum(0, account, numberOfAccounts, 1);
                if(accountIndex != -1){
                    updateAccount(&account[accountIndex]);
                }
                else{
                    printf("ERROR:  Access Denied.\n"); // no matching account
                }
                break;
            case 3:
                //printf("Enter the account#: ");
                accountIndex = findAccountIndexByAcctNum(0, account, numberOfAccounts, 1);

                //display detail
                //displayAccountDetailHeader();
                //displayAccountDetailRecord(&account[accountIndex]);
                if(account[accountIndex].accountNumber == loggedInUser->accountNumber){
                    printf("\nERROR: You can't remove your own account!\n");
                }
                else{
                    displayAccountDetailHeader();
                    displayAccountDetailRecord(&account[accountIndex]);
                    printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                    char validChars[3] = "YN";
                    char remove = getCharOption(validChars);
                    if(remove == 'Y' || remove == 'y'){
                        account[accountIndex].accountNumber = 0; // 0 means removed
                        printf("\n*** Account Removed! ***\n");
                    }else{
                        printf("\n*** No changes made! ***\n");
                    }
                }
                pauseExecution();
                break;
            case 4:
                printf("\n");
                displayAllAccountSummaryRecords(account, numberOfAccounts);
                pauseExecution();
                break;
            case 5:
                printf("\n");
                displayAllAccountDetailRecords(account, numberOfAccounts);
                pauseExecution();
                break;
            
        }

    }while(menuOption != 0);

    printf("\n### LOGGED OUT ###\n\n");
}

int menuLogin(const struct Account* account, int numberOfAccounts){
    printf("\nEnter your account#: ");
    int queryAccount = getInteger(); //Account Number
    printf("\n");
    if(queryAccount == -1){
        return -1;
    }else{
        int i=0;
        for(i=0; i<numberOfAccounts; i++){
            if(account[i].accountNumber == queryAccount){
                if(account[i].type == 'A'){
                    return i;
                }else{
                    printf("CUSTOMER: home menu currently unavailable...\n");
                    pauseExecution();
                    return -1;
                }
            }
        }

        //no matching record
        printf("ERROR:  Access Denied.\n");
        pauseExecution();
        return -1;
    }
}

void applicationStartup(struct Account* account, int numberOfAccounts){
    char validChar[4] = "yYnN";
    int userInput = -1;
    while(userInput != 0){
        printf("==============================================\n");
        printf("Account Ticketing System - Login\n");
        printf("==============================================\n");
        printf("1) Login to the system\n");
        printf("0) Exit application\n");
        printf("----------------------------------------------\n");
        printf("\nSelection: ");

        userInput = getIntFromRange(0, 1);
        if(userInput == 1){
            int loginIndex = menuLogin(account, numberOfAccounts);
            if(loginIndex == -1){
                continue;
            }
            menuAgent(account, numberOfAccounts, &account[loginIndex]);
        }
        if(userInput == 0){
            printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
            char confirmation = getCharOption(validChar);
            if(confirmation == 'Y' || confirmation == 'y'){
                printf("\n==============================================\n");
                printf("Account Ticketing System - Terminated\n");
                printf("==============================================\n");
            }
            else{
                userInput = -1;
                printf("\n");
            }
        }
    }
}

// Pause execution until user enters the enter key
void pauseExecution(void)
{
	printf("\n<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	putchar('\n');
}


int findAccountIndexByAcctNum(int acctNum, const struct Account* account, int numberOfAccounts, int promptAcctNum){
    
    if(promptAcctNum){
        printf("\nEnter the account#: ");
        acctNum = getPositiveInteger();
    }

    int i;
    for(i=0; i<numberOfAccounts; i++){
        if(acctNum == account[i].accountNumber){
            return i;
        }
    }

    return -1;
}


void displayAllAccountSummaryRecords(const struct Account* account, int numberOfAccounts){
    
    displayAccountSummaryHeader();
    int i;
    for(i=0;i<numberOfAccounts;i++){
        if(account[i].accountNumber > 0){
            displayAccountSummaryRecord(&account[i]);
        }
    }
}

void displayAllAccountDetailRecords(const struct Account* account, int numberOfAccounts){

    displayAccountDetailHeader();
    int i;
    for(i=0;i<numberOfAccounts;i++){
        if(account[i].accountNumber > 0){
            displayAccountDetailRecord(&account[i]);
        }
    }
}