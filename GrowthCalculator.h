#pragma once
#include <vector>
using namespace std;

// Header for GrowthCalculator class
class GrowthCalculator {
public:
	vector<double> CalculateStdGrowth(vector<double> dataSet);
	vector<double> CalculateGrowthWithDeposits(vector<double> dataSet);
	double YearsToMonths(double numYears);
	GrowthCalculator();
private:
	double initAmount;
	double monthlyDepo;
	double annualInt;
	double numYears;
	vector<double> yearlyGrowth;
};