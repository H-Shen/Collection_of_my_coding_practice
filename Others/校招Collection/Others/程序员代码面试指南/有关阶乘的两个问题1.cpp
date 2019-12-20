// https://www.nowcoder.com/practice/a54d454f00f84dc3a6eeaec7a7233d51

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline static
ll zeroCount(ll n){
    ll num = 0;
    while(n > 0){
        num += n / 5;
        n /= 5;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    cout << zeroCount(n) << endl;
    return 0;
}