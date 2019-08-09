// https://ac.nowcoder.com/acm/problem/15869

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << 4 * ((int) sqrt((double) b * c / a) +
                 (int) sqrt((double) b * a / c) +
                 (int) sqrt((double) a * c / b))
         << endl;
    return 0;
}