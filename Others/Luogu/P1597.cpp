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

unordered_map<char, string> var2val;

auto is_var = [](const string &s) {
    for (const auto &i : s) {
        if (isalpha(i)) {
            return true;
        }
    }
    return false;
};

int main() {

    var2val['a'] = "0";
    var2val['b'] = "0";
    var2val['c'] = "0";

    string expr;
    char ch;
    char varname;
    string val;
    while (~scanf("%c", &ch)) {
        if (ch == ';') {
            varname = expr.at(0);
            val = expr.substr(3);
            if (is_var(val)) {
                var2val[varname] = var2val[val.front()];
            } else {
                var2val[varname] = val;
            }
            expr = "";
        } else {
            expr.push_back(ch);
        }
    }
    printf("%s %s %s\n", var2val['a'].c_str(), var2val['b'].c_str(), var2val['c'].c_str());

    return 0;
}