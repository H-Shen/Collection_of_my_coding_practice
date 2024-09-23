#include <bits/stdc++.h>

using namespace std;

const vector<string> dict{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (const auto &p : s) { sum = sum + (p - '0'); }
    string num = to_string(sum);
    string res;

    for (int i = 0; i < static_cast<int>(num.size()) - 1; ++i) {
        res += dict[num[i] - '0'] + ' ';
    }
    res += dict[num[static_cast<int>(num.size()) - 1] - '0'];
    cout << res << endl;

    return 0;
}
