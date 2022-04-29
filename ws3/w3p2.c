/*
	==================================================
	Workshop #3 (Part-2):
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
#define LOG_DAYS 3

//if (x <= MAX_YEAR && x >= MIN_YEAR)
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
			//switch (monthInput)
			//{
			//case 1:
			//	printf("Log starting date: %d-JAN-01\n", yearInput);
			//	break;
			//case 2:
			//	printf("Log starting date: %d-FEB-01\n", yearInput);
			//	break;
			//case 3:
			//	printf("Log starting date: %d-MAR-01\n", yearInput);
			//	break;
			//case 4:
			//	printf("Log starting date: %d-APR-01\n", yearInput);
			//	break;
			//case 5:
			//	printf("Log starting date: %d-MAY-01\n", yearInput);
			//	break;
			//case 6:
			//	printf("Log starting date: %d-JUN-01\n", yearInput);
			//	break;
			//case 7:
			//	printf("Log starting date: %d-JUL-01\n", yearInput);
			//	break;
			//case 8:
			//	printf("Log starting date: %d-AUG-01\n", yearInput);
			//	break;
			//case 9:
			//	printf("Log starting date: %d-SEP-01\n", yearInput);
			//	break;
			//case 10:
			//	printf("Log starting date: %d-OCT-01\n", yearInput);
			//	break;
			//case 11:
			//	printf("Log starting date: %d-NOV-01\n", yearInput);
			//	break;
			//case 12:
			//	printf("Log starting date: %d-DEC-01\n", yearInput);
			//	break;
			//}
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

	//Part 2 Start
	double morningTotal = 0;
	double eveningTotal = 0;
	int day = 0;
	for (day = 1; day < LOG_DAYS + 1; day++)
	{
		switch (monthInput)
		{
		case 1:
			printf("%d-JAN-%02d\n", yearInput, day);
			break;
		case 2:
			printf("%d-FEB-%02d\n", yearInput, day);
			break;
		case 3:
			printf("%d-MAR-%02d\n", yearInput, day);
			break;
		case 4:
			printf("%d-APR-%02d\n", yearInput, day);
			break;
		case 5:
			printf("%d-MAY-%02d\n", yearInput, day);
			break;
		case 6:
			printf("%d-JUN-%02d\n", yearInput, day);
			break;
		case 7:
			printf("%d-JUL-%02d\n", yearInput, day);
			break;
		case 8:
			printf("%d-AUG-%02d\n", yearInput, day);
			break;
		case 9:
			printf("%d-SEP-%02d\n", yearInput, day);
			break;
		case 10:
			printf("%d-OCT-%02d\n", yearInput, day);
			break;
		case 11:
			printf("%d-NOV-%02d\n", yearInput, day);
			break;
		case 12:
			printf("%d-DEC-%02d\n", yearInput, day);
			break;
		}
		int morningValid = 0;
		while (morningValid == 0) {
			printf("   Morning rating (0.0-5.0): ");
			double morningRating = 0.0;
			scanf("%lf", &morningRating);

			if (morningRating < 0.0 || morningRating > 5.0) {
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
			else {
				morningValid = 1;
				morningTotal += morningRating; //add rating to total and assign to total
			}
		}
		int eveningValid = 0;
		while (eveningValid == 0) {
			printf("   Evening rating (0.0-5.0): ");
			double eveningRating = 0.0;
			scanf("%lf", &eveningRating);

			if (eveningRating < 0.0 || eveningRating > 5.0) {
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
			else {
				eveningValid = 1;
				eveningTotal += eveningRating;
			}
		}
		printf("\n");
	}

	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", morningTotal);
	printf("Evening total rating: %.3lf\n", eveningTotal);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n", morningTotal + eveningTotal);
	printf("\n");
	printf("Average morning rating:  %.1lf\n", morningTotal/LOG_DAYS);
	printf("Average evening rating:  %.1lf\n", eveningTotal/LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1lf\n", (morningTotal + eveningTotal)/(LOG_DAYS*2) );
	return 0;
}