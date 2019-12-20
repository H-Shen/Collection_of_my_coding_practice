// https://www.nowcoder.com/practice/56c6fb8231a44ed8ab91ac231f7b2c63

#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    int n;

    cin >> s >> n;
    int len = static_cast<int>(s.size());
    if (n <= 0 || n > len) {
        cout << "-1";
    } else {
        bool firstItem = true;
        for (int i = 0; i + n <= len; ++i) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << " ";
            }
            cout << s.substr(i, n);
        }
    }
    cout << endl;
    return 0;
}