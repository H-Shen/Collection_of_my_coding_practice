// https://open.kattis.com/problems/names
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 105;
char str[MAXN];

inline static
int check_palindrome(const string &A) {
    int count = 0;
    if (!A.empty()) {
        size_t len = A.size();
        size_t half = (len - 1) / 2;
        for (size_t i = 0; i <= half; ++i) {
            if (A.at(i) != A.at(len - i - 1)) {
                ++count;
            }
        }
    }
    return count;
}

inline static
vector<string> generate_all_strings(const string &s) {

    deque<char> s_copy(s.begin(), s.end());
    s_copy.pop_back();
    reverse(s_copy.begin(), s_copy.end());
    vector<string> ret;
    ret.emplace_back(s);

    vector<string> temp;
    while (!s_copy.empty()) {
        temp.emplace_back(s + string(s_copy.begin(), s_copy.end()));
        s_copy.pop_front();
    }
    reverse(temp.begin(), temp.end());
    for (const auto &i : temp) {
        ret.emplace_back(i);
    }
    return ret;
}

int main() {
    
    scanf("%s", str);
    string s(str);
    int n = static_cast<int>(s.size());
    int min_counter = numeric_limits<int>::max();
    int counter = 0;
    if (n > 1) {
        auto p = generate_all_strings(s);
        for (const auto &i : p) {
            counter = check_palindrome(i) + static_cast<int>(i.size() - s.size());
            min_counter = min(min_counter, counter);
        }
    } else {
        min_counter = 0;
    }
    printf("%d\n", min_counter);

    return 0;
}
