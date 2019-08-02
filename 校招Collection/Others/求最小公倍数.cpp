// https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef __GNUC__
    long long a, b;
    cin >> a >> b;
    cout << a * b / __gcd(a, b) << endl;
#endif
    return 0;
}