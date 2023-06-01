#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
  
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);

        double value;
        vector<double> input;
        while (ss >> value) {
            input.push_back(value);
        }

        map<double, int> counts;
        vector<double> unique_values;
        for (const auto& val : input) {
            if (counts[val] == 0) {
                unique_values.push_back(val);
            }
            counts[val]++;
        }

        for (const auto& unique_val : unique_values) {
            cout  << unique_val << " - " << counts[unique_val] << " times" << endl;
        }

        cout << endl; // separate the results of each test case
    }

    return 0;
}



