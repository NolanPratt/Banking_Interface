class StackCalculator {
public:
    /**
    * Reads in a mathematical expression as a string and returns the result
    */
	double calculate(const std::string& expression) {
        // Convert the string to a istringstream to convert the numerical values to doubles
		std::istringstream iss(expression);
		std::string token;
		while (iss >> token) {
            // Check if the current token is an operand
			if (isNumber(token)) {
                // Convert the string to a double and push it to the stack
				double number = std::stod(token);
				operandStack.push(number);
			}
            // Check if the current token is an operator
			else if (isOperator(token)) {
                // Error checking to ensure the provided expression is valid
				if (operandStack.size() < 2) {
					throw std::runtime_error("Invalid expression.");
				}
                /**
                * Take the first- and second-inserted operand from the stack and 
                * perform the operation with the current operator token
                */
				else {
					double operand2 = operandStack.top();
					operandStack.pop();
					double operand1 = operandStack.top();
					operandStack.pop();
					double result = performOperation(operand1, operand2, token);
					// Push the result to the back of the stack
                    operandStack.push(result);
				}
			}
            // Error checking to ensure the current operator token is valid
			else {
				throw std::runtime_error("Invalid token in expression.");
			}
		}
        // Error checking to ensure the provided expression is valid
		if (operandStack.size() != 1) {
			throw std::runtime_error("Invalid expression.");
		}
        // Return the evaluation of the expression
		return operandStack.top();
	}

private:
	std::stack<double> operandStack; // Stores the operands

    // Returns true if the provided token is an operand
	bool isNumber(const std::string& str) {
		return((!str.empty()) && str.find_first_not_of("0123456789.") == std::string::npos);
	}

    // Returns true is the provided token is an operator
	bool isOperator(const std::string& str) {
		return str == "+" || str == "-" || str == "*" || str == "/";
	}

    // Evaluates the expression based on the provided operator token
	double performOperation(double operand1, double operand2, const std::string& op) {
		if (op == "+") {
			return operand1 + operand2;
		}
		else if (op == "-") {
			return operand1 - operand2;
		}
		else if (op == "*") {
			return operand1 * operand2;
		}
		else if (op == "/") {
            // Error checking division by zero
			if (operand2 == 0) {
				throw std::runtime_error("Division by zero.");
			}
			return operand1 / operand2;
		}
        // Error if no operator match
		throw std::runtime_error("Invalid operator.");
	}
};

int main() {
	StackCalculator calculator;
	std::string expression;
	std::cout << "Enter a postfix expression: ";
	std::getline(std::cin, expression);

	try {
		double result = calculator.calculate(expression);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}

/*
Output:
Enter a postfix expression: 2 3 +
Result: 5
*/  