#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll gap = '0';

unordered_map<char, string> A = {{'0', "ling"},
                                 {'1', "yi"},
                                 {'2', "er"},
                                 {'3', "san"},
                                 {'4', "si"},
                                 {'5', "wu"},
                                 {'6', "liu"},
                                 {'7', "qi"},
                                 {'8', "ba"},
                                 {'9', "jiu"}};

int main() {
    string s;
    ll sum = 0;
    cin >> s;
    for (auto ch : s) {
        sum = sum + (ll) ch - gap;
    }
    string res = to_string(sum);
    for (size_t i = 0; i != res.size() - 1; ++i) {
        cout << A[res[i]] << ' ';
    }
    cout << A[res[res.size() - 1]] << endl;
    return 0;
}