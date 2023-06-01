#include <iostream>
#include <unordered_set>
#include <list>
#include <string>

using namespace std;

int main() {
    unordered_set<string> parkingLot;
    list<string> order;
    string command;

    while (getline(cin, command) && command != "END") {
        string direction = command.substr(0, command.find(','));
        string carNumber = command.substr(command.find(' ') + 1);

        if (direction == "IN") {
            parkingLot.insert(carNumber);
            order.push_back(carNumber);
        }
        else {
            parkingLot.erase(carNumber);
        }
    }

    if (parkingLot.empty()) {
        cout << "Parking Lot is Empty" << endl;
    }
    else {
        for (const auto& car : order) {
            if (parkingLot.find(car) != parkingLot.end()) {
                cout << car << endl;
                parkingLot.erase(car); // ensure we don't print duplicates
            }
        }
    }

    return 0;
}

