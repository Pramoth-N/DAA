/*
Given an integer N, your task is to place N queens on an N x N chessboard such that no two queens threaten each other. A queen can attack another queen if they are on the same row, column, or diagonal. You need to print all possible solutions by placing queens on the board.
Input Format
• A single integer N representing the size of the chessboard and the number of queens to be placed.
Output Format
• If a solution exists, print all possible arrangements of queens on the board. Each arrangement should be printed as an N x N grid where 'l' represents a queen and '0' represents an empty space.
• If no solution exists (i.e., for N = 2 or N = 3), output "No solution exists".
• If the input is invalid (e.g., not an integer or outside the defined range N ≥ 9), print "Invalid input".
Constraints
• 1 <= N <= 20
Example
Sample Input 1:
4
Sample Output 1:
0100
0001
1000
0010
*/

#include<iostream>
#include<vector>

using namespace std;

void dfs(int n , int i, vector<bool>& cols ,vector<bool>& d1 , vector<bool>& d2 , vector<vector<int>>& board , vector<vector<vector<int>>>& ans){
    if(i==n){
        ans.push_back(board);
        return;
    }
    
    for(int j=0;j<n;j++){
        if(cols[j] || d1[i+j] || d2[j-i+n]){
            continue;
        }
        board[i][j] = 1;
        cols[j] = d1[i+j] = d2[j-i+n] = true;
        dfs(n , i+1, cols , d1,d2,board,ans);
        cols[j] = d1[i+j] = d2[j-i+n] = false;
        board[i][j] = 0;
    }
}

int main(){
    int n;
    cin>>n;
    if(n>8){
        cout<<"Invalid input";
        return 0;
    }
    vector<bool> cols(n,false) , dig1(n*2,false) , dig2(n*2, false);
    vector<vector<vector<int>>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    dfs(n , 0, cols , dig1,dig2,board,ans);
    if(ans.empty()){
        cout<<"No solution exists";
    } else {
        for(auto boards : ans){
            for( auto row : boards){
                for(int cell : row){
                    cout<<cell<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
}