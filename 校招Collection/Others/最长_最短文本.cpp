#include <iostream>
#include <string>
// https://www.nowcoder.com/practice/3331d16fe07d4358858178ff5fa73e0d

#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<string> A;
    string s;
    size_t maxLen = 0;
    size_t minLen = 1005;
    while (getline(cin, s)) {
        A.emplace_back(s);
        maxLen = max(maxLen, s.size());
        minLen = min(minLen, s.size());
    }
    for (const auto &i : A) {
        if (i.size() == minLen) {
            cout << i << endl;
        }
    }
    for (const auto &i : A) {
        if (i.size() == maxLen) {
            cout << i << endl;
        }
    }
    return 0;
}