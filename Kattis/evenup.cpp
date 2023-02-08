// https://open.kattis.com/problems/evenup

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i];
    reverse(vec.begin(), vec.end());
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        s.push(vec[i]);
    }
    stack<int> s2;
    while (true) {
        if (s.empty()) {
            if (s2.size() <= 1) {
                break;
            }
            else {
                int a = s2.top();
                s2.pop();
                int b = s2.top();
                s2.pop();
                if ((a + b) % 2 == 0) {
                    continue;
                }
                else {
                    s2.push(a);
                    s2.push(b);
                    break;
                }
            }
        }
        else {
            if (s2.empty()) {
                s2.push(s.top());
                s.pop();
            }
            else {
                if ((s.top() + s2.top()) % 2 == 0) {
                    s2.pop();
                    s.pop();
                }
                else {
                    s2.push(s.top());
                    s.pop();
                }
            }
        }
    }
    cout << s2.size() << '\n';
    return 0;
}