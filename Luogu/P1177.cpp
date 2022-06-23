#include <bits/extc++.h>
#include <execution>

using namespace std;

constexpr int MAXN = 1e5+5;
array<int, MAXN> arr;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(execution::par, arr.begin(), arr.begin() + n);
    cout << arr[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << arr[i];
    }
    cout << '\n';
    return 0;
}