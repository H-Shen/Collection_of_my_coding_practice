// https://www.nowcoder.com/practice/b69c933c28164cbd8852820c16556a84

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 20;
char str[MAXN];

bool isDigit(const string &s) {
    for (const char &i : s) {
        if (!isdigit(i)) {
            return false;
        }
    }
    return true;
}

int main() {

    string s;
    vector<ll> A;
    ll a, b, N;
    while (~scanf("%s", str)) {
        s = str;
        if (isDigit(s)) {
            A.emplace_back(stoll(s));
        } else {
            sscanf(str, "%lld,%lld", &a, &b);
            A.emplace_back(a);
            N = b;
        }
    }
    sort(A.begin(), A.end());
    int length = static_cast<int>(A.size());
    if (length <= 2) {
        printf("False\n");
        return 0;
    } else {
        for (int i = 0; i < length - 2; ++i) {
            ll s_i = A.at(i);
            int start = i + 1;
            int end = length - 1;
            while (start < end) {
                ll s_j = A.at(start);
                ll s_k = A.at(end);
                ll temp = s_i + s_j + s_k;
                if (temp == N) {
                    printf("True\n");
                    return 0;
                } else if (temp > N) {
                    --end;
                } else {
                    ++start;
                }
            }
        }
    }
    printf("False\n");
    return 0;
}