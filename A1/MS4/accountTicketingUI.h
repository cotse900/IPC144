// ===================================================================================
//
//  Assignment:  1 
//  Milestone:   4
//  Chungon Tse, 154928188, cotse@myseneca.ca
//  NFF
//  Description: account.h
//
#ifndef ACCOUNT_TICKETINGUI_H_
#define ACCOUNT_TICKETINGUI_H_

#include "account.h"

void displayAccountSummaryHeader(void);
void displayAccountDetailHeader(void);
void displayAccountSummaryRecord(const struct Account* account);
void displayAccountDetailRecord(const struct Account* account);
void applicationStartup(struct Account* account, int numberOfAccounts);
void pauseExecution(void);

void menuAgent(struct Account* account, int numberOfAccounts, const struct Account* loggedInUser);
int menuLogin(const struct Account* account, int numberOfAccounts);

int findAccountIndexByAcctNum(int acctNum, const struct Account* account, int numberOfAccounts, int promptAcctNum);
void displayAllAccountSummaryRecords(const struct Account* account, int numberOfAccounts);
void displayAllAccountDetailRecords(const struct Account* account, int numberOfAccounts);
#endif // !ACCOUNT_TICKETINGUI_H_
