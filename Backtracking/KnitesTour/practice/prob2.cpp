/*
You are given a list of integers and a target sum. Your task is to find all unique combinations in the list where the sum of the elements equals the target. Each number in the list may be used multiple times in the combination. Implement a function to return all possible combinations that add up to the target sum.
Input Format
• An integer n represents the number of elements in the list.
• The next line contains the list of n integers representing the available numbers (candidates).
• An integer target representing the target sum.
Output Format
• Print all possible combinations that add up to the target sum.
• Print Invalid input, if any input is non numeric.
Constraints
1 <= n <= 100
Sample input 1:
4
2 3 6 7
7
Sample Output 1:
[2 2 3]
[7]
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], current, result, i);
            current.pop_back();
        }
    }
}

int main() {
    int n, target;
    cin >> n;
    
    if (n < 1 || cin.fail()) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    vector<int> candidates(n);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
        if (cin.fail()) {
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    
    cin >> target;
    if (cin.fail()) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    vector<vector<int>> result;
    vector<int> current;
    
    findCombinations(candidates, target, current, result, 0);
    
    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        for (auto& combination : result) {
            cout << "[ ";
            for (int i = 0; i < combination.size(); i++) {
                cout << combination[i]<<" ";
            }
            cout << "]" << endl;
        }
    }
    
    return 0;
}