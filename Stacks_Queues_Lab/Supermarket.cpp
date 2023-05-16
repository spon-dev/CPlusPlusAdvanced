#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> peopleQueue;
    string input;

    while (true) {
        getline(cin, input);

        if (input == "End") {
            break;
        }
        else if (input == "Paid") {
            while (!peopleQueue.empty()) {
                cout << peopleQueue.front() << endl;
                peopleQueue.pop();
            }
        }
        else {
            peopleQueue.push(input);
        }
    }

    cout << peopleQueue.size() << " people remaining." << endl;

    return 0;
}
