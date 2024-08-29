#pragma once
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <vector>

using namespace std;

class Calculator {
public:
    double Evaluate(args);
    bool TypeCheck(char c);
private:
    std::vector<std::string> CollectInput();
    double ADD(double params);
    double SUBTRACT(double params);
    double MULTIPLY(double params);
    double DIVIDE(double params);
    double ReturnResult(double result);

    double result;
};