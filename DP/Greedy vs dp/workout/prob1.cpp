/*

You are given n plates, and your task is to solve the classic Tower of Hanoi problem. The goal is to move all the plates from the source rod (s) to the destination rod (D) using an auxiliary rod (A), following these rules:
• Only one plate can be moved at a time.
• A plate can only be moved if it is the top plate on a rod.
• No plate may be placed on top of a smaller plate.
Your task is to print each move in the format: Move X Plates From Y to Z.
Input Format
• A single line containing an integer n, representing the number of plates.
Output Format
• If n > 0, print each move in the format Move X Plates From Y to Z.
• If n <= 0, print -1.
• If the input is non-numeric, print Invalid input.
Constraints
• The input can be any printable ASCII characters.
• 1 <= n <= 10 (to avoid excessive recursion depth).

*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move 1 Plates From " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move " << n << " Plates From " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
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
    
    if (n > 10) {
        cout << "-1" << endl;
        return 0;
    }
    
    towerOfHanoi(n, 'S', 'D', 'A');
    
    return 0;
}
