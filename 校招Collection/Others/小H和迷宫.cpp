// https://ac.nowcoder.com/acm/problem/15156

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ll N, a, b, c, N_copy;
    cin >> N >> a >> b >> c;
    N_copy = N;
    vector <ll> A{ a, b, c };
    sort(A.begin(), A.end());
    while ( !(N <= 0 || A.empty()) )
    {
        N = static_cast<ll>(N * (100 - A.back()) / 100.0);
        A.pop_back();
    }
    cout << (N_copy - N) << endl;

    return 0;
}