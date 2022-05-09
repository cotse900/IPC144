// ===================================================================================
//
//  Assignment:  2
//  Milestone:   2
//  Chungon Tse, re-implementation May 2022
//  Description: account.h
//
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

struct Demographic{
    int birthYear;
    double income;
    char country[31];
};

struct UserLogin{
    char customerName[31];
    char loginName[11];
    char password[9];
};

struct Account{
    int accountNumber;
    char type;
    struct UserLogin login;
    struct Demographic demo;
};


void getAccount(struct Account* account);
void getUserLogin(struct UserLogin* login);
void getDemographic(struct Demographic* demographic);

void updateAccount(struct Account* account);
void updateUserLogin(struct UserLogin* login);
void updateDemographic(struct Demographic* demo);
#endif // !ACCOUNT_H_