#include<iostream>
#include<vector>

using namespace std;

bool isValid(int x , int y , int tx , int ty , int n){
    if(tx < 0 || ty<0 || tx>=n || ty >= n)
    return false;
        int dx = abs(tx-x);
        int dy = abs(ty-y);
        return((dx==2 && dy ==1 )|| (dx == 1 && dy ==2));
}
int main(){
    int n;
    cin>>n;
    if(cin.fail() || n<=0){
        cout<<"Invalid input";
        return 0;
    }
    int i,j,x,y;
    cin>>i>>j>>x>>y;
    if(isValid(i,j,x , y,n))
        cout<<"True";
    else cout<<"False";
}