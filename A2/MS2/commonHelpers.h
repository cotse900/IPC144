// ===================================================================================
//
//  Assignment:  2
//  Milestone:   2
//  Chungon Tse, re-implementation May 2022
//  Description: commonHelpers.h
//
#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

#include <time.h>

int currentYear(void);
void clearStandardInputBuffer(void);

int getInteger(void);
int getPositiveInteger(void);
int getZeroOrPositiveInteger(void);
double getDouble(void);
double getPositiveDouble(void);
int getIntFromRange(int lower, int upper);
char getCharOption(char* validChars);
void getCString(char* stringPtr, int minLength, int maxLength);


int haveWhitespace(char* stringPtr, int length);
int containsTwoOfDigitsUpLowSymbol(char* stringPtr, int length);
void stringToUpper(char *convertString);
#endif