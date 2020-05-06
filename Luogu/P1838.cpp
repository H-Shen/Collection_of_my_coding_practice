#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 5;
constexpr int MAX_STR_LENGTH = 15;
vector<vector<int> > A(MAXN, vector<int>(MAXN));
char s[MAX_STR_LENGTH];

inline static
int check(const int &a, const int &b, const int &c) {
    if (a == b && b == c) {
        return a;
    }
    return 0;
}

int main() {

    scanf("%s", s);
    int temp;
    bool flag = true;
    for (int i = 0; s[i] != 0; ++i) {
        temp = s[i] - '0' - 1;
        if (flag) {
            A.at(temp / 3).at(temp % 3) = 1;
            flag = false;
        } else {
            A.at(temp / 3).at(temp % 3) = 2;
            flag = true;
        }
    }
    // check rows
    for (int i = 0; i < 3; ++i) {
        if (check(A[i][0], A[i][1], A[i][2]) == 1) {
            cout << "xiaoa wins." << endl;
            return 0;
        }
        if (check(A[i][0], A[i][1], A[i][2]) == 2) {
            cout << "uim wins." << endl;
            return 0;
        }
    }
    // check cols
    for (int i = 0; i < 3; ++i) {
        if (check(A[0][i], A[1][i], A[2][i]) == 1) {
            cout << "xiaoa wins." << endl;
            return 0;
        }
        if (check(A[0][i], A[1][i], A[2][i]) == 2) {
            cout << "uim wins." << endl;
            return 0;
        }
    }
    // check diagonal lines
    if (check(A[0][0], A[1][1], A[2][2]) == 1) {
        cout << "xiaoa wins." << endl;
        return 0;
    }
    if (check(A[0][0], A[1][1], A[2][2]) == 2) {
        cout << "uim wins." << endl;
        return 0;
    }
    if (check(A[2][0], A[1][1], A[0][2]) == 1) {
        cout << "xiaoa wins." << endl;
        return 0;
    }
    if (check(A[2][0], A[1][1], A[0][2]) == 2) {
        cout << "uim wins." << endl;
        return 0;
    }
    cout << "drew." << endl;
    return 0;
}
