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

#include "GrowthCalculator.h"
#include "InputMenu.h"

using namespace std;


// Corrects string capitalization for easier input validation
string caseCorrection(string input) {
	string newString;
	for (char character : input) {
		newString += toupper(character);
	}
	return newString;
}

// Enter main driver
int main() {

	// Variable to check for program continuation
	string userInput = "yes";

	// While loop to prompt user for program continuation
	while (caseCorrection(userInput) != "NO") {

		// Create object to represent instance menu for user data gathering
		UserDisplay dataSet;

		/* Create 2 objects to represent the set of standard growth without *
		 * deposits and the set of growth with deposits						*/
		GrowthCalculator StdGrowth;
		GrowthCalculator GrowthWithMonthlyDeposits;

		// Declare investment vector and gather elements
		vector<double> investments = dataSet.InputMenuDisplay(); // Ex: { 500.0, 50.0, 5.0, 10.0 }

		// Calculate standard growth and growth with deposits into representative variables
		vector<double> stdResults = StdGrowth.CalculateStdGrowth(investments);
		vector<double> depositGrowthResults = GrowthWithMonthlyDeposits.CalculateGrowthWithDeposits(investments);

		// Displays the calculated results in a table of values
		dataSet.DisplayResults(stdResults, depositGrowthResults);

		// Check for program continuation
		cout << "\n\nEnter \"Yes\" to continue";
		cout << "\nEnter \"No\" to exit the program\n";
		cin >> userInput;
		cout << endl;
	}

	return 0;
}