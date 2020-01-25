// https://open.kattis.com/problems/irepeatmyself
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr size_t MAXN = 75;

// Check if s1 is a prefix of s
inline static
bool is_prefix(const string &s1, const string &s) {
    return mismatch(s1.begin(), s1.end(), s.begin()).first == s1.end();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.get();
    string s;
    string substring;
    int counter;
    while (n--) {
        getline(cin, s);
        counter = 1;
        while (true) {
            substring = s.substr(0, counter);
            while (substring.size() < MAXN) {
                substring += substring;
            }
            if (is_prefix(s, substring)) {
                break;
            }
            ++counter;
        }
        cout << counter << '\n';
    }

    return 0;
}
