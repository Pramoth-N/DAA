/*
You are tasked with writing a program that solves a Sudoku puzzle of size N x N, where N is a perfect square (e.g., 4, 9, 16). The Sudoku rules remain the same, but you must
handle varying sizes of Sudoku grids based on user input.
Input Format
• An integer N representing the size of the Sudoku grid (N must be a perfect square).
• An N x N grid representing the Sudoku puzzle where:
• Each cell contains an integer from 0 to Ν.
• A value of 0 represents an empty cell that needs to be filled.
Output Format
• Print the solved Sudoku grid. If no solution exists, print "No solution exists"
• Print Invalid input, if matrix contains value except 0 - 9.
Constraints
• The input grid will always be an N x N matrix.

Input

9
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

Output

5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isValidInput(int N, const vector<vector<int>>& grid) {
    int maxVal = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] < 0 || grid[i][j] > maxVal) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(const vector<vector<int>>& grid, int N, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
        return false;
    }
    
    int sqrtN = sqrt(N);
    int boxRowStart = row - row % sqrtN;
    int boxColStart = col - col % sqrtN;
    
    for (int r = 0; r < sqrtN; r++) {
        for (int d = 0; d < sqrtN; d++) {
            if (grid[r + boxRowStart][d + boxColStart] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& grid, int N) {
    int row = -1, col = -1;
    bool isEmpty = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }
    
    if (!isEmpty) return true;
    
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, N, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, N)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(const vector<vector<int>>& grid, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    if (!isValidInput(N, grid)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    if (solveSudoku(grid, N)) {
        printGrid(grid, N);
    } else {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}
