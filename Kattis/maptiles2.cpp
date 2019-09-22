// https://open.kattis.com/problems/maptiles2
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> powerOfTwo = {1};


int main() {

    // pre
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 35; ++i) {
        powerOfTwo.emplace_back(powerOfTwo.back() * 2L);
    }

    // input
    string s;
    ll x = 0;
    ll y = 0;

    cin >> s;
    int length = static_cast<int>(s.size());
    int currentLength = length;

    for (const char &ch : s) {
        if (ch == '1') {
            x += powerOfTwo[currentLength] / 2;
        } else if (ch == '2') {
            y += powerOfTwo[currentLength] / 2;
        } else if (ch == '3') {
            x += powerOfTwo[currentLength] / 2;
            y += powerOfTwo[currentLength] / 2;
        }
        --currentLength;
    }
    cout << length << ' ' << x << ' ' << y << endl;

    return 0;
}
