// https://www.nowcoder.com/practice/a30bbc1a0aca4c27b86dd88868de4a4a

#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    int n;
    while (cin >> s >> n) {
        string res;
        int i = 0;
        while (i < n) {
            if (s[i] < 0) {
                if (i + 2 > n)
                    break;
                res = res + s[i];
                i += 2;
            } else {
                res = res + s[i];
                i++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
