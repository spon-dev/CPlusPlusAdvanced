#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    set<string> elements;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream lineStream(line);

        string element;
        while (lineStream >> element) {
            elements.insert(element);
        }
    }

    for (const auto& element : elements) {
        cout << element << " ";
    }

    return 0;
}
