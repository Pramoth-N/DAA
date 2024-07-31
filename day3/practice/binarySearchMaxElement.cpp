/*


Given a array, find and return the maximum element in this array.
Input Format
• An integer n represents the size of the array.
• The next line contains n integers representing the value of the array.
Output Format
• Displays the maximum element in an array.
• Print Invalid input, if any non-numeric input presents.
• Print -1, if all the elements in an array are same.
Constraints
• 1 <= n <= 100


*/


#include<iostream>
using namespace std;


int maxElement(int* nums ,int left , int right  ) {
    if(nums[right] > nums[left])
    return nums[right];
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(nums[mid+1] < nums[mid] ){
            return nums[mid];
        }
        if(nums[mid-1] > nums[mid] ){
            return nums[mid-1];
        }
        if(nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return nums[right];
}

int main() {
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        if(cin.fail()) {
            cout<<"Invalid input";
            return 0;
        }
    }
    if(nums[0] == nums[n-1]){
        cout<<-1;
    }else {
        cout<<maxElement(nums ,0, n-1);
    }
}