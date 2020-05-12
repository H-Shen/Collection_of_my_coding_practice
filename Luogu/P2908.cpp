#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 1005;
char s[MAXN];

inline static
bool has_substring(const string &text, const string &pattern) {
    deque<char> text_deque(text.begin(), text.end());
    deque<char> pattern_deque(pattern.begin(), pattern.end());
    while (!text_deque.empty()) {
        if (pattern_deque.empty()) {
            break;
        }
        if (text_deque.front() == pattern_deque.front()) {
            text_deque.pop_front();
            pattern_deque.pop_front();
        } else {
            text_deque.pop_front();
        }
    }
    return pattern_deque.empty();
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> A(n);
    for (auto &i : A) {
        scanf("%s", s);
        i = s;
        for (auto &ch : i) {
            ch = tolower(ch);
        }
    }
    vector<string> B(m);
    for (auto &i : B) {
        scanf("%s", s);
        i = s;
        for (auto &ch : i) {
            ch = tolower(ch);
        }
    }
    vector<int> output(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (has_substring(A.at(i), B.at(j))) {
                ++output.at(i);
            }
        }
    }
    for (const auto &i : output) {
        printf("%d\n", i);
    }

    return 0;
}
