#include "InputMenu.h"

UserDiplay::UserDiplay() {
	investmentData;
	initAmount = -1;
	monthlyDepo = -1;
	annualInt = -1;
	numYears = -1;
}

// Displays the input menu and final results table
vector<double> UserDiplay::InputMenuDisplay() {
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
	cin >> monthlyDepo;
	investmentData.push_back(monthlyDepo);
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

void UserDiplay::DisplayResults(vector<double> stdGrowth, vector<double> growthWithDeposits) {
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

// Generates borders with n columns for menu display
void UserDiplay::FillColumns(char c, size_t n) {
	for (size_t i = 0; i < n; i++) {
		cout << c;
	}
}