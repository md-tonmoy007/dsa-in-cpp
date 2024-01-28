#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPrefix(string infix) {
    stack<char> operators;
    string prefix = "";

    reverse(infix.begin(), infix.end());

    for (char& ch : infix) {
        if (isalnum(ch)) {
            prefix = ch + prefix;
        } else if (ch == ')') {
            operators.push(ch);
        } else if (ch == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix = operators.top() + prefix;
                operators.pop();
            }
            operators.pop(); // Discard the ')'
        } else {
            while (!operators.empty() && precedence(ch) < precedence(operators.top())) {
                prefix = operators.top() + prefix;
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        prefix = operators.top() + prefix;
        operators.pop();
    }

    return prefix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
