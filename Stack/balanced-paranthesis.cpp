#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string expr) {
    stack<char> stk;

    for (char& ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stk.empty()) {
                return false;
            } else if ((ch == ')' && stk.top() == '(') ||
                       (ch == ']' && stk.top() == '[') ||
                       (ch == '}' && stk.top() == '{')) {
                stk.pop();
            } else {
                return false;
            }
        }
    }

    return stk.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not balanced" << endl;
    }

    return 0;
}
