// https://ac.nowcoder.com/acm/problem/15722

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    int T, n;
    bool isNoob = false;

    cin >> T;
    while (T--) {
        isNoob = false;
        cin >> n;
        while (n--) {
            cin >> s;
            if (s != "PERFECT") {
                isNoob = true;
            }
        }
        if (isNoob) {
            cout << "NAIVE Noob";
        } else {
            cout << "MILLION Master";
        }
        cout << endl;
    }
}