// https://www.nowcoder.com/practice/6d27688e056c491b9024fa1340404666

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    string s;
    cin >> s;
    string a, b;
    for (const auto &ch : s) {
        if (isdigit(ch)) {
            b += ch;
        } else {
            a += ch;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a << b << endl;

    return 0;
}