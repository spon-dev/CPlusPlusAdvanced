#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void printPositions(const vector<vector<int>>& matrix, int number) {
    bool found = false;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == number) {
                cout << i << ' ' << j << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "not found" << endl;
    }
}

vector<vector<int>> readMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    int rows, cols, number;
    cin >> rows >> cols;

    vector<vector<int>> matrix = readMatrix(rows, cols);

    cin >> number;

    printPositions(matrix, number);

    return 0;
}
