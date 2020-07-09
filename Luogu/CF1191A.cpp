#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    unordered_map<int, int> level = {
            {1, 4},
            {3, 3},
            {2, 2},
            {0, 1}
    };
    int hp;
    cin >> hp;
    vector<pair<int, int> > A;
    for (int i = 0; i <= 2; ++i) {
        A.emplace_back(make_pair(i, level[(hp + i) % 4]));
    }
    sort(A.begin(), A.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs){
        if (lhs.second == rhs.second) {
            return lhs.first < rhs.first;
        }
        return lhs.second > rhs.second;
    });
    cout << A.front().first << ' ';
    switch (A.front().second) {
        case 4: cout << 'A'; break;
        case 3: cout << 'B'; break;
        case 2: cout << 'C'; break;
        case 1: cout << 'D'; break;
    }
    cout << '\n';

    return 0;
}
