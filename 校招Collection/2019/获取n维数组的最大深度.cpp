// https://www.nowcoder.com/practice/08707b9b484f4ca4943f108c709dab96

#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    getline(cin, s);
    int maxLen = 0;
    int currentLen = 0;
    for (const char &ch : s) {
        if (ch == '[') {
            ++currentLen;
            maxLen = max(maxLen, currentLen);
        } else if (ch == ']') {
            --currentLen;
        }
    }
    cout << maxLen << endl;
    return 0;
}