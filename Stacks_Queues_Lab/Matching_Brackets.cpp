#include <iostream>
#include <stack>
#include <string>

using namespace std;

void extract_sub_expressions(const string& expression) {
    stack<size_t> bracket_positions;

    for (size_t i = 0; i < expression.size(); ++i) {
        if (expression[i] == '(') {
            bracket_positions.push(i);
        }
        else if (expression[i] == ')') {
            if (!bracket_positions.empty()) {
                size_t start = bracket_positions.top();
                bracket_positions.pop();
                cout << expression.substr(start, i - start + 1) << endl;
            }
        }
    }
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    extract_sub_expressions(expression);

    return 0;
}
