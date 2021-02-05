#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

int booth(string s) {
    s += s; // Concatenate string to it self to avoid modular arithmetic
    int length = (int)s.size();
    vector<int> f(length, -1);    // Failure function
    int k = 0;  // Least rotation of string found so far
    for (int j = 1, i; j < length; ++j) {
        char sj = s.at(j);
        i = f.at(j - k - 1);
        while (i != -1 && sj != s.at(k + i + 1)) {
            if (sj < s.at(k + i + 1)) {
                k = j - i - 1;
            }
            i = f.at(i);
        }
        if (sj != s.at(k + i + 1)) {
            if (sj < s.at(k)) {
                k = j;
            }
            f.at(j - k) = -1;
        } else {
            f.at(j - k) = i + 1;
        }
    }
    return k;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, i;
    string s, s1, s2;
    unordered_set<string> unset;
    unordered_set<string> dup;
    cin >> n;
    while (n--) {
        cin >> s;
        if (dup.find(s) != dup.end()) {
            cout << "Yes" << '\n';
            return 0;
        }
        dup.insert(s);
        s1 = s;
        s2 = s;
        i = booth(s1);
        rotate(s1.begin(), s1.begin() + i, s1.end());
        reverse(s2.begin(), s2.end());
        i = booth(s2);
        rotate(s2.begin(), s2.begin() + i, s2.end());
        if (unset.find(s1) != unset.end() || unset.find(s2) != unset.end()) {
            cout << "Yes" << '\n';
            return 0;
        }
        unset.insert(s1);
        unset.insert(s2);
    }
    cout << "No" << '\n';

    return 0;
}
