#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluatePrefix(string prefix) {
    stack<int> operands;

    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            operands.push(ch - '0');
        } else if (isspace(ch)) {
            // Skip whitespaces
            continue;
        } else {
            int operand1 = operands.top();
            operands.pop();
            int operand2 = operands.top();
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
    string prefix;
    cout << "Enter a prefix expression: ";
    getline(cin, prefix);

    int result = evaluatePrefix(prefix);
    cout << "Result: " << result << endl;

    return 0;
}
