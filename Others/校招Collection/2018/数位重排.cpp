// https://www.nowcoder.com/practice/f970201e9f7e4040ab25a40918e27d15

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int t;
    int n;
    string s, s_copy;

    cin >> t;
    while (t--) {
        bool hasAns = false;
        cin >> n;
        s = to_string(n);
        s_copy = s;
        sort(s.begin(), s.end());
        do {
            if (s[0] != '0' && s != s_copy && (stoi(s) % n == 0)) {
                cout << "Possible";
                hasAns = true;
                break;
            }
        } while (next_permutation(s.begin(), s.end()));

        if (!hasAns) {
            cout << "Impossible";
        }
        cout << endl;
    }
    return 0;
}