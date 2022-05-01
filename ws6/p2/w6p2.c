/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NFF
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w6p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NO_OF_PRODUCT);
	printf("NOTE: A 'serving' is %dg\n", SERVING_GRAM);
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence) {
	struct CatFoodInfo foodInfo;

	printf("\nCat Food Product #%d\n", sequence + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&foodInfo.sku);
	printf("PRICE         : $");
	getDoublePositive(&foodInfo.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&foodInfo.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&foodInfo.calories);

	return foodInfo;
}
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg) {
	double resultKg = 0.0;
	if (*lbs / KG_TO_LBS) {
		resultKg = *lbs / KG_TO_LBS;
	}

	if (kg != NULL) {
		*kg = resultKg;
	;}
	return resultKg;
}
// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* gram) {
	int resultGram;
	if (*lbs / KG_TO_LBS * 1000.0) {
		resultGram = *lbs / KG_TO_LBS * 1000.0;
	}
	if (gram != NULL) {
		*gram = resultGram;
	}
	return resultGram;
}
// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kg, int* gram) {
	double resultKg = 0.0;
	int resultGram = 0;

	if (convertLbsKg(lbs, &resultKg)) {
		//resultKg = convertLbsKg(lbs, &resultKg);
		if (kg != NULL) {
			*kg = resultKg;
		}
	}
	if (convertLbsG(lbs, &resultGram)) {
		//resultGram = convertLbsG(lbs, &resultGram);
		if (gram != NULL) {
			*gram = resultGram;
		}
	}
}
// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalGrams, double* noOfServing) {
	double resultNoOfServing = 0.0;
	if ((double)totalGrams / (double)gPerServ) {
		resultNoOfServing = (double)totalGrams / (double)gPerServ;
	}

	if (noOfServing != NULL) {
		*noOfServing = resultNoOfServing;
	}
	return resultNoOfServing;
}
// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalNoOfServing, double* costPerServing) {
	double resultCostPerServing = 0.0;
	if ((*productPrice) / (*totalNoOfServing)) {
		resultCostPerServing = (*productPrice) / (*totalNoOfServing);
	}
	if (costPerServing != NULL) {
		*costPerServing = resultCostPerServing;
	}
	return resultCostPerServing;
}
// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalNoOfCal, double* costPerCalorie) {
	if ((*productPrice) / (*totalNoOfCal)) {
		*costPerCalorie = (*productPrice) / (*totalNoOfCal);
	}
	return *costPerCalorie;
}
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo info) {
	struct ReportData reportData;
	reportData.calories = info.calories;
	reportData.price = info.price;
	reportData.sku = info.sku;
	reportData.weightLbs = info.weight;
	convertLbs(&info.weight, &reportData.weightKg, &reportData.weightg);
	calculateServings(SERVING_GRAM, reportData.weightg, &reportData.totalServings);
	calculateCostPerServing(&info.price, &reportData.totalServings, &reportData.costPerServing);
	return reportData;
}
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", SERVING_GRAM);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int isCheapest) {
	double totalCalories = reportData.calories * reportData.totalServings;
	double costPerCalories = calculateCostPerCal(&reportData.price, &totalCalories, &costPerCalories);
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportData.sku, reportData.price,
		reportData.weightLbs, reportData.weightKg, reportData.weightg, reportData.calories,
		reportData.totalServings, reportData.costPerServing, costPerCalories);
	if (isCheapest) {
		printf(" ***\n");
	}
	else {
		printf("\n");
	}
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo info) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%0.2lf\n\n", info.sku, info.price);
	printf("Happy shopping!\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void){
	struct CatFoodInfo CatFoodInfoArray[MAX_NO_OF_PRODUCT];
	struct ReportData ReportDataArray[MAX_NO_OF_PRODUCT];

	openingMessage(MAX_NO_OF_PRODUCT);

	int i;
	int cheapestCatFoodDataIndex = 0;
	double cheapestCatFoodDataCostPerServing = 0;

	for (i = 0; i < MAX_NO_OF_PRODUCT; i++) {
		CatFoodInfoArray[i] = getCatFoodInfo(i);
		ReportDataArray[i] = calculateReportData(CatFoodInfoArray[i]); //compute and store report data

		if (i == 0) {
			cheapestCatFoodDataCostPerServing = ReportDataArray[i].costPerServing; //initialize cheapest cost
		}
		else if (ReportDataArray[i].costPerServing < cheapestCatFoodDataCostPerServing) {
			cheapestCatFoodDataCostPerServing = ReportDataArray[i].costPerServing; //update lowest
			cheapestCatFoodDataIndex = i; //replace index representing lowest
		}
	}


	displayCatFoodHeader();
	for (i = 0; i < MAX_NO_OF_PRODUCT; i++) {
		displayCatFoodData(CatFoodInfoArray[i].sku, &CatFoodInfoArray[i].price, &CatFoodInfoArray[i].weight, CatFoodInfoArray[i].calories);
	}
	printf("\n");

	displayReportHeader();
	for (i = 0; i < MAX_NO_OF_PRODUCT; i++) {
		displayReportData(ReportDataArray[i], i == cheapestCatFoodDataIndex);
	}
	printf("\n");

	displayFinalAnalysis(CatFoodInfoArray[cheapestCatFoodDataIndex]);


}
