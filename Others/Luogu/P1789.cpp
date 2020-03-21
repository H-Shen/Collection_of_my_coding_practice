#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n, m, k, i, j;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<bool> > A(n, vector<bool>(n, false));
    for (int i_ = 0; i_ < m; ++i_) {
        scanf("%d %d", &i, &j);
        --i;
        --j;
        A.at(i).at(j) = true;
        try { A.at(i).at(j - 1) = true; } catch (...) {}
        try { A.at(i).at(j - 2) = true; } catch (...) {}
        try { A.at(i).at(j + 1) = true; } catch (...) {}
        try { A.at(i).at(j + 2) = true; } catch (...) {}
        try { A.at(i - 1).at(j) = true; } catch (...) {}
        try { A.at(i - 2).at(j) = true; } catch (...) {}
        try { A.at(i + 1).at(j) = true; } catch (...) {}
        try { A.at(i + 2).at(j) = true; } catch (...) {}
        try { A.at(i - 1).at(j - 1) = true; } catch (...) {}
        try { A.at(i - 1).at(j + 1) = true; } catch (...) {}
        try { A.at(i + 1).at(j + 1) = true; } catch (...) {}
        try { A.at(i + 1).at(j - 1) = true; } catch (...) {}
    }
    for (int i_ = 0; i_ < k; ++i_) {
        scanf("%d %d", &i, &j);
        --i;
        --j;
        i -= 2;
        j -= 2;
        for (int row = i; row < i + 5; ++row) {
            for (int col = j; col < j + 5; ++col) {
                try {
                    A.at(row).at(col) = true;
                } catch (...) {}
            }
        }
    }
    int counter = 0;
    for (int i_ = 0; i_ < n; ++i_) {
        for (int j_ = 0; j_ < n; ++j_) {
            if (!A.at(i_).at(j_)) {
                ++counter;
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}
