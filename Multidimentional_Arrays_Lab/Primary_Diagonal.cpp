#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // Read the size of the square matrix from the input
    cin >> n;

    // Declare the matrix as a 2D vector
    vector<vector<int>> matrix(n, vector<int>(n));

    // Read the matrix elements from the input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate and print the sum of the primary diagonal
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    cout << sum << endl;

    return 0;
}
