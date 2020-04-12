#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    unordered_map<string, string> A;
    string a, b;
    while (n--) {
        cin >> a >> b;
        A[a] = b;
    }
    string s, ans_a, ans_b, ans_c, ans_d;
    while (cin >> s >> ans_a >> ans_b >> ans_c >> ans_d) {
        if (A[s] == ans_a) {
            cout << 'A';
        } else if (A[s] == ans_b) {
            cout << 'B';
        } else if (A[s] == ans_c) {
            cout << 'C';
        } else {
            cout << 'D';
        }
        cout << '\n';
    }

    return 0;
}
