#pragma once
#include <vector>
using namespace std;

class GrowthCalculator {
public:
	vector<double> CalculateStdGrowth(vector<double> dataSet);
	vector<double> CalculateGrowthWithDeposits(vector<double> dataSet);
	GrowthCalculator();
private:
	double initAmount;
	double monthlyDepo;
	double annualInt;
	double numYears;
	vector<double> yearlyGrowth;
};