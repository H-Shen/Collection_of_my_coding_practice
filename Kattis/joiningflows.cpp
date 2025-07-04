#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<ll> t(k), a(k), b(k), d(k);
    ll A = 0, C = 0, E0 = 0;
    for (int i = 0; i < k; i++) {
        cin >> t[i] >> a[i] >> b[i];
        A += a[i];
        E0 += a[i] * t[i];
        d[i] = b[i] - a[i];
        C += d[i];
    }

    // Prepare for greedy min and max energy computations
    // taps_min: sorted by temperature ascending
    // taps_max: sorted by temperature descending
    vector<pair<ll,ll>> taps_min, taps_max;
    taps_min.reserve(k);
    taps_max.reserve(k);
    for (int i = 0; i < k; i++) {
        taps_min.emplace_back(t[i], d[i]);
        taps_max.emplace_back(t[i], d[i]);
    }
    sort(taps_min.begin(), taps_min.end());
    sort(taps_max.begin(), taps_max.end(), greater<>());

    int r;
    cin >> r;
    while (r--) {
        ll tau, phi;
        cin >> tau >> phi;

        // Check total flow feasibility
        if (phi < A || phi > A + C) {
            cout << "no\n";
            continue;
        }

        ll Y = phi - A;           // extra flow above the minimums
        ll Emin = E0, Emax = E0;

        // Compute minimum possible energy by using the coldest taps first
        ll rem = Y;
        for (auto &p : taps_min) {
            if (rem == 0) break;
            ll ti = p.first;
            ll di = p.second;
            ll use = min(di, rem);
            Emin += use * ti;
            rem -= use;
        }

        // Compute maximum possible energy by using the hottest taps first
        rem = Y;
        for (auto &p : taps_max) {
            if (rem == 0) break;
            ll ti = p.first;
            ll di = p.second;
            ll use = min(di, rem);
            Emax += use * ti;
            rem -= use;
        }

        // Desired total energy for temperature tau and flow phi
        ll targetEnergy = tau * phi;

        // Check if targetEnergy lies within [Emin, Emax]
        if (Emin <= targetEnergy && targetEnergy <= Emax)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
