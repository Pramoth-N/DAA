/*
Imagine a treasure hunt where you have several numbered keys, each with a specific value. Your goal is to find how many unique combinations of keys can open a magical chest, but the catch is- the total value of the keys must exactly match the target number to unlock it.
Input Format
• First line contains an integer n (number of elements in the set).
• Second line contains n integers representing the elements of the set.
• Third line contains an integer target (the target sum).
Output Format
• Print the count of subsets that sum up to the target sum.
• Print Invalid input, if input contains negative integers.
Constraints
• 1 ≤ n ≤ 10
Sample Input 1:
Sample Output 1:
5
3
12345
5
*/

#include<iostream>
#include<vector>

using namespace std;

int subsetSum(const vector<int>& nums ,const int& target){
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1 , 0))
;
    for(int i=0;i<=n;dp[i++][0] = 1);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
    }
    
    return dp[n][target];
}

int main(){
    int n ,target;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i] < 0){
            cout<<"Invalid input";
            return 0;
        }
    }
    cin >> target;
    cout << subsetSum(nums , target);
}


//Alternate solution

int subsetSum(vector<int> &nums, int target){
    int n = nums.size();
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=target;j>=0;j--){
            if(j-nums[i] >= 0){
                dp[j] = dp[j - nums[i]] + dp[j];
            }
        }
    }
    return dp[target];
}