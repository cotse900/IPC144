// ===================================================================================
//
//  Assignment:  1 
//  Milestone:   3
//  Chungon Tse, 154928188, cotse@myseneca.ca
//  NFF
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
    char type[2];
    struct UserLogin login;
    struct Demographic demo;
};


void getAccount(struct Account* account);
void getUserLogin(struct UserLogin* login);
void getDemographic(struct Demographic* demographic);
#endif // !ACCOUNT_H_