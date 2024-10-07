
/*

Given an array, your task is to transform the array into a max-heap.
 A max- heap is a binary tree where each node's value is greater than or equal to the values of its children, 
 and the tree must be complete.
Input Format
• An integer n represents the size of the array.
• The next line represents the value of the array.
Output Format
• Converts the array into the max heap and prints it.
Constraints
• 1 <= n <= 100

*/

#include<iostream>
#include<vector>
using namespace std;
void maxHeapify(vector<int>& heap , int index , int n){
    int rev = index;
    int left = index*2 + 1 , right = index*2 + 2;
    if(left < n && heap[left] > heap[rev])
    rev = left;
    if(right < n && heap[right] > heap[rev])
    rev = right;
    
    if(rev != index) {
        swap(heap[rev] , heap[index]);
        maxHeapify(heap,rev,n);
    }
}

void heapup(vector<int>&heap , int index){
    if(index<0)
    return;
    int parent = (index-1)/2;
    
    if(heap[index] > heap[parent]){
        swap(heap[index],heap[parent]);
        heapup(heap,parent);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> heap(n);
    for(int i=0;i<n;i++){
        cin>>heap[i];
        heapup(heap ,i);
    }
    for(int x : heap)
        cout<<x<<" ";
}