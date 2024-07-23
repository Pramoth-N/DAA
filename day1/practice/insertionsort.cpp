/*
Given a list of integers, implement the Insertion Sort algorithm to sort the list in ascending order.
Input Format
• An integer 'n' represents the number of elements in the list.
• A list of n integers represents the value of elements.
Output Format
• Displays the list in ascending order.
• Print 'Invalid input', if a character is entered as input.
• Print -1, if the list is already sorted.
Constraints
• 1 ≤ n ≤ 100
• Each element of the list can be an integer.
*/

#include<iostream>
using namespace std;
void insertionSort(int* arr ,bool &sorted ,int n)
{
    
    for(int i=1;i<n;i++)
    {
        int key = arr[i] , j = i-1;
        
        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
            sorted = false;
        }
        arr[++j] = key;
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(cin.fail()){
            cout<<"Invalid input";
            return 0;
        }
    }
    
    bool sorted = true;
    
    insertionSort(a,sorted , n);
    
    if(!sorted)
    for(int x : a) cout<<x<<" ";
    else
    cout<<-1;
}