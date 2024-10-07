
/*

Given an array of integers. Your task is to convert this array into a min-heap. 
A min-heap is a binary heap where the root element is the minimum element in the heap, 
and each parent node is less than or equal to its children.
Input Format
• An integer n represents the size of the array.
• The next line represents the value of the array.
Output Format
• Converts the array into Min heap and print it.
Constraints
• 1 <= n <= 100

*/


#include<iostream>
#include<vector>
using namespace std;
void minHeapify(vector<int>& heap , int index , int n){
    int rev = index;
    int left = index*2 + 1 , right = index*2 + 2;
    if(left < n && heap[left] < heap[rev])
    rev = left;
    if(right < n && heap[right] < heap[rev])
    rev = right;
    
    if(rev != index) {
        swap(heap[rev] , heap[index]);
        minHeapify(heap,rev,n);
    }
}

void heapup(vector<int>&heap , int index){
    if(index<0)
    return;
    int parent = (index-1)/2;
    
    if(heap[index] < heap[parent]){
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
    // for(int i=n/2-1 ;i>=0;i--) {
    //     minHeapify(heap , i , n);
    // }
    for(int x : heap)
        cout<<x<<" ";
}