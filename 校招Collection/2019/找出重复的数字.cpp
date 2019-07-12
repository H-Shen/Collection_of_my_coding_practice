// https://www.nowcoder.com/practice/1664fe871878496aa600b6e09557982b

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

    ll S = 0;
    ll X = 0;
    ll n = -1;
    ll temp;
    while (cin >> temp) {
        n = max(n, temp);
        S += temp;
    }
    X = S - (1 + n) * n / 2;
    cout << X << endl;

    return 0;
}