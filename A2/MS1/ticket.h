// ===================================================================================
//
//  Assignment:  2
//  Milestone:   1
//  Chungon Tse, re-implementation May 2022
//  Description: ticket.h
//
#ifndef TICKET_H_
#define TICKET_H_


struct Message{
    char accountType;
    char customerName[31];
    char detail[151];
};

struct Ticket{
    int uniqueId;
    int accountNo;
    int status; // 0=closed, 1=active
    char subjectLine[31];
    int noOfMessages;
    struct Message messages[20];
};



#endif // !TICKET_H_