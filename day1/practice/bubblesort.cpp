/*
Given an array of integers that needs to be sorted, 
implement the function bubblesort that sorts the array based on a user-defined comparator function (ascending or descending).
Input Format
• An integer 'n' represents the number of elements in the array.
• A list of n integers represents the value of the elements.
• A character a or d, where a denotes ascending order and d denotes descending order.
Output Format
• Displays the array after sorting based on the user-defined comparator function.
• Print 'Invalid input' if any invalid characters are entered as the value of the array.
• Print -1 if the array is already sorted.
Constraints
• 1 <= n <= 1000
• The order character should be 'a' or 'd'.
*/

#include<iostream>
using namespace std;
void assendingSort(int* arr ,bool &sorted ,int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
                sorted = false;
            }
        }
        if(!swapped)
        break;
    }
}

void dessendingSort(int* arr, bool &sorted ,int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] < arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
                sorted = false;
            }
        }
        if(!swapped)
        break;
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
    char c;
    cin>>c;
    bool sorted = true;
    if(c =='a')
    {
        assendingSort(a,sorted , n);
    } else if(c=='d'){
        dessendingSort(a,sorted,n);
    } else {
        cout<<"Invalid input";
        return 0;
    }
    if(!sorted)
    for(int x : a) cout<<x<<" ";
    else
    cout<<-1;

    return 0;
}