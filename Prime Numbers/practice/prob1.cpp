/*
Given an integer n, print all odd prime numbers less than or equal to n using the Sieve of Sundaram algorithm.
Input Format
• A single integer n, which represents the upper limit for generating odd prime numbers.
Output Format
• A single line containing all odd prime numbers less than or equal to n.
• If the input is invalid (e.g., not an integer or negative), the program should print
"Invalid input"
Constraints
• -10 <= n <= 100
Sample Input 1:
40
Sample Output 1:
3
5
7
11
13
17
19
23
29
31
37
*/


#include <iostream>
#include <vector>
using namespace std;

bool isValidInput(int n) {
    return n >= 0 && n <= 100;
}

void sieveOfSundaram(int n) {
    int limit = (n - 1) / 2;
    vector<bool> marked(limit + 1, false);
    
    for (int i = 1; i <= limit; i++) {
        for (int j = i; i + j + 2 * i * j <= limit; j++) {
            marked[i + j + 2 * i * j] = true;
        }
    }
    
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
        cout << "Invalid input" << endl;
        return 0;
    }
    
    sieveOfSundaram(n);
    return 0;
}
