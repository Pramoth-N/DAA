/*
Given an array 'n' of integers, implement the Bubble Sort algorithm to sort the array in ascending order.
Input Format
An integer 'n' representing the number of elements in the array.
Array elements 'arr' of n integers.
Output Format
• A sorted array of 'n' integers in ascending order.
If the array is already sorted, print '-1'.
• If any character is entered as input, print 'Invalid input'.
Constraints
• 1 ≤ n ≤ 100
Each element of the array can be an integer ranging from -100 to 100.
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(cin.fail()){
            cout<<"Invalid input";
            return 0;
        }
    }
    bool sorted = true, swapped;
    for(int i=0;i<n-1;i++)
    {
        swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]> arr[j+1])
            {
                swapped = true;
                sorted = false;
                swap(arr[j],arr[j+1]);
            }
        }
        
        if(!swapped){
            break;
        }
    }
    
    if(sorted){
        cout<<-1;
    }else{
        for(int num : arr)
        cout<<num<<" ";
    }
}