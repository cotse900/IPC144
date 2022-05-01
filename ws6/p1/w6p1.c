/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NFF
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* to) {
	int result = 0;
	do {
		scanf("%d", &result);
		if (result <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (result <= 0);
	if (to != NULL) {
		*to = result;
	}
	return result;
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* to) {
	double result = 0.0;
	do {
		scanf("%lf", &result);
		if (result <= 0.0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (result <= 0.0);
	if (to != NULL) {
		*to = result;
	}
	return result;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int noOfProducts) {
	printf("===========================\n");
	printf("Starting Main Program Logic\n");
	printf("===========================\n\n");
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NO_OF_PRODUCT);
	printf("NOTE: A 'serving' is %dg\n", SERVING_GRAM);
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence) {
	struct CatFoodInfo foodInfo;

	printf("\nCat Food Product #%d\n", sequence);
	printf("--------------------\n");
	printf("SKU           : \n");
	getIntPositive(&foodInfo.sku);
	printf("PRICE         : $\n");
	getDoublePositive(&foodInfo.price);
	printf("WEIGHT (LBS)  : \n");
	getDoublePositive(&foodInfo.weight);
	printf("CALORIES/SERV.: \n");
	getIntPositive(&foodInfo.calories);

	return foodInfo;
}
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}
// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}
// 7. Logic entry point
void start(void) {
	struct CatFoodInfo CatFoodInfoArray[MAX_NO_OF_PRODUCT];

	openingMessage(MAX_NO_OF_PRODUCT);

	int i;
	for (i = 0; i < MAX_NO_OF_PRODUCT; i++) {
		CatFoodInfoArray[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();
	for (i = 0; i < MAX_NO_OF_PRODUCT; i++) {
		displayCatFoodData(CatFoodInfoArray[i].sku, &CatFoodInfoArray[i].price, &CatFoodInfoArray[i].weight, CatFoodInfoArray[i].calories);
	}
}