#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    string s;
    cin >> n >> s;
    unordered_map<string, int> A;
    int length = static_cast<int>(s.size());
    for (int i = 0; i < length; ++i) {
        for (int j = i; j < length; ++j) {
            ++A[s.substr(i, j - i + 1)];
        }
    }

    unordered_set<string> occurOnce;
    for (const auto &[k, v] : A) {
        if (v == 1) {
            occurOnce.insert(k);
        }
    }

    for (int len = 1; len <= length; ++len) {
        unordered_set<string> temp_set;
        bool haveAns = true;
        for (int i = 0; i + len <= length; ++i) {
            temp_set.insert(s.substr(i, len));
        }
        // check
        for (const string &i : temp_set) {
            if (occurOnce.find(i) == occurOnce.end()) {
                haveAns = false;
                break;
            }
        }
        if (haveAns) {
            printf("%d\n", len);
            return 0;
        }
    }


    return 0;
}