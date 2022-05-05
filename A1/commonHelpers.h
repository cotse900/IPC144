// ===================================================================================
//
//  Assignment:  1 
//  Milestone:   1
//  Description: commonHelpers.h
//

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