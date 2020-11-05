// https://open.kattis.com/problems/nop
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {

    string s;
    cin >> s;
    deque<char> dq1(s.begin(), s.end());
    vector<char> dq2;
    while (!dq1.empty()) {
        if (isupper(dq1.front())) {
            if (dq2.size() % 4 == 0) {
                dq2.emplace_back(dq1.front());
                dq1.pop_front();
            } else {
                dq2.emplace_back(0);
            }
        } else {
            dq2.emplace_back(dq1.front());
            dq1.pop_front();
        }
    }
    cout << count(dq2.begin(), dq2.end(), 0) << '\n';

    return 0;
}
