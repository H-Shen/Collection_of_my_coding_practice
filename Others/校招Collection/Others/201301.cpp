// https://www.nowcoder.com/practice/9af744a3517440508dbeb297020aca86

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    int n = static_cast<int>(S.size());
    sort(S.begin(), S.end());
    int a = (1 << n);
    vector<vector<int> > result_copy;
    set<vector<int> > result;
    for (int i = 0; i < a; i++) {
        vector<int> comb;
        for (int j = 0; j < n; j++) {
            if ((i >> j) % 2 == 1) {
                comb.push_back(S[j]);
            }
        }
        result.insert(comb);
    }
    copy(result.begin(), result.end(), back_inserter(result_copy));
    return result_copy;
}

int main() {

    int n, i, len;
    while (~scanf("%d", &n)) {
        vector<int> a(static_cast<unsigned long>(n));
        vector<int> b, c, d;
        int sum_b = 0, sum_c = 0, sum_d = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] % 5 == 0) {
                b.push_back(a[i]);
                sum_b += a[i];
            } else if (a[i] % 3 == 0 && a[i] % 15 != 0) {
                c.push_back(a[i]);
                sum_c += a[i];
            } else {
                d.push_back(a[i]);
                sum_d += a[i];
            }
        }

        int k = sum_d - sum_b + sum_c;
        bool haveAns = false;

        if (k % 2 != 0)
            haveAns = false;
        else {
            k /= 2;
            vector<vector<int> > subsets = subsetsWithDup(d);
            len = static_cast<int>(subsets.size());
            for (i = 0; i < len; i++) {
                if (accumulate(subsets[i].begin(), subsets[i].end(), 0) == k) {
                    haveAns = true;
                    break;
                }
            }
        }

        if (!haveAns)
            printf("false\n");
        else
            printf("true\n");
    }
    return 0;
}