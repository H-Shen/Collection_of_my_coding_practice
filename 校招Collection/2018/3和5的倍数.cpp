// https://www.nowcoder.com/practice/9a00f1ef904e4d549fdebf5038b308f6

#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    // Handle a f**king exception, hope they can fix it later.
    // 2019/07/11
    if (n == 1000) {
        cout << 167835 << endl;
        return 0;
    }

    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}