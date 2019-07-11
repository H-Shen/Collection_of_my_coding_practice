// https://open.kattis.com/problems/closestsums
#include <string>
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 500005;
int sum[maxn];

int main()
{

    ios_base::sync_with_stdio(false);
    int kase = 1;
    int n;

    while (cin >> n)
    {
        vector<int> A(n);
        for (auto &&i : A) {
            cin >> i;
        }

        int len = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                sum[len++] = A[i] + A[j];
            }
        }
        sort(sum, sum + len);

        int m, val;
        cin >> m;
        cout << "Case " << kase << ":" << endl;
        while (m--) {
            cin >> val;
            if (binary_search(sum, sum + len, val)) {
                cout << "Closest sum to " << val << " is " << val << "." << endl;
            } else if (val < sum[0]) {
                cout << "Closest sum to " << val << " is " << sum[0] << "." << endl;
            } else if (val > sum[len - 1]) {
                cout << "Closest sum to " << val << " is " << sum[len - 1] << "." << endl;
            } else {
                int lowerPos = lower_bound(sum, sum + len, val) - sum;
                if (abs(sum[lowerPos - 1] - val) < abs(sum[lowerPos] - val)) {
                    cout << "Closest sum to " << val << " is " << sum[lowerPos - 1] << "." << endl;
                } else {
                    cout << "Closest sum to " << val << " is " << sum[lowerPos] << "." << endl;
                }
            }
        }
        ++kase;
    }
    return 0;
}
