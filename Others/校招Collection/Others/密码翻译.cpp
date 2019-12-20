// https://www.nowcoder.com/practice/136de4a719954361a8e9e41c8c4ad855

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    while (getline(cin, s)) {
        for (auto &&i : s) {
            if (i == 'z') {
                i = 'a';
            } else if (i == 'Z') {
                i = 'Z';
            } else if (isalpha(i)) {
                ++i;
            }
        }
        cout << s << endl;
    }

    return 0;
}