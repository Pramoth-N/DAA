/*
Given an N x N maze, your task is to find all possible paths for a rat to move from the top-left corner (0, 0) to the bottom-right corner (N-1, N-1). The rat can move in four directions: up, down, left, or right. The maze is represented by a grid where cells with value 1 are open paths, and cells with value 0 are walls that the rat cannot pass through. You need to print all valid paths in lexicographical order.
Input Format
• The first line contains an integer N, representing the size of the maze.
• The next N lines each contain N integers, where each integer is either 0 (wall) or 1 (path), representing the maze grid.
Output Format
• If there are valid paths, print each path as a string consisting of directions (U for up, D for down, L for left, and R for right) on a new line.
• If no solution exists, print "No solution exists"
• If the input is invalid (e.g., N ≤ 0 or non-integer values), print "Invalid input"
Constraints
• 1 <= N <= 10
Sample Input 1:
3
101
111
011
Sample Output 1:
DRDR
DRRD

*/

#include<iostream>
#include<vector>

using namespace std;

void compute(const vector<vector<bool>>& maze ,int i, int j,const int &n,const string path ,vector<string>& ans,vector<vector<bool>>& v){
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return ;
    }
    
    v[i][j]= true;
    if(i+1<n && !v[i+1][j] && maze[i+1][j]){
        compute(maze,i+1,j,n,path+"D",ans,v);
    }
    if(j+1<n && !v[i][j+1] && maze[i][j+1]){
        compute(maze,i,j+1,n,path+"R",ans,v);
    }
    if(i>0 && !v[i-1][j] && maze[i-1][j]){
        compute(maze,i-1,j,n,path+"U",ans,v);
    }
    if(j>0 && !v[i][j-1] && maze[i][j-1]){
        compute(maze,i,j-1,n,path+"L",ans,v);
    }
    v[i][j] = false;
}

int main(){
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Invalid input";
        return 0;
    }
    vector<vector<bool>> maze(n,vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            maze[i][j] = t;
        }
    }
    vector<string> ans;
    vector<vector<bool>> v(n,vector<bool>(n,false));
    compute(maze,0,0,n,"",ans,v);
    if(ans.empty()){
        cout<<"No solution exists";
    } else{
        for(string s : ans){
            cout<<s<<"\n";
        }
    }
}