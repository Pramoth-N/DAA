/*
Given a number n, print the nth Fibonacci number. If the input is zero, negative, or non- numeric, return an error response as described below.
Input Format
• A single integer n, representing the position in the Fibonacci sequence.
Output Format
• If the input is valid, print the nth Fibonacci number.
• If n <= 0, print -1.
• If the input is non-numeric, print Invalid input.
Constraints
• Input can be any printable ASCII characters.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    
    int first = 1, second = 1, result = 0;
    for (int i = 3; i <= n; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return second;
}

int main() {
    int n;
    cin >> n;
    
    if (cin.fail()) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    if (n <= 0) {
        cout << "-1" << endl;
        return 0;
    }
    
    cout << fibonacci(n) << endl;
    
    return 0;
}