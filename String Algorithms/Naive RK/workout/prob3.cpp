#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int d = 256;
const int q = 101;

bool isValidInput(const string& input) {
    for (char c : input) {
        if (!isalnum(c)) {
            return false;
        }
    }
    return true;
}

void rabinKarp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    bool found = false , isOdd = false;
    
    for (i = 0; i < m - 1; i++)
    h = (h * d) % q;
    
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                break;
            }
            
            if (j == m) {
                if(i % 2 == 0){
                cout << i << endl;
                found = true;
                } else {
                    isOdd = true;
                }
            }
        }
        
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
            t = (t + q);
        }
    }
    
    if (!found) {
        if(isOdd){
            cout << "Pattern not found" << endl;
        } else {
            cout << "-1";
        }
    }
}

int main() {
    string str, pattern;
    getline(cin, str);
    getline(cin, pattern);
    
    if (!isValidInput(str) || !isValidInput(pattern)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    rabinKarp(str, pattern);
    return 0;
}