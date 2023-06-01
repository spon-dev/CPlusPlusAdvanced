#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

int main() {
    std::string line;
    getline(std::cin, line);
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    std::istringstream iss(line);

    std::set<std::string> words;
    std::string word;
    while (iss >> word) {
        if (word.length() < 5) {
            words.insert(word);
        }
    }

    for (auto it = words.begin(); it != words.end(); ++it) {
        if (it != words.begin()) {
            std::cout << ", ";
        }
        std::cout << *it;
    }

    return 0;
}
