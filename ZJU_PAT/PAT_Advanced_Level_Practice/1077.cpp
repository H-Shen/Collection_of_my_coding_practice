#include <bits/stdc++.h>

using namespace std;
const int MAXN = 300;
char s[MAXN];

string common(string &a, string &b) {
    string res;
    auto it_a = a.crbegin(), it_b = b.crbegin();
    while (true) {
        if (it_a == a.crend() || it_b == b.crend()) {
            break;
        }
        if (*it_a == *it_b) {
            res += *it_a;
            ++it_a;
            ++it_b;
        } else {
            break;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    vector<string> A(n);
    string str;
    int i;

    for (i = 0; i < n; ++i) {
        scanf("%[^\n]", s);
        getchar();
        str = s;
        A[i] = str;
    }

    string res = A[0];
    for (i = 1; i < n; ++i) {
        res = common(res, A[i]);
        if (res.empty()) break;
    }

    if (res.empty()) {
        printf("nai\n");
    } else {
        printf("%s\n", res.c_str());
    }
    return 0;
}