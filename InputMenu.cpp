#include "InputMenu.h"

UserDisplay::UserDisplay() {
	investmentData;
	initAmount = -1;
	monthlyDepo = -1;
	annualInt = -1;
	numYears = -1;
}

// Displays the input menu and final results table
vector<double> UserDisplay::InputMenuDisplay() {
	FillColumns('*', 37);
	cout << endl;
	FillColumns('-', 8);
	cout << "Enter Investment Data";
	FillColumns('-', 8);
	cout << endl;
	FillColumns('|', 1);

	// Get initAmount with validation
	cout << "Initial Investment: $";
	initAmount = TypeCheck();
	investmentData.push_back(initAmount);
	FillColumns('|', 1);

	// Get monthlyDepo with validation
	cout << "Monthly Deposit: $";
	monthlyDepo = TypeCheck();
	investmentData.push_back(monthlyDepo);
	FillColumns('|', 1);

	// Get annualInt with validation
	cout << "Annual Interest: %";
	annualInt = TypeCheck();
	investmentData.push_back(annualInt);
	FillColumns('|', 1);

	// Get numYears with validation
	cout << "Number of years: ";
	numYears = TypeCheck();
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

// Checks the input data type
double UserDisplay::TypeCheck() {
	double val;
	try {
		cin >> val;
		if (cin.fail()) {
			throw (val);
		}
		if (to_string(val).length() >= 17) {
			throw(val);
		}
	}
	catch (...) {
		cout << "\nInvalid data entry" << endl;
		exit(-99);
	}
	return val;
}

// Checks the calculated val to ensure proper runtime
double UserDisplay::LengthCheck(double val) {
	try {
		if (to_string(val).length() >= 20) {
			throw(val);
		}
	}
	catch (...) {
		cout << "\n\nImproper calculation runtime" << endl;
		exit(-98);
	}
	return val;
}

// Displays calculation results in formatted table of doubles
void UserDisplay::DisplayResults(vector<double> stdGrowth, vector<double> growthWithDeposits) {
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
		LengthCheck(stdGrowth[year]);
		// Separating space
		FillColumns(' ', (26 - (to_string(stdGrowth[year]).length())));
		// Growth with deposit numbers
		cout << growthWithDeposits[year];
		LengthCheck(growthWithDeposits[year]);
		// Separating space
		FillColumns(' ', (23 - (to_string(growthWithDeposits[year]).length())));
		// Displaying difference in growth with vs without deposits
		cout << growthWithDeposits[year] - stdGrowth[year] << endl;
	}
	// Display results footer
	FillColumns('=', 111);
}

// Generates borders with n columns for menu display
void UserDisplay::FillColumns(char c, size_t n) {
	for (size_t i = 0; i < n; i++) {
		cout << c;
	}
}