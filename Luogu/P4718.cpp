// A demo that uses linux/factor in Cpp
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

constexpr int MAXN = 200;
char output_buffer[MAXN];

inline static
bool prime_check(string s, ll & largest_factor) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, ' ')) {
        res.emplace_back(s);
    }
    if (res.size() == 2) {
        return false;
    }
    largest_factor = stoll(res.back());
    return true;
}

int main() {

    int t;
    ll n, largest_factor;
    string command;
    FILE *fp;
    IO::read(t);
    while (t--) {
        IO::read(n);
        command = "factor " + to_string(n);
        fp = popen(command.c_str(), "r");
        if (!fp) {
            return -1;
        }
        fgets_unlocked(output_buffer, sizeof(output_buffer), fp);
        string output = output_buffer;
        output.pop_back();
        if (prime_check(output, largest_factor)) {
            IO::writeln(largest_factor);
        } else {
            fputs_unlocked("Prime\n", stdout);
        }
        pclose(fp);
    }

    return 0;
}
