
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector <int> A;
unordered_map <int, int> saveAns;

bool cmp (int x, int y) {
    return x > y;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, m, i, j, crnVal, lastVal;
    int len = 0;
    scanf("%d", &n);

    A.resize(n);
    scanf("%d", &crnVal);
    A[0] = crnVal;
    lastVal = crnVal;
    len++;

    for (i = 1; i < n; i++) {
        scanf("%d", &crnVal);
        if (crnVal == lastVal)
            continue;
        A[len] = crnVal;
        lastVal = crnVal;
        len++;
    }

    scanf("%d", &m);
    int idx;
    for (i = 0; i < m; i++) {
        scanf("%d", &crnVal);

        if (saveAns.find(crnVal) == saveAns.end()) {

            if (crnVal >= A[0]) {
                idx = 1;
            }
            else if (crnVal < A[len - 1]) {
                idx = len + 1;
            }
            else {
                idx = upper_bound(A.begin(), A.end(), crnVal, cmp) - A.begin();
                if (!binary_search(A.begin(), A.end(), crnVal, cmp)) {
                    idx++;
                }
            }
            saveAns[crnVal] = idx;
            printf("%d\n", idx);
        }
        else {
            printf("%d\n", saveAns[crnVal]);
        }
    }

    return 0;
}
