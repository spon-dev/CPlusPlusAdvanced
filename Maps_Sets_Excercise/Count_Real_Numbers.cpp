#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    map<double, int> occurrences;
    string line;
    getline(cin, line);
    stringstream ss(line);

    double num;
    while (ss >> num) {
        occurrences[num]++;
    }

  //  cout << fixed << setprecision(2);
    for (auto& pair : occurrences) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
