// https://open.kattis.com/problems/fodelsedagsmemorisering
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

unordered_map<string, pair<string, int> > unmap;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string name, birthday;
    int like;
    while (n--) {
        cin >> name >> like >> birthday;
        if (unmap.find(birthday) == unmap.end() || like > unmap[birthday].second) {
            unmap[birthday] = {name, like};
        }
    }
    vector<pair<string, int> > output(unmap.size());
    auto iter = unmap.cbegin();
    for (size_t i = 0; i != output.size(); ++i, ++iter) {
        output.at(i) = {iter->second.first, iter->second.second};
    }
    sort(output.begin(), output.end(), [](const pair<string, int> &l, const pair<string, int> &r) {
        return l.first < r.first;
    });
    cout << output.size() << '\n';
    for (const auto &[k, v] : output) {
        cout << k << '\n';
    }

    return 0;
}
