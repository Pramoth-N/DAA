/*
You are given a partially filled 9x9 Sudoku grid. Your task is to write a program that solves the Sudoku puzzle using backtracking. A valid Sudoku solution must satisfy the following conditions:
Each row contains the digits from 1 to 9 without repetition.
Each column contains the digits from 1 to 9 without repetition.
Each of the nine 3x3 subgrids (also known as boxes) contains the digits from 1 to 9 without repetition.
Input Format
• A 9x9 grid representing the Sudoku puzzle where:
• Each cell contains an integer from 0 to 9.
• A value of 0 represents an empty cell that needs to be filled.
Output Format
• Print the solved Sudoku grid. If no solution exists, print "No solution exists"
• Print "Invalid input" if input contains values less than 0 or greater than 9.
Constraints
• The input grid will always be a 9x9 matrix.
Sample Input 1:
Sample Output 1:

Input

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
using namespace std;

#define N 9

bool isValidInput(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] < 0 || grid[i][j] > 9) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
    if (row == N - 1 && col == N) {
        return true;
    }
    if (col == N) {
        row++;
        col = 0;
    }
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }
    
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    
    return false;
}

void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    if (!isValidInput(grid)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}