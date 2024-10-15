/*
Given two integers P and k, find the sum of the next k prime numbers greater than P using the Sieve of Eratosthenes.
Input Format
• Two integers P and k, where P is the starting number and k is the number of primes to sum.
Output Format
• A single integer representing the sum of the next k primes greater than P.
• If the input is invalid (e.g., not integers or outside the defined range), the program should print "Invalid input"
Constraints
-10 <= k <= 10
Sample Input 1:
10 5
Sample Output 1:
83
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidInput(int P, int k) {
    return k >= 0 && k <= 10;
}

void sieveOfEratosthenes(int limit, vector<bool>& primes) {
    primes.assign(limit + 1, true);
    primes[0] = primes[1] = false;
    
    for (int i = 2; i * i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= limit; j += i) {
                primes[j] = false;
            }
        }
    }
}

int nextKPrimesSum(int P, int k) {
    int limit = 10000;
    vector<bool> primes;
    sieveOfEratosthenes(limit, primes);
    
    int sum = 0, count = 0, num = P + 1;
    
    while (count < k) {
        if (num > limit) {
            return -1;
        }
        
        if (primes[num]) {
            sum += num;
            count++;
        }
        num++;
    }
    
    return sum;
}

int main() {
    int P, k;
    cin >> P >> k;
    
    if (!isValidInput(P, k)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int result = nextKPrimesSum(P, k);
    
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "No valid primes found within the limit" << endl;
    }
    
    return 0;
}