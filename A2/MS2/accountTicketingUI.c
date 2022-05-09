// ===================================================================================
//
//  Assignment:  2
//  Milestone:   2
//  Chungon Tse, re-implementation May 2022
//  Description: accountTicketingUI.c
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
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
    if (account->type == 'C') {
        printf("%05d AGENT     %5d\n", account->accountNumber, account->demo.birthYear);
    }
    if (account->type == 'A') {
        printf("%05d CUSTOMER  %5d\n", account->accountNumber, account->demo.birthYear);
    }
}

void displayAccountDetailRecord(const struct Account* account)
{
    char hiddenPassword[31];
    int i = 0;
    for (i = 0; i < 31; i++) {
        if (i % 2 == 0) {
            hiddenPassword[i] = account->login.password[i];
        }
        else {
            hiddenPassword[i] = '*';
        }
    }

    if (account->type == 'A')
    {
        printf("%05d AGENT     %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->accountNumber, account->demo.birthYear, account->demo.income, account->demo.country, account->login.customerName, account->login.loginName, hiddenPassword);
    }
    else if (account->type == 'C')
    {
        printf("%05d CUSTOMER  %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->accountNumber, account->demo.birthYear, account->demo.income, account->demo.country, account->login.customerName, account->login.loginName, hiddenPassword);
    }
}

void menuAgent(struct AccountTicketingData* accTicketingData, const struct Account* loggedInUser){
    struct Account* account = accTicketingData->accounts;
    int numberOfAccounts = accTicketingData->ACCOUNT_MAX_SIZE;

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
        printf("6) List new tickets\n");
        printf("7) List active tickets\n");
        printf("8) Manage a ticket\n");
        printf("9) Archive closed tickets\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n");
        printf("\nSelection: ");

        menuOption = getIntFromRange(0,9);//NO LINESPACING
        printf("\n");
        int i, j;
        int full = 1;
        int accountIndex = 0;
	    int highest = 0;
        switch(menuOption){
            case 1:
                highest = 0;
	            for(i=0; i<numberOfAccounts; i++){
                    if(account[i].accountNumber > highest){
                        highest = account[i].accountNumber;
                    }
                }
                for(i=0; i < numberOfAccounts; i++){
                    if(account[i].accountNumber == 0){
                        account[i].accountNumber = highest + 1; //auto increment
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
                displayAllAccountSummaryRecords(account, numberOfAccounts);
                pauseExecution();
                break;
            case 5:
                displayAllAccountDetailRecords(account, numberOfAccounts);
                pauseExecution();
                break;
            case 6:
                while(menuOption != 0){
                    printf("------ ----- --------------- ------ ------------------------------ --------\n");//LINESPACING
                    printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
                    printf("------ ----- --------------- ------ ------------------------------ --------\n");

                    //print all new tickets
                    for(i=0; i<accTicketingData->TICKET_MAX_SIZE; i++){
                        if( accTicketingData->tickets[i].status == 1
                            && accTicketingData->tickets[i].noOfMessages == 1 ){
                                printf("%06d %-5d %-15s OPEN   %-30s %5d\n", accTicketingData->tickets[i].uniqueId, accTicketingData->tickets[i].accountNo,
                                            accTicketingData->tickets[i].messages[0].customerName, accTicketingData->tickets[i].subjectLine,
                                            accTicketingData->tickets[i].noOfMessages);
                        }
                    }
                    printf("------ ----- --------------- ------ ------------------------------ --------\n");
                    printf("\nEnter the ticket number to view the messages or\n");//LINESPACING
                    printf("0 to return to previous menu: ");//LINESPACING required
                    menuOption = getZeroOrPositiveInteger();
                    //is menuOption a ticket number?
                    printf("\n");
                    for(i=0; i<accTicketingData->TICKET_MAX_SIZE; i++){
                        //Is one of the above tickets
                        //accTicketingData->tickets[i].accountNo == loggedInUser->accountNumber
                        if( accTicketingData->tickets[i].status == 1 && accTicketingData->tickets[i].noOfMessages == 1 ){
                            if(menuOption == accTicketingData->tickets[i].uniqueId){
                                printf("================================================================================\n");
                                printf("%06d (OPEN) Re: %s\n", accTicketingData->tickets[i].uniqueId, accTicketingData->tickets[i].subjectLine);
                                printf("================================================================================\n");
                                if(accTicketingData->tickets[i].messages[0].accountType == 'C'){
                                    printf("CUSTOMER (%s):\n", accTicketingData->tickets[i].messages[0].customerName );
                                }else{
                                    printf("AGENT (%s):\n", accTicketingData->tickets[i].messages[0].customerName );
                                }
                                printf("   %s\n", accTicketingData->tickets[i].messages[0].detail);
                                pauseExecution();
                                break; //break the for loop, so 'i' will indicate valid id is found
                            }
                        }
                    }
                    if( menuOption != 0 && i == accTicketingData->TICKET_MAX_SIZE ){ //if for loop reached the end
                        printf("ERROR: Invalid ticket number.\n");
                        pauseExecution();
                    }
                }
                menuOption = -1; //reset it so we can stay in the while loop
                break;
            case 7:
                while(menuOption != 0){
                    printf("------ ----- --------------- ------ ------------------------------ --------\n");//LINESPACING
                    printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
                    printf("------ ----- --------------- ------ ------------------------------ --------\n");

                    //print all new tickets
                    for(i=0; i<accTicketingData->TICKET_MAX_SIZE; i++){
                        if(accTicketingData->tickets[i].status == 1 ){
                                printf("%06d %-5d %-15s ", accTicketingData->tickets[i].uniqueId, accTicketingData->tickets[i].accountNo,
                                            accTicketingData->tickets[i].messages[0].customerName);
                                if(accTicketingData->tickets[i].status == 0){
                                    printf("CLOSED");
                                }
                                if(accTicketingData->tickets[i].status == 1){
                                    printf("OPEN  ");
                                }
                                printf(" %-30s %5d\n", accTicketingData->tickets[i].subjectLine, accTicketingData->tickets[i].noOfMessages);
                        }
                    }
                    printf("------ ----- --------------- ------ ------------------------------ --------\n");
                    printf("\nEnter the ticket number to view the messages or\n");
                    printf("0 to return to previous menu: ");
                    menuOption = getZeroOrPositiveInteger();
                    printf("\n");
                    if(menuOption != 0){
                        for(i=0; i<accTicketingData->TICKET_MAX_SIZE; i++){
                            //Is one of the above tickets
                            //accTicketingData->tickets[i].accountNo == loggedInUser->accountNumber
                            if(accTicketingData->tickets[i].uniqueId == menuOption){
                                printf("================================================================================\n");
                                printf("%06d (", accTicketingData->tickets[i].uniqueId);
                                if(accTicketingData->tickets[i].status == 0){
                                    printf("CLOSED");
                                }
                                if(accTicketingData->tickets[i].status == 1){
                                    printf("OPEN");
                                }
                                printf(") Re: %s\n",  accTicketingData->tickets[i].subjectLine);
                                printf("================================================================================\n");
                                for(j=0; j<accTicketingData->tickets[i].noOfMessages; j++){
                                    if(j>0){
                                        printf("\n");
                                    }
                                    if(accTicketingData->tickets[i].messages[j].accountType == 'C'){
                                        printf("CUSTOMER (%s):\n", accTicketingData->tickets[i].messages[j].customerName );
                                    }else{
                                        printf("AGENT (%s):\n", accTicketingData->tickets[i].messages[j].customerName );
                                    }
                                    printf("   %s\n", accTicketingData->tickets[i].messages[j].detail);
                                }
                                break;
                            }
                        }
                        if( menuOption != 0 && i == accTicketingData->TICKET_MAX_SIZE ){ //if for loop reached the end
                            printf("ERROR: Invalid ticket number.\n");
                        }//NO LINESPACING
                        pauseExecution();
                    }
                }
                menuOption = -1; //reset it so we can stay in the while loop
                
                break;
            case 8:
                printf("Feature #8 currently unavailable!\n");
                pauseExecution();
                break;
            case 9:
                printf("Feature #9 currently unavailable!\n");
                pauseExecution();
                break;
            
        }

    }while(menuOption != 0);

    printf("### LOGGED OUT ###\n\n");
}

void menuCustomer(struct AccountTicketingData* accTicketingData, const struct Account* loggedInUser){
    int menuOption = -1;
    do{
        printf("CUSTOMER: %s (%05d)\n", loggedInUser->login.customerName, loggedInUser->accountNumber);//NO LINESPACING
        printf("==============================================\n");
        printf("Customer Main Menu\n");
        printf("==============================================\n");
        printf("1) View your account detail\n");
        printf("2) Create a new ticket\n");
        printf("3) Modify an active ticket\n");
        printf("4) List my tickets\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n");
        printf("\nSelection: ");

        menuOption = getIntFromRange(0,4);

        int i,j;
        //int full = 1;
        //int accountIndex = 0;
        switch(menuOption){
            case 1:
                printf("\n");
                displayAccountDetailHeader();
                displayAccountDetailRecord(loggedInUser);
                pauseExecution();
                break;
            case 2:
                printf("Feature #2 currently unavailable!\n");
                pauseExecution();
                break;
            case 3:
                printf("Feature #3 currently unavailable!\n"); 
                pauseExecution();
                break;
            case 4:
                printf("\n");
                while(menuOption != 0){
                    printf("------ ------ ------------------------------ --------\n");
                    printf("Ticket Status Subject                        Messages\n");
                    printf("------ ------ ------------------------------ --------\n");
                    for(i=0; i<accTicketingData->TICKET_MAX_SIZE;i++){
                        if(accTicketingData->tickets[i].accountNo == loggedInUser->accountNumber){
                            printf("%06d ", accTicketingData->tickets[i].uniqueId);
                            if(accTicketingData->tickets[i].status == 0){
                                printf("CLOSED");
                            }
                            if(accTicketingData->tickets[i].status == 1){
                                printf("OPEN  ");
                            }
                            printf(" %-30s %5d\n", accTicketingData->tickets[i].subjectLine, accTicketingData->tickets[i].noOfMessages);
                        }

                    }
                    printf("------ ------ ------------------------------ --------\n");
                    printf("\nEnter the ticket number to view the messages or\n");//LINESPACE
                    printf("0 to return to previous menu: ");
                    menuOption = getZeroOrPositiveInteger();
                    printf("\n");
                    if(menuOption != 0 ){
                        for(i=0; i<accTicketingData->TICKET_MAX_SIZE; i++){
                            if(accTicketingData->tickets[i].uniqueId == menuOption && accTicketingData->tickets[i].accountNo == loggedInUser->accountNumber){
                                printf("================================================================================\n");
                                printf("%06d (", accTicketingData->tickets[i].uniqueId);
                                if(accTicketingData->tickets[i].status == 0){
                                    printf("CLOSED");
                                }
                                if(accTicketingData->tickets[i].status == 1){
                                    printf("OPEN");
                                }
                                printf(") Re: %s\n",  accTicketingData->tickets[i].subjectLine);
                                printf("================================================================================\n");
                                for(j=0; j<accTicketingData->tickets[i].noOfMessages; j++){
                                    if(j>0){
                                        printf("\n");
                                    }
                                    if(accTicketingData->tickets[i].messages[j].accountType == 'C'){
                                        printf("CUSTOMER (%s):\n", accTicketingData->tickets[i].messages[j].customerName );
                                    }else{
                                        printf("AGENT (%s):\n", accTicketingData->tickets[i].messages[j].customerName );
                                    }
                                    printf("   %s\n", accTicketingData->tickets[i].messages[j].detail);
                                }
                                break;
                            }
                        }
                        if( menuOption != 0 && i == accTicketingData->TICKET_MAX_SIZE ){ //if for loop reached the end
                            printf("ERROR: Invalid ticket number.\n");
                        }
                        pauseExecution();
                        menuOption = -1; //stay until user press 0
                    }
                }
                menuOption = -1; //reset
                break;
        }

    }while(menuOption != 0);

    printf("\n### LOGGED OUT ###\n\n");
}

int menuLogin(struct AccountTicketingData* data){
    //struct Account* account = data->accounts;
    //int numberOfAccounts = data->ACCOUNT_MAX_SIZE;
    //int queryAccount = 0;
    char loginName[31];
    char password[31];
    int validLogin = 3;
    //int i;

    while(validLogin > 0){
        printf("\nEnter the account#: ");
        int queryAccount = getInteger();

        int queryAccountIndex = findAccountIndexByAcctNum(queryAccount, data->accounts, data->ACCOUNT_MAX_SIZE, 0);
        printf("User Login    : ");
        getCString(loginName, 1, 30); //Rooster Ronnie > 10 but no warn in sample output
        printf("Password      : ");
        getCString(password, 8, 30);
        
        
        if(queryAccountIndex != -1
            && strcmp(data->accounts[queryAccountIndex].login.loginName, loginName) == 0
            && strcmp(data->accounts[queryAccountIndex].login.password, password) == 0 ){
            validLogin = 0;
            //Password Success
            printf("\n");
            return queryAccountIndex;
        }else{
            validLogin--;
            printf("INVALID user login/password combination! [attempts remaining:%d]\n", validLogin);
        }
    }
    printf("\n");
    printf("ERROR:  Login failed!\n");

    return -1;

}

void applicationStartup(struct AccountTicketingData* data){ //, int numberOfAccounts){
    //struct Account* account; // = &(data->accounts[0]); // test
    //int numberOfAccounts = data->ACCOUNT_MAX_SIZE; //for this milestone

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
            int loginIndex = menuLogin(data);
            if(loginIndex == -1){
                pauseExecution();
                continue;
            }
            //(account, &account[loginIndex]);
            if(data->accounts[loginIndex].type == 'A'){
                menuAgent(data, &data->accounts[loginIndex]);
            }
            else if(data->accounts[loginIndex].type == 'C'){
                menuCustomer(data, &data->accounts[loginIndex]);
            }
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
        printf("Enter the account#: ");
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