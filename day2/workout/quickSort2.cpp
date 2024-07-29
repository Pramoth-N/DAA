/*

Given a list of the Person's 'age' (integer) and 'height' (floating-point). Implement a Quick Sort algorithm using the median-of-three method to select the pivot. Your task is to sort the list based on user-specified criteria using this custom sorting algorithm.
Input Format
• An integer n represents the number of Persons.
• The next set of inputs contains the age and height of each person,
age: An integer representing the age of the person.
height: A floating-point number representing the height of the person.
An integer representing the sorting criterion, 1 for age and 2 for height.
Output Format
• Displays the sorted list of people, formatted as • Age: {age}, Height: {height}
• If any non-numerical input present, print Invalid input.
• If the array is already sorted based on the chosen criterion, print -1.
Constraints
• 1 <= n <= 100

*/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int agePartition(vector<pair<int,double>>& nums ,int low ,int high){
    int pivot = nums[high].first , index = low-1;
    
    for(int i=low;i<high;++i) {
        if(nums[i].first <= pivot) {
            swap(nums[++index] ,nums[i]);
        }
    }
    
    swap(nums[++index] , nums[high]);
    return index;
}

int hightPartition(vector<pair<int,double>>& nums ,int low ,int high){
    int pivot = nums[high].second , index = low-1;
    
    for(int i=low;i<high;++i) {
        if(nums[i].second <= pivot) {
            swap(nums[++index] ,nums[i]);
        }
    }
    
    swap(nums[++index] , nums[high]);
    return index;
}

void quickSort(vector<pair<int,double>>& nums, int low, int high ,int flag) {
    if(low >= high){
        return;
    }
    int pivot;
    if(flag == 1){
        pivot = agePartition(nums ,low ,high);
    } else {
        pivot = hightPartition(nums ,low ,high);
    }
    quickSort(nums , low ,pivot - 1 , flag);
    quickSort(nums , pivot + 1 ,high ,flag);
}

bool isSorted(vector<pair<int,double>> nums , int flag) {
    if(flag == 1){
        for(int i=1;i<nums.size();i++){
            if(nums[i-1].first > nums[i].first)
            return false;
        }
        return true;
    }
    else{
        for(int i=1;i<nums.size();i++){
            if(nums[i-1].second > nums[i].second)
            return false;
        }
        return true;
    }
}
int main(){
    int n ,flag;
    cin>>n;
    if(n<=0) {
        cout<<"Invalid input";
        return 0;
    }
    vector<pair<int,double>> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i].first;
        cin>>nums[i].second;
        if(cin.fail()) {
            cout<<"Invalid input";
            return 0;
        }
    }
    cin>>flag;
    if(flag != 1 && flag != 2) {
        cout<<"Invalid input";
        return 0;
    }
    if(isSorted(nums ,flag)){
        cout<<-1;
        return 0;
    }
    quickSort(nums, 0, n-1, flag);
    
    for(pair<int,double> num : nums) {
        cout<<"Age: "<<num.first<<" Height: "<<num.second<<endl;
    }
}