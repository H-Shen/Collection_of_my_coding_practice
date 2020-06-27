#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
bool isPalindrome(const std::string_view &A) {
    if (!A.empty()) {
        size_t len = A.size();
        size_t half = (len - 1) / 2;
        for (size_t i = 0; i <= half; ++i) {
            if (A.at(i) != A.at(len - i - 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    cin >> s;
    int n = static_cast<int>(s.size());
    int max_size = 0;
    string_view sv(s);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (!isPalindrome(sv.substr(i, j - i + 1))) {
                max_size = max(max_size, static_cast<int>(sv.substr(i, j - i +
                                                                       1).size()));
            }
        }
    }
    cout << max_size << '\n';

    return 0;
}