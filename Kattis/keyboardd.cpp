// https://open.kattis.com/problems/keyboardd

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    string a, b;
    getline(cin, a);
    getline(cin, b);
    unordered_map<char,int> unmap_a, unmap_b;
    for (const auto &i : a) ++unmap_a[i];
    for (const auto &j : b) ++unmap_b[j];
    string result;
    for (const auto &[k,v] : unmap_a) {
        if (unmap_b.find(k) == unmap_b.end() || v < unmap_b[k]) {
            result.push_back(k);
        }
    }
    cout << result << '\n';

    return 0;
}
