#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;

    // Read the number of rows and columns from the input
    cin >> rows >> cols;

    // Declare the matrix as a 2D vector
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Read the matrix elements from the input
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate and print the sum of each column
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        cout << sum << endl;
    }

    return 0;
}
