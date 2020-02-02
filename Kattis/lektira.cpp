// https://open.kattis.com/problems/lektira
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 60;
char s[MAXN];

inline static
string solve(const string &str) {
    int n = static_cast<int>(str.size());
    string a;
    string b;
    string c;
    string result;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            a = "";
            b = "";
            c = "";
            for (int index = 0; index <= i; ++index) {
                a += str.at(index);
            }
            for (int index = i + 1; index <= j; ++index) {
                b += str.at(index);
            }
            for (int index = j + 1; index < n; ++index) {
                c += str.at(index);
            }
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            if (result.empty()) {
                result.append(a).append(b).append(c);
            } else {
                result = min(result, a + b + c);
            }
        }
    }
    return result;
}

int main() {

    scanf("%s", s);
    printf("%s\n", solve(s).c_str());

    return 0;
}
