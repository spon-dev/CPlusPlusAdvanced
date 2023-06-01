#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n;
    unordered_set<string> uniqueNames;
    vector<string> namesOrder;
    string name;

    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name;
        if (uniqueNames.find(name) == uniqueNames.end()) {
            uniqueNames.insert(name);
            namesOrder.push_back(name);
        }
    }

    for (const auto& name : namesOrder) {
        cout << name << endl;
    }

    return 0;
}
