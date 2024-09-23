// https://ac.nowcoder.com/acm/problem/17955

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    n *= 2;
    cout << (n * n + n + 2) / 2 << endl;
    return 0;
}