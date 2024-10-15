/*
Given two integers P and S, find the smallest set of prime numbers greater than P such that their sum is greater than or equal to S.
Input Format
• Two integers P and S, where P is the starting number and S is the target sum for the primes.
Output Format
• A single integer representing the number of primes needed to reach a sum greater than or equal to S.
• If the input is invalid (e.g., not integers or outside the defined range), the program should print "Invalid input"
Constraints
• -10 <= P,S <= 1000
Sample Input 1:
10 5
Sample Output 1:
1
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidInput(int P, int S) {
    return P >= 1 && P <= 1000 && S >= 1 && S <= 1000;
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

int findSmallestPrimeSet(int P, int S) {
    int limit = 1000;
    vector<bool> primes;
    sieveOfEratosthenes(limit, primes);
    
    int sum = 0, count = 0, num = P + 1;
    
    while (num <= limit && sum < S) {
        if (primes[num]) {
            sum += num;
            count++;
        }
        num++;
    }
    
    return (sum >= S) ? count : -1;
}

int main() {
    int P, S;
    cin >> P >> S;
    
    if (!isValidInput(P, S)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    if (S <= 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int result = findSmallestPrimeSet(P, S);
    
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "No valid set of primes found within the limit" << endl;
    }
    
    return 0;
}