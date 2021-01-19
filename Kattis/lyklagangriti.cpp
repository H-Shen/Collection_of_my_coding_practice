// https://open.kattis.com/problems/lyklagangriti

#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    list<char> L;
    auto iter = L.begin();

    for (const char &ch : s) {
        if (ch == 'L') {
            --iter;
        }
        else if (ch == 'R') {
            ++iter;
        }
        else if (ch == 'B') {
            --iter;
            iter = L.erase(iter);
        }
        else {
            iter = L.insert(iter, ch);
            ++iter;
        }
    }
    for (const auto &i : L) {
        cout << i;
    }
    cout << '\n';

    return 0;
}
