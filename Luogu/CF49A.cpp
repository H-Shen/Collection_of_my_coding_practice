#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    string vowel = "aeiouyAEIOUY";
    unordered_set<char> vowel_set(vowel.begin(), vowel.end());

    string s;
    getline(cin, s);
    for (auto iter = s.crbegin(); iter != s.crend(); ++iter) {
        if (isalpha(*iter)) {
            if (vowel_set.find(*iter) != vowel_set.end()) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            break;
        }
    }
    return 0;
}
