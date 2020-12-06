// https://open.kattis.com/problems/heimavinna
//
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

const regex r("[^;]+");
constexpr int MAXN = 1005;
bitset<MAXN> problems;

inline static
pair<int, int> parse(const string &s) {
    string fst, snd;
    pair<int, int> result;
    auto iter = s.cbegin();
    bool found = false;
    for (; iter != s.cend(); ++iter) {
        if (*iter == '-') {
            found = true;
            break;
        } else {
            fst += *iter;
        }
    }
    if (!found) {
        result.first = stoi(fst);
        result.second = result.first;
    } else {
        ++iter;
        for (; iter != s.cend(); ++iter) {
            snd += *iter;
        }
        result.first = stoi(fst);
        result.second = stoi(snd);
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    pair<int, int> temp;
    cin >> s;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
        temp = parse(it->str());
        for (int i = temp.first; i <= temp.second; ++i) {
            problems[i] = true;
        }
    }
    cout << problems.count() << '\n';
    return 0;
}
