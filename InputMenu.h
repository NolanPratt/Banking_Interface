#pragma once
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <vector>
using namespace std;

class UserDisplay {
public:
	vector<double> InputMenuDisplay();
	double TypeCheck();
	double LengthCheck(double val);
	double ValCheck(double val);
	void DisplayResults(vector<double> stdGrowth, vector<double> growthWithDeposits);
	void FillColumns(char c, size_t n);
	UserDisplay();
private:
	vector<double> investmentData;
	double initAmount;
	double monthlyDepo;
	double annualInt;
	double numYears;
};

