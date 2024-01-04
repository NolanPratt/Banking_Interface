#include "GrowthCalculator.h"

GrowthCalculator::GrowthCalculator() {
	initAmount = -1;
	monthlyDepo = -1;
	annualInt = -1;
	numYears = -1;
	yearlyGrowth;
}

vector<double> GrowthCalculator::CalculateGrowthWithDeposits(vector<double> dataSet) {
	// Gather data set into discrete variables
	initAmount = dataSet[0];
	monthlyDepo = dataSet[1];
	annualInt = dataSet[2];
	numYears = dataSet[3];

	// Declare summation variables for use in iteration
	double growthWithDeposits = initAmount + monthlyDepo;

	// Enter iteration to calculate each year's investment growth
	for (double year = 0; year <= numYears; year++) {
		if (year > 0) {
			// Yearly increase	  // Interest on current years earnings		 // Sum of deposits		// Interest on deposits
			growthWithDeposits += (growthWithDeposits * (annualInt / 100)) + (monthlyDepo * 12.0) + (monthlyDepo * (annualInt / 100));
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
	double stdGrowth = initAmount;

	for (double year = 0; year <= numYears; year++) {
		if (year > 0)
			stdGrowth += stdGrowth * (annualInt / 100);
		yearlyGrowth.push_back(stdGrowth);
	}
	return yearlyGrowth;
}