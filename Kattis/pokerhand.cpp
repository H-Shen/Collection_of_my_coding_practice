// https://open.kattis.com/problems/pokerhand

#include <bits/extc++.h>

using namespace std;

int main() {
    string s;
    unordered_map<char, int> A;

    while (cin >> s) {
        ++A[s[0]];
    }

    int maxVal = -1;
    for (const auto &it : A) {
        maxVal = max(maxVal, it.second);
    }
    cout << maxVal << endl;
    return 0;
}
