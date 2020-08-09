#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 300;
array<int, MAXN> stats;

int main() {

    string s;
    cin >> s;
    for (const char &ch : s) {
        ++stats[ch];
    }
    int counter = 0;
    while (stats['B'] >= 1 && stats['u'] >= 2 && stats['b'] >= 1 && stats['l'] >= 1 && stats['a'] >= 2 && stats['s'] >= 1 && stats['r'] >= 1) {
        stats['B'] -= 1;
        stats['u'] -= 2;
        stats['b'] -= 1;
        stats['l'] -= 1;
        stats['a'] -= 2;
        stats['s'] -= 1;
        stats['r'] -= 1;
        ++counter;
    }
    cout << counter << '\n';

    return 0;
}