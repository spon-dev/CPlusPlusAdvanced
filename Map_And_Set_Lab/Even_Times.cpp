#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> counts;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        counts[num]++;
    }

    for (auto& pair : counts) {
        if (pair.second % 2 == 0) {
            cout << pair.first << endl;
            break;
        }
    }

    return 0;
}
