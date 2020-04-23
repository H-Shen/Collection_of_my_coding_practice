#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> L = {1, 0, 0};
    string s;
    cin >> s;

    for (const auto &i : s) {
        switch (i) {
            case 'A':
                swap(L[0], L[1]);
                break;
            case 'B':
                swap(L[1], L[2]);
                break;
            case 'C':
                swap(L[0], L[2]);
                break;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (L[i] == 1) {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}