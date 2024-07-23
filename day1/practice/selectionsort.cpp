/*
Given an unsorted array of integers, implement the Selection Sort algorithm to sort the array 
in ascending order and then perform a range query to count the number of elements that fall within a specified range.
Input Format
• An integer 'n' representing the number of elements in the array.
• A line of n integers representing the elements of the array.
• An integer representing the lower bound of the range.
• An integer representing the upper bound of the range.
Output Format
• The sorted array in ascending order.
• The count of elements in the sorted array that are within the range [lower, upper].
• Print 'Invalid input' if any of the inputs are invalid.
• Print-1' if the lower bound of the range is higher than the upper bound of the range.
Constraints
• 1 <= n <= 100
*/

#include<iostream>
using namespace std;
void selectionSort(int* arr ,int n)
{
    
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min] > arr[j])
            min = j;
        }
        if(min != i) {
            swap(arr[min] , arr[i]);
        }
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
    int u,v,cnt =0;
    cin>>u>>v;
    bool sorted = true;
    
    selectionSort(a , n);
    
    for(int x : a) {
        cout<<x<<" ";
        if(x>=u && x<=v)
        cnt++;
    }
    cout<<"\n"<<((cnt>0)? cnt : -1);

    return 0;
}