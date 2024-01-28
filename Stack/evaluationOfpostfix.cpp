#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> operands;

    for (char& ch : postfix) {
        if (isdigit(ch)) {
            operands.push(ch - '0');
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (ch) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid operator" << endl;
                    return -1;
            }
        }
    }

    return operands.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
