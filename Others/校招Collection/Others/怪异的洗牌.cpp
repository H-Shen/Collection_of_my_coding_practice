// https://www.nowcoder.com/practice/1801ea11cc9d4732a7f0cb2b0b75c8cf

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, pos;
    while (cin >> n >> k) {
        vector<int> a(n);
        for (int i = 1; i <= n; i++)
            a[i - 1] = i;
        for (int j = 1; j <= k; j++) {
            cin >> pos;
            rotate(a.begin(), a.begin() + pos, a.end());
            if (n % 2 == 0)
                reverse(a.begin(), a.begin() + n / 2);
            else
                reverse(a.begin(), a.begin() + (n - 1) / 2);
        }
        for (int m = 0; m < n; m++)
            cout << a[m] << ' ';
        cout << endl;
    }
    return 0;
}