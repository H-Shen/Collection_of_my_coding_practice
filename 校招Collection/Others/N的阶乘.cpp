// https://www.nowcoder.com/practice/f54d8e6de61e4efb8cce3eebfd0e0daa

#include <iostream>
#include <string>

using namespace std;
const int L_FAC = 100005;
int a[L_FAC];

string fac(int n) {

    if (n == 0)
        return "1";

    string ans;
    fill(a, a + L_FAC, 0);
    int s = 0, m = n;
    while (m)
        a[++s] = m % 10, m /= 10;
    for (int i = n - 1; i >= 2; i--) {
        int w = 0;
        for (int j = 1; j <= s; j++) {
            a[j] = a[j] * i + w;
            w = a[j] / 10;
            a[j] = a[j] % 10;
        }
        while (w) {
            a[++s] = w % 10;
            w /= 10;
        }
    }
    while (!a[s])
        s--;
    while (s >= 1)
        ans += a[s--] + '0';
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n)
        cout << fac(n) << endl;
    return 0;
}
