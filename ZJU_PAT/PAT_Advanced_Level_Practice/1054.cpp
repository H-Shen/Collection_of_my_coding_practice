#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    n = n * m;
    
    ll val = -1, cnt = 0, a;
    while (n--) {
      cin >> a;
      if (a != val) {
        if (--cnt <= 0) val = a, cnt = 1;
      } else ++cnt;
    }
    cout << val << '\n';
    
    return 0;
}
