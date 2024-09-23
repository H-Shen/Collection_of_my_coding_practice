#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    unordered_set<char> A;
    unordered_set<char> B;

    int lena = a.size();
    int lenb = b.size();
    string res;
    int i;
    char ch;

    for (i = 0; i < lenb; ++i) {
        ch = static_cast<char>(toupper(b[i]));
        B.insert(ch);
    }

    for (i = 0; i < lena; ++i) {
        ch = static_cast<char>(toupper(a[i]));
        if (B.find(ch) != B.end()) {
            continue;
        }
        if (A.find(ch) == A.end()) {
            res += static_cast<char>(toupper(a[i]));
            A.insert(ch);
        }
    }

    cout << res << endl;
    return 0;
}