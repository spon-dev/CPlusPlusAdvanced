#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool isPerfectSquare(int number) {
    int root = sqrt(number);
    return root * root == number;
}

int main() {
    multiset<int, greater<int>> squareNumbers;
    string line;

    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        int number;

        while (ss >> number) {
            if (isPerfectSquare(number)) {
                squareNumbers.insert(number);
            }
        }
    }

    for (const auto& n : squareNumbers) {
        cout << n << " ";
    }

    return 0;
}
