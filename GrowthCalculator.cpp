#include "GrowthCalculator.h"

GrowthCalculator::GrowthCalculator() {
	initAmount = -1;
	monthlyDepo = -1;
	annualInt = -1;
	numYears = -1;
	yearlyGrowth;
}

/* Calculates the annual growth with deposits based on entered parameters *
 * returns each yearly increase as an ascending double vector             */
vector<double> GrowthCalculator::CalculateGrowthWithDeposits(vector<double> dataSet) {
	// Gather data set into discrete variables
	initAmount = dataSet[0];
	monthlyDepo = dataSet[1];
	annualInt = dataSet[2];
	numYears = dataSet[3];

	// Declare summation variables for use in iteration
	double growthWithDeposits = 0.0;
	double deposits = 0.0;

	// Enter iteration to calculate each year's investment growth
	for (double year = 0; year <= numYears; year++) {
		growthWithDeposits = ((initAmount + deposits) * (pow((1.0 + ((annualInt / 100.0) / 12.0)), year * 12.0)));
		// Accounting for monthly deposits
		for (double month = 1; month <= 12; month++) {
			deposits += monthlyDepo;
		}
		yearlyGrowth.push_back(growthWithDeposits);
	}
	return yearlyGrowth;
}

/* Calculates the annual growth without deposits based on entered parameters *
 * returns each yearly increase as an ascending double vector                */
vector<double> GrowthCalculator::CalculateStdGrowth(vector<double> dataSet) {
	// Gather data set into discrete variables
	initAmount = dataSet[0];
	annualInt = dataSet[2];
	numYears = dataSet[3];

	// Declare summation variable for use in iteration
	double stdGrowth = 0.0;

	for (double year = 0; year <= numYears; year++) {
		stdGrowth = (initAmount * (pow((1.0 + ((annualInt / 100.0) / 12.0)), year * 12.0)));
		yearlyGrowth.push_back(stdGrowth);
	}
	return yearlyGrowth;
}