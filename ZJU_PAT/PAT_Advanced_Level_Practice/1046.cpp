#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    int s = 0;
    for (auto&i : A) {
        cin >> i;
        s += i;
    }
    vector<int> pre(n);
    pre[0] = A[0];
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i-1] + A[i];
    }
    auto getDist = [&](int l, int r) {
        if (l > r) {
            swap(l, r);
        }
        if (l == r) {
            return 0;
        }
        if (l == 1) {
            return min(pre[r-2], s - pre[r-2]);
        }
        int temp = pre[r-2] - pre[l-2];
        return min(temp, s - temp);
    };
    int m, l, r;
    cin >> m;
    while (m--) {
        cin >> l >> r;
        cout << getDist(l, r) << '\n';
    }
    return 0;
}
