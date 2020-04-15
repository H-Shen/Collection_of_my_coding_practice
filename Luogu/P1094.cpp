#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int w, n;
    cin >> w >> n;
    deque<int> A(n);
    for (auto &i : A) cin >> i;
    sort(A.begin(), A.end());
    int groups = 0;
    while (!A.empty()) {
        if (A.size() == 1) {
            A.pop_back();
            ++groups;
        }
        else if (A.back() + A.front() <= w) {
            A.pop_back();
            A.pop_front();
            ++groups;
        }
        else {
            A.pop_back();
            ++groups;
        }
    }
    cout << groups << '\n';

    return 0;
}