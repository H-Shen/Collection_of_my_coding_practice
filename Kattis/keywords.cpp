// https://open.kattis.com/problems/keywords
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 30;
char cstr[MAXN];

int main() {

    unordered_set<string> A;
    int n;
    string s;
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%[^\n]", cstr);
        getchar();
        s = cstr;
        for (auto &i : s) {
            i = tolower(i);
            if (i == '-') {
                i = ' ';
            }
        }
        A.insert(s);
    }
    printf("%lu\n", A.size());
    return 0;
}
