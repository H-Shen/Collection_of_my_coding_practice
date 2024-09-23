// https://www.nowcoder.com/practice/b6edb5ca15d34b1eb42e4725a3c68eba

#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    bool haveAns;
    string s;
    cin >> n;
    while (n--) {
        haveAns = false;
        cin >> s;
        for (size_t i = 0; i != s.size(); ++i) {
            if (s.at(i) != s.at(s.size() - 1 - i)) {
                haveAns = true;
                // Case 1:
                if (s.at(i + 1) == s.at(s.size() - 1 - i)) {
                    cout << i << endl;
                    break;
                }
                // Case 2:
                cout << s.size() - 1 - i << endl;
                break;
            }
        }
        // Case 3:
        if (!haveAns) {
            cout << -1 << endl;
        }
    }
    return 0;
}