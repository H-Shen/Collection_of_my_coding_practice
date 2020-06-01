#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 105;
char s[MAXN];

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d %s", &n, s);
    vector<int> indices_of_one;
    for (int i = 0; s[i] != 0; ++i) {
        if (s[i] == '1') {
            indices_of_one.emplace_back(i);
        }
    }
    int d = -1;
    int length = static_cast<int>(indices_of_one.size());
    for (int i = 0; i < length - 1; ++i) {
        if (d == -1) {
            d = indices_of_one.at(i + 1) - indices_of_one.at(i);
        } else if (d != indices_of_one.at(i + 1) - indices_of_one.at(i)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}
