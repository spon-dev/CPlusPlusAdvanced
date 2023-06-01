#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    map<string, map<string, vector<string>>> data;
    map<string, vector<string>> continentCountries;
    vector<string> continentOrder;
    string line;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);

        string continent, country, city;
        ss >> continent >> country >> city;

        if (data.find(continent) == data.end()) {
            continentOrder.push_back(continent);
        }

        if (data[continent].find(country) == data[continent].end()) {
            continentCountries[continent].push_back(country);
        }

        data[continent][country].push_back(city);
    }

    for (auto& continent : continentOrder) {
        cout << continent << ":\n";
        for (auto& country : continentCountries[continent]) {
            cout << "  " << country << " -> ";
            for (auto city = data[continent][country].begin(); city != data[continent][country].end(); ++city) {
                if (city != data[continent][country].begin()) cout << ", ";
                cout << *city;
            }
            cout << endl;
        }
    }

    return 0;
}


