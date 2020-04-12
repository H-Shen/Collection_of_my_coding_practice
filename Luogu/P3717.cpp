#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    vector<pair<int, int> > A(m);
    for (auto &i : A) {
        scanf("%d %d", &i.first, &i.second);
    }
    unordered_set<string> result;
    string s;
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j) {
            for (const auto &[a, b] : A) {
                if ((i-a)*(i-a)+(j-b)*(j-b)<=r*r) {
                    s = to_string(i) + ' ' + to_string(j);
                    result.insert(s);
                }
            }
        }
    }
    printf("%lu\n", result.size());

    return 0;
}
