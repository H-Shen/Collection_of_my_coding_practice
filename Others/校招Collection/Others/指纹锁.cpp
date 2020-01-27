// https://ac.nowcoder.com/acm/problem/17508
// Please compile it in C++11(Clang++3.9) since they have some optimizations for it

#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

constexpr int MAXLENGTH = 10;
char op[MAXLENGTH];

static int k;

struct Compare {
    bool operator() (const int &a, const int &b) const {
        if (abs(a - b) <= k) {
            return false;
        }
        return a<b;
    }
};

// All elements in this set will satisfy that, for every two unique element a, b
// abs(a - b) > k

set<int, Compare> temp_set;

int main() {

    int m, val;
    scanf("%d %d", &m, &k);
    while (m--) {
        scanf("%s %d", op, &val);
        if (strcmp(op, "add") == 0) {
            // If there exists an element E in set such that
            // abs(E - val) <= k, val will be considered as the same as E
            // and the insertion will be ignored
            temp_set.insert(val);
        } else if (strcmp(op, "query") == 0) {
            // If there exists an element E in set such that
            // abs(E - val) <= k, the boolean expression below will return true
            if (temp_set.find(val) != temp_set.end()) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            // When we deleted val, then actually we deleted all E such that
            // abs(E - val) <= k
            temp_set.erase(val);
        }
    }
    return 0;
}