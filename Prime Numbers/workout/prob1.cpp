/*
Given an integer n, you are required to print all prime numbers less than or equal to n using the Sieve of Sundaram algorithm.
Input Format
• A single integer n which represents the upper limit for generating prime numbers.
Output Format
• A single line containing all prime numbers less than or equal to n.
• If the input is invalid (e.g., not an integer or outside the defined range), the program should print "Invalid input"
Constraints
• -10 <= n <= 1000
Sample Input 1:
20
Sample Output 1:
2 
3
5
7
11
13
17
19
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidInput(int n) {
    return n >= 0 && n <= 1000;
}

void sieveOfSundaram(int n) {
    if (n < 2) {
        cout << "No primes exist" << endl;
        return;
    }
    
    int limit = (n - 1) / 2;
    vector<bool> marked(limit + 1, false);
    
    for (int i = 1; i <= limit; i++) {
        for (int j = i; i + j + 2 * i * j <= limit; j++) {
            marked[i + j + 2 * i * j] = true;
        }
    }
    
    cout << 2 << " " << 3 << " "; 
    for (int i = 1; i <= limit; i++) {
        if (!marked[i]) {
            cout << 2 * i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    
    if (!isValidInput(n)) {
        cout << "Invalid input." << endl;
        return 0;
    }
    
    sieveOfSundaram(n);
    return 0;
}