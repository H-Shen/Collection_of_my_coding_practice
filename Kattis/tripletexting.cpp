// https://open.kattis.com/problems/tripletexting
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 105;
char str[MAXN];
unordered_map<string, int> A;

int main() {
    scanf("%s", str);
    string s(str);
    size_t length = s.size() / 3;
    ++A[s.substr(0, length)];
    ++A[s.substr(length, length)];
    ++A[s.substr(2 * length)];
    for (const auto &[k, v] : A) {
        if (v > 1) {
            printf("%s\n", k.c_str());
            break;
        }
    }
    return 0;
}
