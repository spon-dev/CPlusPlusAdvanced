#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    std::string line;
    getline(std::cin, line);

    std::vector<double> numbers;
    std::istringstream iss(line);

    double number;
    while (iss >> number) {
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) {
            std::cout << " <= ";
        }
        std::cout << numbers[i];
    }

    return 0;
}
