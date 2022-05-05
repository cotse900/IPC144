// ===================================================================================
//
//  Assignment:  1 
//  Milestone:   1
//  Chungon Tse, 154928188, cotse@myseneca.ca
//  NFF
//  Description: commonHelpers.c
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "commonHelpers.h"

// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}

// As demonstrated in the course notes: 
//https://ict.senecacollege.ca//~ipc144/pages/content/formi.html#buf
// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
    while (getchar() != '\n')
    {
    ; // On purpose: do nothing
    }
}
int getInteger(void){
    int num = 0;
    char newlineCheck = 'x';
    while(newlineCheck != '\n'){
        scanf(" %d%c", &num, &newlineCheck);
        if(newlineCheck != '\n'){
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
    }
    return num;
}

int getPositiveInteger(void){
    int result = -1;
    while(result <= 0){
        result = getInteger();
        if(result <= 0){
            printf("ERROR: Value must be a positive integer greater than zero: ");
        }
    }
    return result;
}

double getDouble(void){
    double num = 0;
    char newlineCheck = 'x';
    while(newlineCheck != '\n'){
        scanf(" %lf%c", &num, &newlineCheck);
        if(newlineCheck != '\n'){
            clearStandardInputBuffer();
            printf("ERROR: Value must be an double floating-point number: ");
        }
    }
    return num;

}

double getPositiveDouble(void){
    double result = -1.0;
    while(result <= 0.0){
        result = getDouble();
        if(result <= 0.0){
            printf("ERROR: Value must be a positive double floating-point number: ");
        }
    }
    return result;
}

int getIntFromRange(int lower, int upper){
    int passed = 0;
    int result = 0;
    do
    {
        result = getInteger();
        if( result >= lower && result <= upper ){
            passed = 1;
        }else{
            printf("ERROR: Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (passed == 0);
    return result;
}

char getCharOption(char* validChars){

    char userChar;
    char newlineCheck = 'x';
    int isValid = 0;
    while(newlineCheck != '\n' || isValid == 0){
        scanf(" %c%c", &userChar, &newlineCheck);
        if(newlineCheck != '\n'){
            clearStandardInputBuffer();
        }else{
            //for loop check if userChar is in validChars
            for (char* t = validChars; *t != '\0'; t++) {
                if(userChar == *t){
                    isValid = 1;
                }
            }
        }
        if(isValid == 0){
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }
    }

    return userChar;
}

void getCString(char* stringPtr, int minLength, int maxLength){
    int size;
    int passed = 0;
    char tempString[30];
    while(passed == 0){
        //clean array
        int i;
        for(i=0; i<30; i++){
            tempString[i] = '\0'; //empty the char array
        }

        scanf(" %30[^\n]", tempString);
        clearStandardInputBuffer();

        size = 0;
        for ( i = 0; i < 30; i++) {
            if( tempString[i] != '\0' ){
                size++;
            }
        }

        if(size < minLength || size > maxLength){
            if(size > maxLength){
                printf("ERROR: String length must be no more than %d chars: ", maxLength);
            }else{
                printf("ERROR: String length must be between %d and %d chars: ", minLength, maxLength);
            }
        }else{
            passed = 1;
            for(i=0; i<maxLength; i++){
                stringPtr[i] = tempString[i];
            }
        }
    }
}
