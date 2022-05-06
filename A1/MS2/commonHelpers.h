// ===================================================================================
//
//  Assignment:  1 
//  Milestone:   2
//  Chungon Tse, 154928188, cotse@myseneca.ca
//  NFF
//  Description: commonHelpers.h
//
#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

#include <time.h>

int currentYear(void);
void clearStanadardInputBuffer(void);

int getInteger(void);
int getPositiveInteger(void);
double getDouble(void);
double getPositiveDouble(void);
int getIntFromRange(int lower, int upper);
char getCharOption(char* validChars);
void getCString(char* stringPtr, int minLength, int maxLength);

#endif