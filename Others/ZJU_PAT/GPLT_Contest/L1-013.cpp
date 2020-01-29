#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
int s[maxn];

int main() {
    int i;
    int res = 1, sum = 0;
    for (i = 1; i <= 11; ++i) {
        res *= i;
        sum += res;
        s[i] = sum;
    }
    int n;
    cin >> n;
    cout << s[n] << endl;
}