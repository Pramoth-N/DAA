/*
Given a chessboard of size N x N, a knight is initially placed at position (startX, startY) on the board. Your task is to find the minimum number of moves required for the knight to reach the position (targetX, targetY).
A knight can move in an L-shape: two squares in one direction and then one square perpendicular to that direction, or one square in one direction and then two squares perpendicular to that direction.
Input Format
• An integer N represents the size of the chessboard.
• Next line contains two integers x and y, represents the starting position.
• Next line contains two integers x and y, represent the target position.
Output Format
• Print the minimum number of moves required for the knight to reach the target position from the starting position.
• Print Invalid input, if target position is out of the range.
Constraints
1 <= N <= 8
Sample Input 1:
8
0 0
7 7

Sample Output 1:
6
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Position {
    int x, y, dist;
};

bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int minKnightMoves(int N, int startX, int startY, int targetX, int targetY) {
    if (!isValid(targetX, targetY, N)) {
        return -1;
    }
    
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    
    queue<Position> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        Position p = q.front();
        q.pop();
        
        if (p.x == targetX && p.y == targetY) {
            return p.dist;
        }
        
        for (int i = 0; i < 8; i++) {
            int newX = p.x + dx[i];
            int newY = p.y + dy[i];
            
            if (isValid(newX, newY, N) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY, p.dist + 1});
            }
        }
    }
    
    return -1;
}

int main() {
    int N;
    cin >> N;
    
    if (N < 1 || N > 8 || cin.fail()) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    int startX, startY, targetX, targetY;
    cin >> startX >> startY >> targetX >> targetY;
    
    if (startX < 0 || startY < 0 || targetX < 0 || targetY < 0 ||
    startX >= N || startY >= N || targetX >= N || targetY >= N || cin.fail()) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    int result = minKnightMoves(N, startX, startY, targetX, targetY);
    
    if (result == -1) {
        cout << "Invalid input" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}