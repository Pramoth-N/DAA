#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    
    if (N <=0) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        
        int min_value = *min_element(arr.begin() + L, arr.begin() + R +1) ;
        int sum_value = accumulate(arr.begin() + L, arr.begin() + R + 1, 0);
        cout << min_value << "\n" << sum_value << endl;
    }
}