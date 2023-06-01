#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    unordered_set<string> uniqueUsernames;
    vector<string> usernamesOrder;
    string username;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> username;
        if (uniqueUsernames.find(username) == uniqueUsernames.end()) {
            uniqueUsernames.insert(username);
            usernamesOrder.push_back(username);
        }
    }

    for (const auto& username : usernamesOrder) {
        cout << username << "\n";
    }

    return 0;
}
