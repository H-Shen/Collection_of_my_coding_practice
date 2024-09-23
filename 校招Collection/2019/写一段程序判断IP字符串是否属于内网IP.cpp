// https://www.nowcoder.com/practice/80ce674313ff43af9d7ac7a41ae21527

#include <bits/stdc++.h>

using namespace std;

bool judge(int a, int b, int c, int d) {

    // 10.0.0.0 – 10.255.255.255
    if (a == 10) {
        if (b >= 0 && b <= 255) {
            if (c >= 0 && c <= 255) {
                if (d >= 0 && d <= 255) {
                    return true;
                }
            }
        }
    }

    // 172.16.0.0 – 172.31.255.255
    if (a == 172) {
        if (b >= 16 && b <= 31) {
            if (c >= 0 && c <= 255) {
                if (d >= 0 && d <= 255) {
                    return true;
                }
            }
        }
    }

    // 192.168.0.0 – 192.168.255.255
    if (a == 192) {
        if (b == 168) {
            if (c >= 0 && c <= 255) {
                if (d >= 0 && d <= 255) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {

    int a, b, c, d;
    char ch;
    cin >> a >> ch >> b >> ch >> c >> ch >> d;
    if (judge(a, b, c, d)) {
        cout << "1";
    } else {
        cout << "0";
    }
    cout << endl;

    return 0;
}