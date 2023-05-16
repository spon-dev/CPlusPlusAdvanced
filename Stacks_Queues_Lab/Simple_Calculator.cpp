#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int calculate(const string& expression) {
    stack<int> numStack;
    istringstream iss(expression);
    int num;
    char op;

    iss >> num;
    numStack.push(num);

    while (iss >> op >> num) {
        if (op == '+') {
            numStack.push(num);
        }
        else if (op == '-') {
            numStack.push(-num);
        }
    }

    int result = 0;
    while (!numStack.empty()) {
        result += numStack.top();
        numStack.pop();
    }

    return result;
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    int result = calculate(expression);
    cout << "Result: " << result << endl;

    return 0;
}
