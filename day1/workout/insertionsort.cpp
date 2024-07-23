/*
Given an array of integers, sort the array in descending order using the Insertion Sort algorithm.
Input Format
• An integer 'n' representing the number of elements in the array.
• Array elements of n integers.
Output Format
• Print the sorted array in descending order.
• If the array is already sorted in descending order, print -1.
• Print 'Invalid input' if any of the inputs are invalid, such as non- integer values.
Constraints
• 1 ≤ n ≤ 100
• -100 ≤ elements of the array ≤ 100
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
    bool sorted = true;
    int key , j;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        key = arr[i];
        while(j>=0 && arr[j] < key)
        {
            arr[j+1] = arr[j];
            j--;
            sorted = false;
        }
        
        arr[j+1] = key;
    }
    
    if(sorted){
        cout<<-1;
    }else{
        for(int num : arr)
        cout<<num<<" ";
    }
    return 0;
}