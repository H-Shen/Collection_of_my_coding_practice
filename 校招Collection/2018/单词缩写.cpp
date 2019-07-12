// https://www.nowcoder.com/practice/af2c953f9fc8464fa0e3252da8eb4131

#include <string>
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s.size() >= 10) {
            cout << s.front() << to_string(s.size() - 2) << s.back() << endl;
        } else {
            cout << s << endl;
        }
    }
    return 0;
}