/*
#include <iostream>
#include <queue>
#include <sstream>

int main() {
    std::priority_queue<double> numbers;
    std::string line;
    getline(std::cin, line);
    std::istringstream ss(line);

    double number;
    while (ss >> number) {
        numbers.push(number);
    }

    int count = 3;
    while (!numbers.empty() && count > 0) {
        std::cout << numbers.top() << " ";
        numbers.pop();
        count--;
    }

    return 0;
}
*/
#include <iostream>
#include <set>
#include <sstream>

int main() {
    std::multiset<double> numbers;
    std::string line;
    getline(std::cin, line);
    std::istringstream ss(line);

    double number;
    while (ss >> number) {
        numbers.insert(number);
    }

    auto it = numbers.end();
    int count = 3;
    while (it != numbers.begin() && count > 0) {
        --it;
        std::cout << *it << " ";
        count--;
    }

    return 0;
}
