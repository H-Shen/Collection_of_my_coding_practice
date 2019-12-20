// https://www.nowcoder.com/practice/662ed635c2d445729a1227ee879a3610

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    size_t len;
    vector<int> A, B, C, D;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vector<int>().swap(A);
        vector<int>().swap(B);
        vector<int>().swap(C);
        vector<int>().swap(D);
        len = static_cast<size_t>(n) * 2;
        A.resize(len);
        B.resize(len);
        C.resize(len);
        for (size_t i = 0; i < len; ++i) {
            cin >> A[i];
        }
        B[0] = A[0];

        for (size_t i = 1; i < len; ++i) {
            B[i] = B[i - 1] + A[i];
        }
        C[len - 1] = A[len - 1];
        for (int i = static_cast<int>(len - 2); i >= 0; --i) {
            C[i] = C[i + 1] + A[i];
        }

        reverse(C.begin(), C.end());
        set_intersection(B.begin(), B.end(), C.begin(), C.end(), back_inserter(D));
        cout << D.size() << endl;
    }
    return 0;
}