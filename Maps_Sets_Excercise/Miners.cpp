#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> resources;
    vector<string> resourceOrder;
    string line;
    string currentResource;
    bool isResource = true;

    while (getline(cin, line) && line != "stop") {
        if (isResource) {
            currentResource = line;
            if (resources.find(currentResource) == resources.end()) {
                resources[currentResource] = 0;
                resourceOrder.push_back(currentResource);
            }
        }
        else {
            int quantity = stoi(line);
            resources[currentResource] += quantity;
        }
        isResource = !isResource;
    }


    for (const auto& resource : resourceOrder) {
        cout << resource << " -> " << resources[resource] << endl;
    }

    return 0;
}
