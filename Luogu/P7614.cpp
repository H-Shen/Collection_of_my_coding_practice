#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 8;
array<pair<int,int>, MAXN> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < MAXN; ++i) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    sort(A.begin(),  A.end(), [](const auto &l, const auto &r){
        return l.first > r.first;
    });
    int sum = 0;
    constexpr int N = 5;
    for (int i = 0; i < N; ++i) {
        sum += A[i].first;
    }
    cout << sum << '\n';
    sort(A.begin(),  A.begin() + N, [](const auto &l, const auto &r){
        return l.second < r.second;
    });
    for (int i = 0; i < N; ++i) {
        cout << A[i].second << ' ';
    }
    cout << '\n';
    return 0;
}