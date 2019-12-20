// https://ac.nowcoder.com/acm/problem/15054

#include <string>
#include <iostream>

using namespace std;
constexpr int maxn = 3;

int main()
{
    string s;
    cin >> s;
    string res;
    int cnt = 0;
    for (auto it = s.crbegin(); it != s.crend(); ++it) {
        if (cnt == maxn) {
            res = (*it) + string(",") + res;
            cnt = 1;
        } else {
            res = (*it) + res;
            ++cnt;
        }
    }
    cout << res << endl;
    return 0;
}