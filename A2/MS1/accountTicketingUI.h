// ===================================================================================
//
//  Assignment:  2
//  Milestone:   1
//  Chungon Tse, re-implementation May 2022
//  Description: accountTicketingUI.h
//
#ifndef ACCOUNT_TICKETINGUI_H_
#define ACCOUNT_TICKETINGUI_H_

#include "account.h"
#include "ticket.h"

struct AccountTicketingData
{
 struct Account* accounts; // array of accounts
 const int ACCOUNT_MAX_SIZE; // maximum elements for account array
 struct Ticket* tickets; // array of tickets
 const int TICKET_MAX_SIZE; // maximum elements for ticket array
};

void displayAccountSummaryHeader(void);
void displayAccountDetailHeader(void);
void displayAccountSummaryRecord(const struct Account* account);
void displayAccountDetailRecord(const struct Account* account);
void applicationStartup(struct AccountTicketingData* data); //, int numberOfAccounts);
void pauseExecution(void);

void menuAgent(struct AccountTicketingData* accTicketingData, const struct Account* loggedInUser);
void menuCustomer(struct Account* loggedInUser);
//int menuLogin(const struct Account* account, int numberOfAccounts);
int menuLogin(struct AccountTicketingData* data);

int findAccountIndexByAcctNum(int acctNum, const struct Account* account, int numberOfAccounts, int promptAcctNum);
void displayAllAccountSummaryRecords(const struct Account* account, int numberOfAccounts);
void displayAllAccountDetailRecords(const struct Account* account, int numberOfAccounts);


#endif // !ACCOUNT_TICKETINGUI_H_
