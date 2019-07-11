// https://www.nowcoder.com/practice/f6bca30942874d01863ccfd44ae260f0

#include <iostream>

using namespace std;

int main() {

    long long x, k;
    string s;
    cin >> x >> k;
    while (x > 0) {
        s = to_string(x % k) + s;
        x /= k;
    }
    if (s.empty()) {
        cout << 0 << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}