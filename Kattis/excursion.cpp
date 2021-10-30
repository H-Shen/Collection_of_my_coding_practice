// https://open.kattis.com/problems/excursion

#include <bits/extc++.h>

using ll = long long;
using namespace std;

constexpr int MAXN = 1000005;
int A[MAXN];
int temp[MAXN];
ll counter = 0;
int n;

// sort A[l ... r-1]
void merge(int l, int r) {
    if (l >= r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    merge(l, mid);
    merge(mid, r);
    int p = l;
    int q = mid;
    int s = l;
    while (s < r) {
        if (p >= mid || (q < r && A[p] > A[q]) ) {
            temp[s++] = A[q++];
            counter += static_cast<ll>(mid - p);
        } else {
            temp[s++] = A[p++];
        }
    }
    for (int i = l; i < r; ++i) {
        A[i] = temp[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    n = (int)s.size();
    for (int i = 0; i < n; ++i) A[i] = s[i] - '0';
    merge(0, n);
    cout << counter << '\n';
    return 0;
}
