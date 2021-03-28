// https://open.kattis.com/problems/speeding

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    int maxSpeed = 0;
    int last_t;
    int last_d;
    int cur_t, cur_d;
    cin >> n;
    cin >> last_t >> last_d;
    for (int i = 1; i < n; ++i) {
        cin >> cur_t >> cur_d;
        maxSpeed = max(maxSpeed, (cur_d - last_d) / (cur_t - last_t));
        last_t = cur_t;
        last_d = cur_d;
    }
    cout << maxSpeed << '\n';

    return 0;
}
