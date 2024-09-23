#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPalindrome(const vector<string> &A, vector<string> &A_mirr) {
    reverse(A_mirr.begin(), A_mirr.end());
    return (A_mirr == A);
}

void conv(ll n, ll radix, vector<string> &save) {

    string tmp;
    if (n == 0) {
        save.emplace_back("0");
        return;
    }
    while (n > 0) {
        tmp = to_string(n % radix);
        save.push_back(tmp);
        n /= radix;
    }
}

int main() {
    ll a, radix;
    int i;
    scanf("%lld %lld", &a, &radix);
    vector<string> save;
    conv(a, radix, save);

    vector<string> saveMirr = save;
    bool k = isPalindrome(save, saveMirr);

    if (k) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    for (i = 0; i < static_cast<int>(saveMirr.size()) - 1; ++i) {
        printf("%s ", saveMirr[i].c_str());
    }
    printf("%s\n", saveMirr[static_cast<int>(saveMirr.size()) - 1].c_str());
    return 0;
}
