#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

void hot_potato_game(const string& names, int toss_count) {
    istringstream iss(names);
    queue<string> children;
    string name;

    while (iss >> name) {
        children.push(name);
    }

    while (children.size() > 1) {
        for (int i = 0; i < toss_count - 1; ++i) {
            children.push(children.front());
            children.pop();
        }
        cout << "Removed " << children.front() << endl;
        children.pop();
    }

    cout << "Last is " << children.front() << endl;
}

int main() {
    string names;
    int toss_count;

    cout << "Enter children names: ";
    getline(cin, names);

    cout << "Enter toss count: ";
    cin >> toss_count;

    hot_potato_game(names, toss_count);

    return 0;
}
