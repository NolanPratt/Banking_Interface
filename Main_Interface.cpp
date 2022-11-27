/*
 * 
 * Banking Interface
 * CS 210
 * Nolan Pratt
 * 11/27/2022
 *
 * This program funcitons as a banking interface for the user 
 * to access and manage their financial plans through the 
 * generated input menu. The current, core functionality  
 * allows a user to calculate compounding interest within 
 * an account based on the entered parameters.
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "GrowthCalculator.h"

using namespace std;


// Generates borders with n columns for menu display
void FillColumns(char c, size_t n) {
	for (size_t i = 0; i < n; i++) {
		cout << c;
	}	
}

// Corrects string capitalization for easier input validation
string caseCorrection(string input) {
	string newString;
	for (char character : input) {
		newString += toupper(character);
	}
	return newString;
}

// Displays the input menu and final results table
vector<double> InputMenuDisplay() {
	vector<double> investmentData;
	double initAmount;
	double monthDepo;
	double annualInt;
	double numYears;

	FillColumns('*', 37);
	cout << endl;
	FillColumns('-', 8);
	cout << "Enter Investment Data";
	FillColumns('-', 8);
	cout << endl;
	FillColumns('|', 1);

	// Get initAmount
	cout << "Initial Investment: $";
	cin >> initAmount;
	investmentData.push_back(initAmount);
	FillColumns('|', 1);

	// Get monthDepo
	cout << "Monthly Deposit: $"; 
	cin >> monthDepo;
	investmentData.push_back(monthDepo);
	FillColumns('|', 1);

	// Get annualInt
	cout << "Annual Interest: %";
	cin >> annualInt;
	investmentData.push_back(annualInt);
	FillColumns('|', 1);

	// Get numYears
	cout << "Number of years: ";
	cin >> numYears;
	investmentData.push_back(numYears);

	FillColumns('-', 37);
	cout << endl;
	FillColumns('*', 111);
	cout << endl;

	// Display results header
	FillColumns(' ', 2);
	cout << "Accrued Balance with Interest by Year";
	FillColumns(' ', 3);
	cout << "-without deposits-";
	FillColumns(' ', 4);
	cout << "-with deposits-";
	FillColumns(' ', 4);
	cout << "-accrued through deposits-";
	cout << endl;
	FillColumns('=', 111);

	return investmentData;
}

void DisplayResults(vector<double> stdGrowth, vector<double> growthWithDeposits) {
	// Iterates through calculations and displays corresponding numbers
	for (int year = 0; year < stdGrowth.size(); year++) {
		// Formatting doubles for aligning number columns
		cout << fixed << setprecision(2) << endl;
		FillColumns(' ', 4);
		// Row titled by year
		cout << "Year " << year;
		FillColumns(' ', (10 - (to_string(year).length())));
		// Pointer
		FillColumns('-', 3); FillColumns('>', 1); FillColumns(' ', 20);
		// Std growth numbers
		cout << stdGrowth[year];
		// Separating space
		FillColumns(' ', (26 - (to_string(stdGrowth[year]).length())));
		// Growth with deposit numbers
		cout << growthWithDeposits[year];
		// Separating space
		FillColumns(' ', (23 - (to_string(growthWithDeposits[year]).length())));
		// Displaying difference in growth with vs without deposits
		cout << growthWithDeposits[year] - stdGrowth[year] << endl;
	}
	// Display results footer
	FillColumns('=', 111);
}

// Enter main driver
int main() {

	// Variable to check for program continuation
	string userInput = "yes";

	// While loop to prompt user for program continuation
	while (caseCorrection(userInput) != "NO") {

		/* Create 2 objects to represent the set of standard growth without *
		 * deposits and the set of growth with deposits						*/
		GrowthCalculator StdGrowth;
		GrowthCalculator GrowthWithMonthlyDeposits;

		// Declare investment vector and gather elements
		vector<double> investments = InputMenuDisplay(); // Ex: { 500.0, 50.0, 5.0, 10.0 }

		// Calculate standard growth and growth with deposits into representative variables
		vector<double> stdResults = StdGrowth.CalculateStdGrowth(investments);
		vector<double> depositGrowthResults = GrowthWithMonthlyDeposits.CalculateGrowthWithDeposits(investments);

		// Displays the calculated results in a table of values
		DisplayResults(stdResults, depositGrowthResults);

		// Check for program continuation
		cout << "\n\nEnter \"Yes\" to continue";
		cout << "\nEnter \"No\" to exit the program\n";
		cin >> userInput;
		cout << endl;
	}

	return 0;
}