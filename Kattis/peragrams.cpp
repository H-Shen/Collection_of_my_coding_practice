// https://open.kattis.com/problems/peragrams

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    unordered_map <char, int> A;
    for (const auto & ch : s) {
        ++A[ch];
    }
    int cnt = 0;
    bool firstOdd = true;
    for (const auto & it : A) {
        if (it.second % 2 != 0) {
            if (firstOdd) {
                firstOdd = false;
            } else {
                ++cnt;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
