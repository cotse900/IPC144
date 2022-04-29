/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NFF
	*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main(void) {
	const int JAN = 1;
	const int DEC = 12;
	//const int FEB = 2;
	//const int MAR = 3;
	//const int APR = 4;
	//const int MAY = 5;
	//const int JUN = 6;
	//const int JUL = 7;
	//const int AUG = 8;
	//const int SEP = 9;
	//const int OCT = 10;
	//const int NOV = 11;
	int yearInput = 0;
	int monthInput = 0;
	printf("General Well-being Log\n");
	printf("======================\n");

	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &yearInput, &monthInput);	
	
		if ((yearInput >= MIN_YEAR && yearInput <= MAX_YEAR) && (monthInput >= JAN && monthInput <= DEC))//correct year and correct month
		{
			printf("\n*** Log date set! ***\n");
			printf("\n");
			//printf("Log starting date : %d-%d-01", yearInput, monthInput);
			switch (monthInput)
			{
			case 1:
				printf("Log starting date: %d-JAN-01\n", yearInput);
				break;
			case 2:
				printf("Log starting date: %d-FEB-01\n", yearInput);
				break;
			case 3:
				printf("Log starting date: %d-MAR-01\n", yearInput);
				break;
			case 4:
				printf("Log starting date: %d-APR-01\n", yearInput);
				break;
			case 5:
				printf("Log starting date: %d-MAY-01\n", yearInput);
				break;
			case 6:
				printf("Log starting date: %d-JUN-01\n", yearInput);
				break;
			case 7:
				printf("Log starting date: %d-JUL-01\n", yearInput);
				break;
			case 8:
				printf("Log starting date: %d-AUG-01\n", yearInput);
				break;
			case 9:
				printf("Log starting date: %d-SEP-01\n", yearInput);
				break;
			case 10:
				printf("Log starting date: %d-OCT-01\n", yearInput);
				break;
			case 11:
				printf("Log starting date: %d-NOV-01\n", yearInput);
				break;
			case 12:
				printf("Log starting date: %d-DEC-01\n", yearInput);
				break;
			}
		}

		else if ((yearInput >= MIN_YEAR && yearInput <= MAX_YEAR) && (monthInput < JAN || monthInput > DEC))//correct year and wrong month
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}

		else if ((yearInput < MIN_YEAR || yearInput > MAX_YEAR) && (monthInput >= JAN && monthInput <= DEC))//wrong year and correct month
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
		else
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
	} while ((yearInput < MIN_YEAR || yearInput > MAX_YEAR) || (monthInput < JAN || monthInput > DEC));
	return 0;
}