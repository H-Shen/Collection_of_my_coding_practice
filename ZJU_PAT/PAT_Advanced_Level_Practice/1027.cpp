#include <bits/stdc++.h>

using namespace std;
constexpr int RADIX = 13;

string f(int n) {
    string ans;
    while (n > 0) {
        int temp = n % RADIX;
        if (temp < 10) {
            ans.push_back(temp+'0');
        } else {
            ans.push_back(temp-10+'A');
        }
        n /= RADIX;
    }
    if (ans.empty()) ans = "0";
    reverse(ans.begin(),ans.end());
    if (ans.size() == 1) ans = '0' + ans;
    return ans;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << '#' << f(a) << f(b) << f(c) << '\n';
    return 0;
}
