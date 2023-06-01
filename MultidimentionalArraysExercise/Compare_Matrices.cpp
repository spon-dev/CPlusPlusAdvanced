#include <iostream>
#include <vector>
#include<sstream>

using namespace std;

bool compareMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size()) {
        return false;
    }
    for (int i = 0; i < matrix1.size(); i++) {
        if (matrix1[i].size() != matrix2[i].size()) {
            return false;
        }
        for (int j = 0; j < matrix1[i].size(); j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> readMatrix(int rows) {
    vector<vector<int>> matrix(rows);

    for (int i = 0; i < rows; i++) {
        string line;
        getline(cin, line);
        istringstream lineStream(line);

        int num;
        while (lineStream >> num) {
            matrix[i].push_back(num);
        }
    }
    return matrix;
}

int main() {
    int rows1, rows2;
    cin >> rows1;
    cin.ignore();
    vector<vector<int>> matrix1 = readMatrix(rows1);

    cin >> rows2;
    cin.ignore();
    vector<vector<int>> matrix2 = readMatrix(rows2);

    if (compareMatrices(matrix1, matrix2)) {
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }
    return 0;
}
