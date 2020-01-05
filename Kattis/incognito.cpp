// https://open.kattis.com/problems/incognito
//
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    int t;
    int n;
    string name, type;
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<string, ll> A;
        while (n--) {
            cin >> name >> type;
            ++A[type];
        }
        ll sum = 1;
        if (A.size() == 1) {
            sum = static_cast<ll>(A.cbegin()->second);
        } else {
            for (const auto &i : A) {
                sum *= (i.second + 1);
            }
            --sum;
        }
        cout << sum << endl;
    }

    return 0;
}
