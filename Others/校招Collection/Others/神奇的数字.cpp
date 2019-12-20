// https://ac.nowcoder.com/acm/problem/14342

#include <bits/stdc++.h>

using namespace std;
constexpr int MIN = 1000;
constexpr int MAX = 9999;

int main()
{
    vector <int> A;
    string tmp, res;
    for (int i = MIN; i <= MAX; ++i) {
        tmp = to_string(i);
        res = tmp;
        reverse(tmp.begin(), tmp.end());
        res = res + tmp;
        A.emplace_back(stoi(res));
    }
    sort(A.begin(), A.end());
    for (const auto &p : A) {
        printf("%d\n", p);
    }
    return 0;
}