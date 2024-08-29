#include "Calculator.h"

Calculator::Calculator() {
    result = -1;
}

// Read in the user inputs into an equation
String[] Calculator::CollectInput() {
    // Define buffer variables
    std::string[] equation;
    std::string num;

    // Loop to collect all user inputs
    do {
        if (input.TypeCheck("double")) {
            num += input;
        }
        else {
            equation.add(num);
            equation.add(input);
            num = "";
        }
    } while(input);
    return equation; // Example: ["123", "+", "456"]
}

// Reference necessary mathematical methods to evaluate the user's equation
double Calculator::Evaluate(std::vector<std::string> equation) {
    // Loop through the aggregated strings from the parsed equation
    for (int i = 0; i < equation.size(); ++i) {
        // Determine the type of symbol present within the current vector location
        if (element.TypeCheck(element.at(i)) == true) {
            
        }
    }
}

// Check whether the passed character is a numerical value or mathematical operator
bool Calculator::TypeCheck(char& c) {

}

double Calculator::ADD(double[] nums) {
    for (double num : nums) {
        result += num;
    }
    return result;
}

double Calculator::SUBTRACT(double[] nums) {
    for (double num : nums) {
        result -= num;
    }
    return result;
}

double Calculator::MULTIPLY(double[] nums) {
    for (double num : nums) {
        result *= num;
    }
    return result;
}

double Calculator::DIVIDE(double[] nums) {
    for (double num : nums) {
        result /= num;
    }
    return result;
}