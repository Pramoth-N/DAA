/*
Given an integer N, your task is to determine how many distinct ways you can place N queens on an N x N chessboard such that no two queens threaten each other. A queen can attack another queen if they are on the same row, column, or diagonal. You are only required to count the number of valid solutions, without printing the boards.
Input Format
• A single integer N representing the size of the chessboard and the number of queens to be placed.
Output Format
• A single integer that represents the total number of valid solutions for placing N queens on the chessboard.
• If the input is invalid (e.g., not an integer or outside the defined range N ≥ 4), print
"Invalid input"
Constraints
• -10 <= N <= 10
Sample Input 1:
6

Sample Output 1:
4
*/

#include<iostream>
#include<vector>

using namespace std;

int dfs(int i,const int& n , vector<bool>& cols , vector<bool>& d1 , vector<bool>& d2){
    if(i==n)
        return 1;
    int result = 0;
    for(int j=0;j<n;j++){
        if(!cols[j] && !d1[i+j] && !d2[j-i+n]){
            cols[j] = d1[i+j] = d2[j-i+n] = true;
            result += dfs(i+1,n,cols,d1,d2);
            cols[j] = d1[i+j] = d2[j-i+n] = false;
        }
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    if(cin.fail()||n<=0){
        cout<<"Invalid input";
        return 0;
    }
    vector<bool> cols(n,false) , d1(n*2,false) , d2(n*2,false);
    cout<<dfs(0,n,cols,d1,d2);
}