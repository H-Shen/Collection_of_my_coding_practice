// https://open.kattis.com/problems/encodedmessage
#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

inline
int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, length;
    string s;
    vector<vector<char> > A;
    cin >> n;
    while (n--) {
        cin >> s;
        length = sqrt((double) (s.size()));
        vector<vector<char> >().swap(A);
        A.resize(length);
        for (auto &&i : A) {
            i.resize(length);
        }
        int pos = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = length - 1; j >= 0; --j) {
                A[j][i] = s[pos++];
            }
        }
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                cout << A[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
