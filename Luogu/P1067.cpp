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

struct Node {
    int coeff;
    int power;
    [[nodiscard]] string to_string() const {
        if (coeff == 0) {
            return "";
        }
        string result;
        if (coeff > 0) {
            result.push_back('+');
        } else {
            result.push_back('-');
        }
        if (abs(coeff) != 1) {
            result += ::to_string(abs(coeff));
        } else {
            if (power == 0) {
                result.push_back('1');
            }
        }

        if (power != 0) {
            result.push_back('x');
            if (power != 1) {
                result.push_back('^');
                result += ::to_string(power);
            }
        }
        return result;
    }
};

int main() {

    int n;
    IO::read(n);
    ++n;
    vector<Node> A(n);
    for (int i = n - 1; i >= 0; --i) {
        IO::read(A.at(i).coeff);
        A.at(i).power = i;
    }
    reverse(A.begin(), A.end());
    string output;
    for (const auto &i : A) {
        output += i.to_string();
    }
    if (output.size() > 1 && output.front() == '+') {
        output = output.substr(1);
    }
    if (output.empty()) {
        output = "0";
    }
    printf("%s\n", output.c_str());
    return 0;
}
