#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    if (N < 0) {
        cout << "Invalid input";
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
        int min_value = *min_element(arr.begin() + L, arr.begin() + R + 1);
        int cnt = 0;
        for_each(arr.begin() + L, arr.begin() + R + 1,[&cnt,&min_value](int & a){cnt += (a==min_value ? 1 : 0);});
        cout<<min_value << "\n" << cnt << endl;
    }
}