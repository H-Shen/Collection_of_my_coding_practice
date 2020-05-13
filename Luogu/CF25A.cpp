#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    vector<int> even;
    vector<int> odd;
    for (auto &i : A) {
        scanf("%d", &i);
        if (i & 1) {
            odd.emplace_back(i);
        } else {
            even.emplace_back(i);
        }
    }
    int temp;
    if (even.size() == 1) {
        temp = *even.cbegin();
        for (int i = 0; i < n; ++i) {
            if (A.at(i) == temp) {
                cout << i + 1 << '\n';
                return 0;
            }
        }
    } else {
        temp = *odd.cbegin();
        for (int i = 0; i < n; ++i) {
            if (A.at(i) == temp) {
                cout << i + 1 << '\n';
                return 0;
            }
        }
    }

    return 0;
}