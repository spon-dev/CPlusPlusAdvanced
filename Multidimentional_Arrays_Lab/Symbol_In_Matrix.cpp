#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // Read the size of the square matrix from the input
    cin >> n;

    // Declare the matrix as a 2D vector of chars
    vector<vector<char>> matrix(n, vector<char>(n));

    // Read the matrix elements from the input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Read the symbol to be searched
    char symbol;
    cin >> symbol;

    // Find the first occurrence of the symbol in the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == symbol) {
                cout << "(" << i << ", " << j << ")" << endl;
                return 0;
            }
        }
    }

    // Print error message if the symbol does not occur in the matrix
    cout << symbol << " does not occur in the matrix" << endl;

    return 0;
}
