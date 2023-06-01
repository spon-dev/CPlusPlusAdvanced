#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    unordered_map<string, int> wordOccurrences;
    list<string> order;
    string line;
    getline(cin, line);
    stringstream ss(line);

    string word;
    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (wordOccurrences.find(word) == wordOccurrences.end()) {
            order.push_back(word);
        }
        wordOccurrences[word]++;
    }

    bool firstWord = true;
    for (const auto& word : order) {
        if (wordOccurrences[word] % 2 != 0) {
            if (!firstWord) {
                cout << ", ";
            }
            cout << word;
            firstWord = false;
        }
    }

    return 0;
}
