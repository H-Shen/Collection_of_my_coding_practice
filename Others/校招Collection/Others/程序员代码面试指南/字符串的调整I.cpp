// https://www.nowcoder.com/practice/c53c017b757d4c02b6666b40bfa49a27

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    char ch;
    int asteriskCount = 0;
    vector<char> A;
    while (cin >> ch) {
        if (ch == '*') {
            ++asteriskCount;
        } else if (ch != '\n') {
            A.emplace_back(ch);
        }
    }
    while (asteriskCount--) {
        cout << '*';
    }
    for (const char &i : A){
        cout << i;
    }
    cout << endl;

    return 0;
}