#include<iostream>
#include<vector>

using namespace std;
    vector<vector<int>> moves = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    vector<pair<int,int>> ans;
bool isValid(int x , int y, vector<vector<int>>& board){
    int n = board.size();
    return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
}
bool knitesTour(int i,int j,int total_moves,vector<vector<int>>& board){
    if(total_moves == board.size()*board.size()){
        return true;
    }
    for(int k=0;k<8;k++){
        int x = i+moves[k][0];
        int y= j+moves[k][1];
        if(isValid(x ,y ,board)){
            board[x][y] = total_moves;
            ans.push_back({x,y});
            if(knitesTour(x, y, total_moves + 1,board)){
              return true; 
            }
            ans.pop_back();
            board[x][y] = -1;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    if(cin.fail()){
        cout<<"Invalid input";
        return 0;
    }
    
    vector<vector<int>> board(n,vector<int>(n,-1));
    board[0][0] = 0;
    ans.push_back({0,0});
    if(knitesTour(0,0,1,board))
    for(auto tuple : ans){
        cout<<"("<<tuple.first<<", "<<tuple.second<<") ";
    }
    else cout<<"None";
}