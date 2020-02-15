#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 15;
char cstr[MAXN];

int main() {

    int n;
    scanf("%d", &n);
    unordered_map<string, int> A;
    string s;
    for (int i = 1; i <= n; ++i) {
        s.push_back(i + '0');
    }
    int counter = 1;
    do {
        A[s] = counter;
        ++counter;
    } while (next_permutation(s.begin(), s.end()));
    scanf("%s", cstr);
    printf("%d\n", A[cstr]);

    return 0;
}