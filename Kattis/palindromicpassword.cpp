// https://open.kattis.com/problems/palindromicpassword
//
#include <bits/stdc++.h>

using namespace std;

constexpr int MIN{100};
constexpr int MAX{999};
vector<int> A;

int main() {

    string s, s_rev;
    for (int i = 100; i <= 999; ++i) {
        s = to_string(i);
        s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        s += s_rev;
        A.emplace_back(stoi(s));
    }
    sort(A.begin(), A.end());

    int n, val;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        if (binary_search(A.begin(), A.end(), val)) {
            printf("%d\n", val);
        } else if (val < A.front()) {
            printf("%d\n", A.front());
        } else {
            int val1 = A.at(upper_bound(A.begin(), A.end(), val) - A.begin());
            int val2 = A.at(lower_bound(A.begin(), A.end(), val) - A.begin() - 1);
            int diff1 = abs(val1 - val);
            int diff2 = abs(val2 - val);
            if (diff1 > diff2) {
                printf("%d\n", val2);
            } else if (diff1 < diff2) {
                printf("%d\n", val1);
            } else {
                printf("%d\n", min(val1, val2));
            }
        }
    }

    return 0;
}
