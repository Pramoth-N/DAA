/*
You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. Your task is to find the number of ways that you can climb to reach the top.
Input Format
• A single integer n, representing the number of steps in the staircase.
Output Format
• Print the number of distinct ways to climb the stairs.
• If n <= 0, print -1.
• If the input is non-numeric, print Invalid input.
Constraints
• Input can be any printable ASCII characters.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int countWaysToClimbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int first = 1, second = 2, result = 0;
    for (int i = 3; i <= n; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return second;
}

int main() {
    int n ;
    cin >> n;
    if (cin.fail()) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    if (n <= 0) {
        cout << "-1" << endl;
        return 0;
    }
    
    cout << countWaysToClimbStairs(n) << endl;
    
    return 0;
}
