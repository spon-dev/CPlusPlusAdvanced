#include <iostream>
#include <vector>

using namespace std;

int countEqual2x2Squares(const vector<vector<char>>& matrix) {
    int count = 0;
    for (int i = 0; i < matrix.size() - 1; i++) {
        for (int j = 0; j < matrix[i].size() - 1; j++) {
            if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j] == matrix[i + 1][j] && matrix[i][j] == matrix[i + 1][j + 1]) {
                count++;
            }
        }
    }
    return count;
}

vector<vector<char>> readMatrix(int rows, int cols) {
    vector<vector<char>> matrix(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> matrix = readMatrix(rows, cols);

    int count = countEqual2x2Squares(matrix);

    cout << count << endl;

    return 0;
}
