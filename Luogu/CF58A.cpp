#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 105;
char s[MAXN];
deque<char> vec = {'h', 'e', 'l', 'l', 'o'};

int main() {

    scanf("%s", s);
    string str(s);
    for (const char &ch : s) {
        if (!vec.empty() && ch == vec.front()) {
            vec.pop_front();
        }
        if (vec.empty()) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}