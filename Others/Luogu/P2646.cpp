#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 1000005;

char s[MAXN];
vector<int> positions_of_z;
vector<int> positions_of_y;

int main() {

    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == 'z') {
            positions_of_z.emplace_back(i);
        } else if (s[i] == 'y') {
            positions_of_y.emplace_back(i);
        }
    }
    if (positions_of_z.size() < 2 || positions_of_y.empty()) {
        printf("0\n");
        return 0;
    }
    ll sum = 0;
    ll left, right;
    for (size_t i = 1; i != positions_of_z.size(); ++i) {
        left = i;
        right = positions_of_y.end() - lower_bound(positions_of_y.begin(), positions_of_y.end(), positions_of_z.at(i));
        sum += left * right;
    }
    printf("%lld\n", sum);

    return 0;
}
