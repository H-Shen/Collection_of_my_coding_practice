#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 1005;
int A[MAXN][MAXN];
int res[MAXN][MAXN];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, m;
    string op;
    cin >> t;
    bool firstCase = true;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> A[i][j];
            }
        }
        cin >> op;
        vector<int> a = {0, 1, 2, 3};
        vector<int> aVal(4, 0);
        for (const char &ch : op) {
            switch (ch) {
                case 'C':
                    swap(a.at(1), a.at(3));
                    break;
                case 'I':
                    swap(a.at(2), a.at(3));
                    break;
                case 'U':
                    --aVal.at(a.at(1));
                    break;
                case 'D':
                    ++aVal.at(a.at(1));
                    break;
                case 'L':
                    --aVal.at(a.at(2));
                    break;
                case 'R':
                    ++aVal.at(a.at(2));
                    break;
                default:
                    break;
            }
        }
        vector<int> result(4, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    switch (a.at(k)) {
                        case 1:
                            result.at(k) = i + aVal.at(1);
                            break;
                        case 2:
                            result.at(k) = j + aVal.at(2);
                            break;
                        case 3:
                            result.at(k) = A[i][j] + aVal.at(3);
                            break;
                    }
                    result.at(k) = (result.at(k) % n + n) % n;
                    if (result.at(k) == 0) {
                        result.at(k) = n;
                    }
                }
                res[result.at(1)][result.at(2)] = result.at(3);
            }
        }
        if (firstCase) {
            firstCase = false;
        } else {
            cout << '\n';
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1) {
                    cout << ' ';
                }
                cout << res[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}