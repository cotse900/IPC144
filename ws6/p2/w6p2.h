/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Chungon Tse
	ID     : 154928188
	Email  : cotse@myseneca.ca
	Section: NFF
*/

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NO_OF_PRODUCT 3
#define SERVING_GRAM 64
#define KG_TO_LBS 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo{
	int sku;
	double price;
	double weight;
	int calories;
};
struct ReportData{
	int sku;
	double price;
	double weightLbs;
	double weightKg;
	int calories;
	int weightg;
	double totalServings;
	double costPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* to);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* to);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int noOfProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories);

// 7. Logic entry point
void start(void);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* gram);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kg, int* gram);

// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalGrams, double* noOfServing);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalNoOfServing, double* costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalNoOfCal, double* costPerCalorie);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo info);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int isCheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo info);

// ----------------------------------------------------------------------------
