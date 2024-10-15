/*
Given an N x N maze, the task is to find a path for a rat starting from the top-left corner (0, 0) to the bottom-right corner (N-1, N-1). The rat can only move in two directions: right or down. The maze is represented by a grid where cells with value 1 are open paths, and cells with value 0 are walls that the rat cannot pass through. You need to print a valid solution path if it exists.
Input Format
• The first line contains an integer N, representing the size of the maze.
• The next N lines each contain N integers, where each integer is either 0 (wall) or 1 (path), representing the maze grid.
Output Format
• If a solution exists, print the solution grid, where 1 represents the cells that are part of the path and 0 represents the cells that are not.
• If the input is invalid (e.g., N ≤ 0 or non-integer values or values except 0 and 1), print "Invalid input"
Constraints
• 1 <= N <= 10
Sample Input 1:
4
1000
1101
0100
0111
Sample Output 1:
1000
1100
0100
0111
*/

#include<iostream>
#include<vector>

using namespace std;

bool findPath(vector<vector<bool>> &maze , vector<vector<bool>> &ans , int n , int i , int j , vector<vector<bool>> &v){
    v[i][j] = true;
    ans[i][j] = true;
    if(i==n-1 && j==n-1){
        return true;
    }
    if(j<n-1 && maze[i][j+1] && !v[i][j+1]){
        if(findPath(maze,ans,n,i,j+1,v))
        return true;
    }
    if(i<n-1 && maze[i+1][j] && !v[i+1][j]){
        if(findPath(maze,ans,n,i+1,j,v))
        return true;
    }
    if(i>0 && maze[i-1][j] && !v[i-1][j]){
        if(findPath(maze,ans,n,i-1,j,v))
        return true;
    }
    if(j>0 && maze[i][j-1] && !v[i][j-1]){
        if(findPath(maze,ans,n,i,j-1,v))
        return true;
    }
    ans[i][j] = false;
    v[i][j] = false;
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<bool>> maze(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            if(cin.fail()){
                cout<<"Invalid input";
                return 0;
            }
            maze[i][j] = t;
        }
    }
    vector<vector<bool>> v(n,vector<bool>(n,false));
    vector<vector<bool>> ans(n,vector<bool>(n,false));
    findPath(maze,ans,n,0,0,v);
    
    for(auto row : ans){
        for(int cell : row){
            cout<<cell<<" ";
        }
        cout<<endl;
    }
}