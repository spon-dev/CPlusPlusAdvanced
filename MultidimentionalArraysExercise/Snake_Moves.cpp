#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    string snake;

    // Read the dimensions of the matrix and the snake string
    cin >> n >> m >> snake;

    // Declare the matrix as a 2D vector of chars
    vector<vector<char>> matrix(n, vector<char>(m));

    // Fill the matrix with the snake's path
    int snakeIndex = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // Forward direction
            for (int j = 0; j < m; j++) {
                matrix[i][j] = snake[snakeIndex++];
                if (snakeIndex == snake.size()) {
                    snakeIndex = 0; // Restart from the beginning of the snake string
                }
            }
        }
        else { // Reverse direction
            for (int j = m - 1; j >= 0; j--) {
                matrix[i][j] = snake[snakeIndex++];
                if (snakeIndex == snake.size()) {
                    snakeIndex = 0; // Restart from the beginning of the snake string
                }
            }
        }
    }

    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
