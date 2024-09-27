from collections import deque
import re

class calculator:
    # Evaluates the passed expression
    def calculate(self, expression):
        # Convert infix expression to RPN
        rpn_expression = self.infix_to_rpn(expression)
        
        # Define a stack to store operands
        operandStack = deque()

        # Tokenize the RPN expression by spaces
        tokens = rpn_expression.split()

        # Process each token in the RPN expression
        for token in tokens:
            # Check if the token is a number
            if self.isNumber(token):
                # Assign the number as a float and add it to the stack
                num = float(token)
                operandStack.append(num)

            # Check if the token is an operator
            elif self.isOperator(token):
                # Error check for a valid expression (Cannot operate with one operand)
                if len(operandStack) < 2:
                    raise ValueError("Invalid Expression: requires two or more operands")
                else:
                    # Assign the two top operands and pop them from the stack for evaluation
                    operand2 = operandStack.pop()
                    operand1 = operandStack.pop()

                    # Store the resultant operation for storage within the operand stack
                    result = self.perform_operation(operand1, operand2, token)
                    operandStack.append(result)

        # The final result should be the only element left in the stack
        if len(operandStack) != 1:
            raise ValueError("Invalid Expression: check syntax")

        return operandStack.pop()

    # Performs the binary operation based on the passed operator
    def perform_operation(self, operand1, operand2, operator):
        if operator == '+':
            return operand1 + operand2
        elif operator == '-':
            return operand1 - operand2
        elif operator == '*':
            return operand1 * operand2
        elif operator == '/':
            if operand2 == 0:
                raise ValueError("Invalid Expression: division by zero")
            return operand1 / operand2
        else:
            raise ValueError("Invalid Expression: unexpected operator")

    def isNumber(token):
        # Regular expression to match a valid integer or float number
        return bool(re.match(r'^-?\d+(\.\d+)?$', token))
    
    # Returns true if the passed token is an operator 
    def isOperator(self, token):
        return token in "+-*/"

    # Converts infix expression to Reverse Polish Notation (RPN)
    def infix_to_rpn(self, expression):
        # Precedence map for operators
        precedence = {'+': 1, '-': 1, '*': 2, '/': 2}
        output = []  # Output list for the RPN expression
        operator_stack = []  # Stack for operators
        i = 0  # Index to traverse the expression

        # While the expression is still being read
        while i < len(expression):
            # Iterate through each character within the expression
            char = expression[i]

            # Check if the current character is an integer or decimal
            if char.isdigit() or char == '.':
                num = char
                i += 1
                # Append the following operands to a string until reaching a non-operand
                while i < len(expression) and (expression[i].isdigit() or expression[i] == '.'):
                    num += expression[i]
                    i += 1
                # Append the concatenated operand to the output list
                output.append(num)
                # Skip the increment of i to avoid double counting
                continue

            # Check if the current character is an operator
            elif char in precedence:
                # Append the popped operator from the stack while the stack is populated with operators and the current operator takes precedence
                while (operator_stack and operator_stack[-1] in precedence and precedence[char] <= precedence[operator_stack[-1]]):
                    output.append(operator_stack.pop())
                # Append the current operator to the operator stack
                operator_stack.append(char)

            # Check if the current character is a left parenthesis
            elif char == '(':
                operator_stack.append(char)

            # Check if the current character is a right parenthesis
            elif char == ')':
                while operator_stack and operator_stack[-1] != '(':
                    output.append(operator_stack.pop())
                operator_stack.pop()  # Pop the '(' itself

            # Increment index to process next character
            i += 1

        # Pop all remaining operators in the stack to output
        while operator_stack:
            output.append(operator_stack.pop())

        return ' '.join(output)  # Return the RPN expression as a single string