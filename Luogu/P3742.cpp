#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string x, y;
    cin >> x >> y;
    if (x.size() == y.size()) {
        // construct z such that f(x,z)=y <=> y[i] = min(x[i], z[i])
        string z = string(x.size(), 'a');
        for (size_t i = 0; i != z.size(); ++i) {
            while (y.at(i) != min(x.at(i), z.at(i))) {
                ++z.at(i);
                if (!islower(z.at(i))) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
        cout << z << '\n';
    } else {
        cout << -1 << '\n';
    }


    return 0;
}
