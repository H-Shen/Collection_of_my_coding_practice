// https://www.nowcoder.com/practice/a83e1893f5df4285a1796b34e1e7c9b3

#include <bits/stdc++.h>

using namespace std;

inline static
unordered_map<char, int> getCharFreq(const string &s) {
    unordered_map<char, int> res;
    for (const char &ch : s) {
        ++res[ch];
    }
    return res;
}

inline static
bool judge(unordered_map<char, int> A, unordered_map<char, int> B) {
    for (const auto &i : A) {
        if (B.find(i.first) == B.end()) {
            return false;
        }
        if (B[i.first] < i.second) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    auto freq_s = getCharFreq(S);
    auto freq_t = getCharFreq(T);
    cout << boolalpha << judge(freq_s, freq_t) << endl;

    return 0;
}