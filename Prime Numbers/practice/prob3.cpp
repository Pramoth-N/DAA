/*
You are given a positive integer P. Your task is to find the sum of all prime numbers that are greater than P and less than or equal to N, where N is also provided as input. If there are no prime numbers in this range, return 0.
Input Format
• The first line contains a single integer P
• The second line contains a single integer N
Output Format
• Output a single integer representing the sum of all prime numbers greater than P and less than or equal to N.
• If there are no such prime numbers, output 0.
Constraints
•P<N
Sample Input 1:
10 30
Sample Output 1:
112
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidInput(int P, int N) {
    return P >= 0 && N > P;
}

void sieveOfEratosthenes(int N, vector<bool>& primes) {
    primes.assign(N + 1, true);
    primes[0] = primes[1] = false;
    
    for (int i = 2; i * i <= N; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= N; j += i) {
                primes[j] = false;
            }
        }
    }
}

int sumPrimesInRange(int P, int N) {
    vector<bool> primes;
    sieveOfEratosthenes(N, primes);
    
    int sum = 0;
    for (int i = P + 1; i <= N; i++) {
        if (primes[i]) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int P, N;
    cin >> P >> N;
    
    if (!isValidInput(P, N)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    int result = sumPrimesInRange(P, N);
    
    cout << result << endl;
    
    return 0;
}