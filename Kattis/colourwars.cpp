// https://open.kattis.com/problems/colourwars

#include <bits/extc++.h>

using namespace std;
using ll = long long;

unordered_map<int,int> unmap;
int n, val;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        ++unmap[val+1];
    }
    int counter = 0;
    for (auto &[i,j] : unmap) {
        if (j <= i) {
            counter += i;
            continue;
        }
        if (j % i == 0) {
            counter += (j / i) * i;
        }
        else {
            counter += (j / i) * i;
            counter += ((j+i) % i) * i;
        }
    }
    cout << counter << '\n';
    return 0;
}
