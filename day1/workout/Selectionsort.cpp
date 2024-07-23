/*
Given an array of 'n' integers, find and return the kth smallest element using the Selection Sort algorithm.
Input Format
An integer 'n' representing the number of elements in the array.
An array of n integers.
An integer 'k'.
Output Format
Print the kth smallest element in the array.
Print'-1' if all values in the array are the same.
Print 'Invalid input' if any input is invalid, such as non-integer values or out-of-range values for k.
Constraints
• 1 <= n <= 100
The value of k must be within the range from 1 to n
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
    int k;
    cin>>k;
    if(k>=n){
            cout<<"Invalid input";
            return 0;
    }
    bool swapped = false;
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]> arr[j])
            {
                min = j;
            }
        }
        if(min != i){
            swap(arr[min],arr[i]);
            swapped = true;
        }
    }
    if(swapped)
    cout<<arr[k-1];
    else
    cout<<-1;
}