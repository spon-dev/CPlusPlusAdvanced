#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<int> secondSet;
    vector<int> firstSet;
    int element;

    // Reading the first set and preserving the order
    for (int i = 0; i < n; i++) {
        cin >> element;
        firstSet.push_back(element);
    }

    // Reading the second set
    for (int i = 0; i < m; i++) {
        cin >> element;
        secondSet.insert(element);
    }

    // Finding and printing the intersection
    unordered_set<int> printed;
    for (const auto& elem : firstSet) {
        // If the element is in the second set and hasn't been printed yet
        if (secondSet.find(elem) != secondSet.end() && printed.find(elem) == printed.end()) {
            cout << elem << " ";
            printed.insert(elem);  // Mark this element as printed
        }
    }

    return 0;
}
