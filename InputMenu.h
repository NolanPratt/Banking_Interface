#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class UserDiplay {
public:
	vector<double> InputMenuDisplay();
	void DisplayResults(vector<double> stdGrowth, vector<double> growthWithDeposits);
	void FillColumns(char c, size_t n);
	UserDiplay();
private:
	vector<double> investmentData;
	double initAmount;
	double monthlyDepo;
	double annualInt;
	double numYears;
};

