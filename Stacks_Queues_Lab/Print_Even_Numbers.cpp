#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

void print_even_numbers(const string& input) {
    istringstream iss(input);
    queue<int> numQueue;
    int num;

    while (iss >> num) {
        numQueue.push(num);
    }

    bool isFirst = true;
    while (!numQueue.empty()) {
        if (numQueue.front() % 2 == 0) {
            if (!isFirst) {
                cout << ", ";
            }
            isFirst = false;
            cout << numQueue.front();
        }
        numQueue.pop();
    }

    cout << endl;
}

int main() {
    string input;
    cout << "Enter a list of numbers: ";
    getline(cin, input);

    print_even_numbers(input);

    return 0;
}
