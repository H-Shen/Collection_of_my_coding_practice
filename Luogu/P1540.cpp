#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    size_t m;
    int n, val;
    scanf("%zd %d", &m, &n);
    unordered_set<int> A;
    deque<int> B;
    int counter = 0;
    while (n--) {
        scanf("%d", &val);
        if (A.find(val) == A.end()) {
            A.insert(val);
            ++counter;
            if (B.size() == m) {
                A.erase(B.front());
                B.pop_front();
            }
            B.emplace_back(val);
        }
    }
    printf("%d\n", counter);

    return 0;
}