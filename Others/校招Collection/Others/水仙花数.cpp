// https://ac.nowcoder.com/acm/problem/14386

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline static
ll myPow(ll a, ll n) {
    if (n <= 0) {
        return 1;
    }
    ll ret = 1;
    while (n--) {
        ret *= a;
    }
    return ret;
}

int main() {

    int n;
    ll A,  A_copy, sum, temp;
    cin >> n;
    while (n--) {
        cin >> A;
        temp = to_string(A).size();
        A_copy = A;
        sum = 0;
        while (A_copy > 0) {
            sum += myPow(A_copy % 10, temp);
            A_copy /= 10;
        }
        if (sum == A) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << endl;
    }

    return 0;
}