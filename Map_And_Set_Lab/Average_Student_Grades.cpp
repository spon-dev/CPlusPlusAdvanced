#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    map<string, vector<double>> studentGrades;
    vector<string> order;
    string line;

   
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);

        string name;
        double grade;
        ss >> name >> grade;

        if (studentGrades.find(name) == studentGrades.end()) {
            order.push_back(name);
        }

        studentGrades[name].push_back(grade);
    }

    cout << fixed << setprecision(2);
    for (auto& studentName : order) {
        cout << studentName << " -> ";

        double sum = 0;
        for (auto& grade : studentGrades[studentName]) {
            cout << grade << " ";
            sum += grade;
        }

        double avg = sum / studentGrades[studentName].size();
        cout << "(avg: " << avg << ")" << endl;
    }

    return 0;
}
