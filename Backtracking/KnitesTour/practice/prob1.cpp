/*
Given a set of integers and a target sum, determine if there is a subset of the given integers that adds up to the target sum. Implement a function to solve this problem using backtracking.
Input Format
• An integer n represents the number of elements in the list.
• The next line contains the list of n integers.
• An integer target represents the target sum.
Output Format
• If there is at least one subset with the sum equal to the target print True, otherwise
False.
• Print Invalid input for non numerical inputs.
Constraints
1 <= n <= 100
Sample Input 1:
6
3 34 4 12
9
52

Sample Output 1:
True
*/

#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(vector<int>& nums, int n, int target) {
    if (target == 0) return true;
    if (n == 0) return false;
    if (nums[n-1] > target) {
        return isSubsetSum(nums, n-1, target);
    }
    return isSubsetSum(nums, n-1, target) || isSubsetSum(nums, n-1, target - nums[n-1]);
}

int main() {
    int n, target;
    
    cin >> n;
    
    if (n < 1 || cin.fail()) {
        cout << "Invalid input";
        return 0;
    }
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (cin.fail()) {
            cout << "Invalid input";
            return 0;
        }
    }
    
    cin >> target;
    if (cin.fail()) {
        cout << "Invalid input";
        return 0;
    }
    
    if (isSubsetSum(nums, n, target)) {
        cout << "True";
    } else {
        cout << "False";
    }
    
    return 0;
}