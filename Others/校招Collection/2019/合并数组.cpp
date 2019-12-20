// https://www.nowcoder.com/practice/20c8731629b64109825595c3d349d2fc

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string a, b, temp;

    while (getline(cin, a)) {

        if (!getline(cin, b)) {
            cout << a << endl;
            continue;
        }

        vector<int> A, B;
        istringstream f0(a);
        while (getline(f0, temp, ',')) {
            A.push_back(stoi(temp));
        }
        istringstream f1(b);
        while (getline(f1, temp, ',')) {
            B.push_back(stoi(temp));
        }

        vector<int> C(A.size() + B.size());
        int n1 = static_cast<int>(A.size());
        int n2 = static_cast<int>(B.size());
        int i1 = 0;
        int i2 = 0;
        int j = 0;
        while ((i1 < n1) && (i2 < n2)) {
            if (A[i1] < B[i2]) {
                C[j] = A[i1];
                ++i1;
            } else {
                C[j] = B[i2];
                ++i2;
            }
            ++j;
        }

        while (i1 < n1) {
            C[j] = A[i1];
            ++i1;
            ++j;
        }
        while (i2 < n2) {
            C[j] = B[i2];
            ++i2;
            ++j;
        }

        for (size_t i = 0; i != C.size(); ++i) {
            if (i != 0) {
                cout << ",";
            }
            cout << C[i];
        }
        cout << endl;
    }
    return 0;
}