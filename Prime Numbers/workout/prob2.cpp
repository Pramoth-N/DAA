/*
Given an integer n, count the number of prime numbers less than n using the Sieve of Sundaram algorithm.
Input Format
• A single integer n, which represents the upper limit for counting prime numbers.
Output Format
• A single integer representing the count of prime numbers less than n.
• If the input is invalid (e.g., not an integer or outside the defined range), the program should print "Invalid input"
Constraints
-10 <= n <= 150
Sample Input 1:
20
Sample Output 1:
8
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidInput(int n) {
    return n >= 0 && n <= 1000;
}

int sieveOfSundaram(int n) {
    if (n < 2) {
        cout << "No primes exist" << endl;
        return 0;
    }
    
    int limit = (n - 1) / 2;
    vector<bool> marked(limit + 1, false);
    
    for (int i = 1; i <= limit; i++) {
        for (int j = i; i + j + 2 * i * j <= limit; j++) {
            marked[i + j + 2 * i * j] = true;
        }
    }
    
    int count = 2;
    for (int i = 1; i <= limit; i++) {
        if (!marked[i]) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    if (!isValidInput(n)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    cout << sieveOfSundaram(n);
    return 0;
}