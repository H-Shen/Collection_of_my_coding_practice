#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, m, val;
    scanf("%d %d", &n, &m);
    deque<int> A;
    int length = 0;
    int sum = 0;
    int min_sum = numeric_limits<int>::max();
    while (length < m) {
        scanf("%d", &val);
        A.push_back(val);
        ++length;
        sum += val;
        --n;
    }
    min_sum = min(min_sum, sum);
    while (n--) {
        scanf("%d", &val);
        sum -= A.front();
        A.pop_front();
        sum += val;
        A.push_back(val);
        min_sum = min(min_sum, sum);
    }
    printf("%d\n", min_sum);
    
    return 0;
}
