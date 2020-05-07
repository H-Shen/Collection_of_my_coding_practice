#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MAXN = 1000000000;
constexpr ll MINN = 1;

int main() {

    ll low = MINN;
    ll high = MAXN;
    ll mid;
    int response;

    while (true) {
        mid = low + ((high - low) >> 1);
        cout << mid << endl;
        cin >> response;
        if (response == 1) {
            high = mid - 1;
        } else if (response == -1) {
            low = mid + 1;
        } else if (response == 0) {
            break;
        }
    }
    return 0;
}
