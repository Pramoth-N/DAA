#include<iostream>

using namespace std;


int main() {
    int n;
    cin>>n;
    
    int weight ,val , max_val = 0;
    for(int i=0;i<n;i++){
        cin>>weight>>val;
        if(weight==1){
            max_val = max(max_val,val);
        }
    }
    
    
    if(max_val){
        cout<< max_val;
    } else {
        cout << "Invalid input";
    }
}