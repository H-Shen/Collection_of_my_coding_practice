// https://open.kattis.com/problems/npuzzle
#include <bits/extc++.h>

using namespace std;

const int maxn = 4;

struct Pos {
    int i;
    int j;
};

inline
int distance(const Pos &a, const Pos &b) {
    return abs(a.i - b.i) + abs(a.j - b.j);
}

int main() {
    vector<string> A{"ABCD", "EFGH", "IJKL", "MNO."};
    unordered_map<char, Pos> save;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            if (A[i][j] == '.') {
                continue;
            }
            save[A[i][j]].i = i;
            save[A[i][j]].j = j;
        }
    }

    vector<string> B(maxn);
    for (auto &&i : B) {
        cin >> i;
    }

    int cnt = 0;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            if (B[i][j] == '.') {
                continue;
            }
            Pos tmp;
            tmp.i = i;
            tmp.j = j;
            cnt += distance(tmp, save[B[i][j]]);
        }
    }
    cout << cnt << endl;
    return 0;
}
