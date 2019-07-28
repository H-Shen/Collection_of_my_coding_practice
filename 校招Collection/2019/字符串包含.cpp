// https://www.nowcoder.com/practice/661e24c11de64e78804fdce653dafb0e

#include <bits/stdc++.h>

using namespace std;

int main() {

    string a, b;
    while (cin >> a >> b) {
        if (b.size() > a.size()) {
            swap(a, b);
        }
        if (a.find(b) != string::npos) {
            cout << 1;
        } else {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}