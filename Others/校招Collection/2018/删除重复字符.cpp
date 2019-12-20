// https://www.nowcoder.com/practice/c4ea1f2263434861aef111aa44a5b064

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
const int maxn = 1005;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    unordered_set<char> dict;
    vector<char> result(maxn);
    size_t pos = 0;
    for (const char &ch : s) {
        if (dict.find(ch) == dict.end()) {
            result[pos++] = ch;
            dict.insert(ch);
        }
    }
    for (size_t i = 0; i != pos; ++i) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}