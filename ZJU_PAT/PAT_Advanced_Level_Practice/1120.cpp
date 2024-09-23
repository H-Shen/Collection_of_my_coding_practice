#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(static_cast<unsigned long>(n));
    set<int> B;
    string str;
    for (auto &p : A) {
        cin >> p;
        str = to_string(p);
        vector<int> temp(str.begin(), str.end());
        for_each(temp.begin(), temp.end(), [](int &a) { a -= static_cast<int>('0'); });
        B.insert(accumulate(temp.begin(), temp.end(), static_cast<int>(0)));
    }
    cout << B.size() << endl;
    if (!B.empty()) {
        for (auto it = B.cbegin(); it != B.cend(); ++it) {
            cout << *it;
            if (it == prev(B.cend())) {
                break;
            } else {
                cout << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}