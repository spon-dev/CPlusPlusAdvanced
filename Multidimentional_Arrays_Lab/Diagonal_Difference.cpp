#include <iostream>
#include <vector>
#include <cmath>

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

    // Calculate the sum of the primary and secondary diagonals
    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        primaryDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][n - i - 1];
    }

    // Calculate and print the absolute difference between the sums of the diagonals
    cout << abs(primaryDiagonalSum - secondaryDiagonalSum) << endl;

    return 0;
}
