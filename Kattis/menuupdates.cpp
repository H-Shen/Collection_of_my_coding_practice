// https://open.kattis.com/problems/menuupdates

#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 4*1e5+5;

int d, u, num;
set<int> avail;
unordered_map<int, vector<int>> unmap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> d >> u;
    for (int i = 1; i <= MAXN; ++i) {
        avail.insert(i);
    }
    string op;
    for (int i = 1; i <= u; ++i) {
        // release
        if (unmap.find(i) != unmap.end()) {
            for (auto &j : unmap[i]) {
                avail.insert(j);
            }
            unmap.erase(i);
        }
        cin >> op;
        if (op == "a") {
            int temp = *avail.begin();
            avail.erase(avail.begin());
            cout << temp << '\n';
        }
        else {
            cin >> num;
            unmap[i+d].emplace_back(num);
        }
    }

    return 0;
}
