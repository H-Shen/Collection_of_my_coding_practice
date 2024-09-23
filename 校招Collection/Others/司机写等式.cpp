// https://ac.nowcoder.com/acm/problem/14406

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    int n;
    cin >> n;
    ll a, b, c, d;
    while (n--) {
        cin >> a >> b >> c >> d;
        cout << a*b-c*d << endl;
    }

    return 0;
}