// https://open.kattis.com/problems/missingnumber

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    int n;
    string s, curNum;
    cin >> n >> s;
    deque<char> dq(s.begin(), s.end());
    for (int i = 1; i <= n; ++i) {
        curNum = to_string(i);
        if (dq.size() < curNum.size()) {
            cout << i << '\n';
            return 0;
        }
        string str;
        for (size_t j = 0; j != curNum.size(); ++j) {
            str.push_back(dq.front());
            dq.pop_front();
        }
        if (str != curNum) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
