// https://www.nowcoder.com/practice/4f31423f126749ab9196c97c5117bcb9

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    bool firstItem = true;
    cout << "[";
    do {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ", ";
        }
        cout << s;
    } while (next_permutation(s.begin(), s.end()));
    cout << "]" << endl;
    return 0;
}