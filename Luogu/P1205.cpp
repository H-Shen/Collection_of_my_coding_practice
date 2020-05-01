#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
inline static
vector<vector<T> > matrixRotation(const vector<vector<T> > &A, int n) {
    vector<vector<T> > result(n, vector<T>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.at(i).at(n - 1 - j) = A.at(j).at(i);
        }
    }
    return result;
}

template<typename T>
inline static
vector<vector<T> > mirror(const vector<vector<T> > &A, int n) {
    vector<vector<T> > result(A);
    for (auto &i : result) {
        reverse(i.begin(), i.end());
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    string s;
    cin >> n;
    vector<vector<char> > A;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        A.emplace_back(s.begin(), s.end());
    }
    vector<vector<char> > B;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        B.emplace_back(s.begin(), s.end());
    }
    auto A_copy(A);
    A_copy = matrixRotation(A_copy, n);
    if (A_copy == B) {
        cout << 1 << '\n';
        return 0;
    }
    A_copy = matrixRotation(A_copy, n);
    if (A_copy == B) {
        cout << 2 << '\n';
        return 0;
    }
    A_copy = matrixRotation(A_copy, n);
    if (A_copy == B) {
        cout << 3 << '\n';
        return 0;
    }
    A_copy = mirror(A, n);
    if (A_copy == B) {
        cout << 4 << '\n';
        return 0;
    }
    A_copy = matrixRotation(mirror(A, n), n);
    if (A_copy == B) {
        cout << 5 << '\n';
        return 0;
    }
    A_copy = matrixRotation(A_copy, n);
    if (A_copy == B) {
        cout << 5 << '\n';
        return 0;
    }
    A_copy = matrixRotation(A_copy, n);
    if (A_copy == B) {
        cout << 5 << '\n';
        return 0;
    }
    if (B == A) {
        cout << 6 << '\n';
        return 0;
    }
    cout << 7 << '\n';

    return 0;
}