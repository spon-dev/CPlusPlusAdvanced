#include <iostream>
#include <stack>
#include <sstream>

std::string reverseWord(const std::string& word) {
    std::stack<char> wordStack;
    for (const char& c : word) {
        wordStack.push(c);
    }

    std::string reversedWord;
    while (!wordStack.empty()) {
        reversedWord += wordStack.top();
        wordStack.pop();
    }

    return reversedWord;
}

std::string reverseString(const std::string& input) {
    std::istringstream iss(input);
    std::stack<std::string> wordsStack;
    std::string word;

    while (iss >> word) {
        wordsStack.push(reverseWord(word));
    }

    std::string reversedString;
    while (!wordsStack.empty()) {
        reversedString += wordsStack.top() + " ";
        wordsStack.pop();
    }

    // Remove the extra space at the end
    reversedString.pop_back();
    return reversedString;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::string output = reverseString(input);
    std::cout << output << std::endl;

    return 0;
}
