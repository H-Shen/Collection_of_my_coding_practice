// https://open.kattis.com/problems/skocimis

#include<bits/stdc++.h>

using namespace std;

const int maxn = 3;

int main() {
    vector<int> A(maxn);
    for (auto &&i : A) {
        cin >> i;
    }
    int cnt = 0;
    int diff0 = 0;
    int diff1 = 0;
    while (1) {
        diff0 = A[1] - A[0];
        diff1 = A[2] - A[1];
        if (diff1 == 1 && diff0 == 1) {
            break;
        }

        if (diff1 >= diff0) {
            A[0] = A[1] + 1;
            swap(A[0], A[1]);
        } else {
            A[2] = A[1] - 1;
            swap(A[2], A[1]);
        }
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
