// https://www.nowcoder.com/practice/bba8c89fddf7462e8c6aae4791b36e23

#include <iostream>

using namespace std;

int main() {

    int m, n;
    cin >> m;
    while (m--) {
        cin >> n;
        if (n < 0) {
            n = -n;
            cout << "-";
        }
        cout << 3 * n * (n + 1) / 2 << endl;
    }

    return 0;
}