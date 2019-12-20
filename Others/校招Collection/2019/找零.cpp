// https://www.nowcoder.com/practice/944e5ca0ea88471fbfa73061ebe95728

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    n = 1024 - n;
    int a = n / 64;
    n = n - a * 64;
    int b = n / 16;
    n = n - b * 16;
    int c = n / 4;
    n = n - c * 4;
    int d = n;
    cout << a + b + c + d << endl;
    return 0;
}