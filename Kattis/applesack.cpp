// https://open.kattis.com/problems/applesack

#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr ll INF = 0x3f3f3f3f;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int counter = 1;
    while (n > k) {
        ++counter;
        n = n - ceil(n * 1.0 / k);
    }
    counter += n;
    cout << counter << '\n';

    return 0;
}
