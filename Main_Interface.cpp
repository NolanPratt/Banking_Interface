/*
 * 
 * Banking Interface
 * CS 210
 * Nolan Pratt
 * 11/14/2022
 *
 * This program funcitons as a banking interface for the user 
 * to access and manage their financial plans through the 
 * generated menu options.
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "GrowthCalculator.h"

using namespace std;


// Generates borders with n columns for menu display
void FillColumns(char c, size_t n) {
	for (size_t i = 0; i < n; i++) {
		cout << c;
	}	
}

// Rounds inputted double to n decimal places
double RoundDouble(double num, double n = 0.01) {
	return round(num / n) * n;
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
	cout << "Number of months: ";
	cin >> numYears;
	investmentData.push_back(numYears);

	FillColumns('-', 37);
	cout << endl;
	FillColumns('*', 82);
	cout << endl;

	// Display header
	FillColumns(' ', 1);
	cout << "Accrued Balance with Interest by Year";
	FillColumns(' ', 3);
	cout << "-without deposits-";
	FillColumns(' ', 4);
	cout << "-with deposits-";
	FillColumns(' ', 2);
	cout << endl;
	FillColumns('=', 82);

	return investmentData;
}

// Enter main driver
int main() {

	/* Create 2 objects to represent the set of standard growth without *
	 * deposits and the set of growth with deposits						*/
	GrowthCalculator StdGrowth;
	GrowthCalculator GrowthWithMonthlyDeposits;

	// Declare investment vector and gather elements
	vector<double> investments = InputMenuDisplay(); // Ex: { 500.0, 50.0, 5.0, 10.0 }

	// Calculate standard growth and growth with deposits into representative variables
	vector<double> results = StdGrowth.CalculateStdGrowth(investments);
	vector<double> depositGrowthResults = GrowthWithMonthlyDeposits.CalculateGrowthWithDeposits(investments);

	// Iterates through calculatiosn and displays corresponding numbers
	for (int year = 0; year < results.size(); year++) {
		cout << fixed << setprecision(2) << endl;
		FillColumns(' ', 4);
		cout << "Year " << year;
		FillColumns(' ', (10-(to_string(year).length()))); //34
		FillColumns('-', 3);
		FillColumns('>', 1);
		FillColumns(' ', 20);
		cout << RoundDouble(results[year]);
		FillColumns(' ', (24 - (to_string(results[year]).length())));
		cout << RoundDouble(depositGrowthResults[year]) << endl;
	}
	FillColumns('=', 82);

	return 0;
}