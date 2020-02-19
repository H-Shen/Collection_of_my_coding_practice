#include <bits/extc++.h>

using namespace std;
using ll = long long;
constexpr ll DUMMY_DATA = 0;

bool cmp(const pair<ll, ll> &lhs, const pair<ll, ll> &rhs) {
    if (lhs.first == rhs.first) {
        return lhs.second > rhs.second;
    }
    return (lhs.first < rhs.first);
}

vector<pair<ll, ll> > A;

int main() {

    int n, m;
    ll val;
    scanf("%d %d", &n, &m);
    A.resize(n);
    for (auto &i : A) {
        scanf("%lld %lld", &i.first, &i.second);
    }
    sort(A.begin(), A.end(), cmp);
    ll max_salary = -1;
    for (auto &i : A) {
        max_salary = max(max_salary, i.second);
        i.second = max_salary;
    }

    while (m--) {
        scanf("%lld", &val);
        if (val < A.front().first) {
            printf("0\n");
        } else {
            auto iter = upper_bound(A.begin(), A.end(), make_pair(val, DUMMY_DATA), cmp);
            printf("%lld\n", (--iter)->second);
        }
    }

    return 0;
}
