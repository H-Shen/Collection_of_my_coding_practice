// https://open.kattis.com/problems/krizaljka
#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;

    int i = 0, j = 0;
    int len_a = a.size(), len_b = b.size();
    bool hasAns = false;

    for (i = 0; i < len_a; ++i) {
        for (j = 0; j < len_b; ++j) {
            if (a[i] == b[j]) {
                hasAns = true;
                break;
            }
        }
        if (hasAns) {
            break;
        }
    }

    vector<string> res(len_b);
    for (auto &&k : res) {
        k = string(len_a, '.');
    }
    res[j] = a;
    for (int k = 0; k < len_b; ++k) {
        res[k][i] = b[k];
    }

    for (const auto &k : res) {
        cout << k << endl;
    }

    return 0;
}
