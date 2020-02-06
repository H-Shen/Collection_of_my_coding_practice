// https://open.kattis.com/problems/piglatin
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
inline
void read(T& t) {
    int n = 0; int c = getchar(); t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (n) t = -t;
}
template <typename T, typename... Args>
inline
void read(T& t, Args&... args) {
    read(t); read(args...);
}

template <typename T>
inline void write(T x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x) {
    write(x);
    puts("");
}

unordered_set<char> vowels = {'a','e','i','o','u','y'};
inline static
string solve(string s) {
    if (vowels.find(s.front()) != vowels.end()) {
        return s + "yay";
    }
    deque<char> temp(s.begin(), s.end());
    while (vowels.find(temp.front()) == vowels.end()) {
        temp.push_back(temp.front());
        temp.pop_front();
    }
    temp.push_back('a');
    temp.push_back('y');
    return string(temp.begin(), temp.end());
}

inline static
std::string join(const std::vector<std::string> &v, const std::string &str) {
    std::string s;
    for (auto p = cbegin(v); p != cend(v); ++p) {
        s.append(*p);
        if (p != cend(v) - 1) {
            s.append(str);
        }
    }
    return s;
}

inline static
string splitAndCombine(std::string s, const char &delim) {
    std::vector<std::string> res;
    std::istringstream f(s);
    std::string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    for (auto &i : res) {
        i = solve(i);
    }
    return join(res, " ");
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin, s)) {
        cout << splitAndCombine(s, ' ') << '\n';
    }

    return 0;
}
