// https://open.kattis.com/problems/symmetricorder

#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int cnt = 1;
    int n;
    string s;
    bool change = false;

    while (true) {
        change = false;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<string> A;
        deque<string> Left, Right;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            A.push_back(s);
        }
        for (const auto &i : A) {
            if (!change) {
                Left.push_back(i);
                change = true;
            } else {
                Right.push_front(i);
                change = false;
            }
        }
        cout << "SET " << cnt << endl;
        ++cnt;
        for (const auto &i : Left) {
            cout << i << endl;
        }
        for (const auto &i : Right) {
            cout << i << endl;
        }
    }


    return 0;
}
