#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    istringstream iss(input);
    int num;
    stack<int> numStack;

    while (iss >> num) {
        numStack.push(num);
    }

    string command;
    int num1, num2;
    while (true) {
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input == "end") {
            break;
        }

        istringstream cmdStream(input);
        cmdStream >> command;

        if (command == "add") {
            cmdStream >> num1 >> num2;
            numStack.push(num1);
            numStack.push(num2);
        }
        else if (command == "remove") {
            cmdStream >> num1;
            if (num1 <= numStack.size()) {
                while (num1-- > 0) {
                    numStack.pop();
                }
            }
        }
    }

    int sum = 0;
    while (!numStack.empty()) {
        sum += numStack.top();
        numStack.pop();
    }

    cout << "Sum: " << sum << endl;

    return 0;
}
