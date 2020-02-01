// https://open.kattis.com/problems/base2palindrome
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr size_t MAXN = 60000;

unordered_set<ll> A;

inline static
ll power_of_two(const ll &n) {
    if (n == 0) {
        return 1;
    }
    ll sum = 1;
    for (ll i = 0; i < n; ++i) {
        sum *= 2;
    }
    return sum;
}

inline static
string convert_to_bin(ll n, size_t length) {
    string s;
    while (n > 0) {
        if (n % 2 == 0) {
            s += "0";
        } else {
            s += "1";
        }
        n /= 2;
    }
    while (s.size() < length) {
        s += "0";
    }
    reverse(s.begin(), s.end());
    return s;
}

inline static
string get_mirror(const string &s) {
    string p;
    reverse_copy(s.begin(), s.end(), back_inserter(p));
    return p;
}

inline static
void pre() {

    A.insert(1);
    A.insert(3);
    A.insert(stoi("101", nullptr, 2));
    A.insert(stoi("111", nullptr, 2));

    ll n = 1;
    while (true) {

        ll upperbound = power_of_two(n);
        string s;
        string temp;

        for (ll i = 0; i < upperbound; ++i) {
            temp = convert_to_bin(i, n);
            s = "1" + temp + get_mirror(temp) + "1";
            A.insert(stoi(s, nullptr, 2));
        }

        if (A.size() > MAXN) {
            break;
        }

        for (ll i = 0; i < upperbound; ++i) {
            temp = convert_to_bin(i, n);
            s = "1" + temp + "0" + get_mirror(temp) + "1";
            A.insert(stoi(s, nullptr, 2));
        }
        for (ll i = 0; i < upperbound; ++i) {
            temp = convert_to_bin(i, n);
            s = "1" + temp + "1" + get_mirror(temp) + "1";
            A.insert(stoi(s, nullptr, 2));
        }

        if (A.size() > MAXN) {
            break;
        }

        ++n;
    }
}

int main() {

    // pre
    pre();
    vector<ll> L(A.begin(), A.end());
    sort(L.begin(), L.end());

    // input
    int m;
    scanf("%d", &m);

    // output
    printf("%lld\n", L.at(m - 1));

    return 0;
}
