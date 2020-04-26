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

int songNumber = 0;

inline static
vector<int> merge(const vector<vector<int> > &A) {
    if (A.size() == 1) {
        return A.front();
    }
    vector<int> res = A.front();
    vector<int> temp;
    for (size_t i = 1; i != A.size(); ++i) {
        vector<int>().swap(temp);
        set_union(res.begin(), res.end(), A.at(i).begin(), A.at(i).end(), back_inserter(temp));
        res = temp;
    }
    return res;
}

int main() {

    int n;
    IO::read(n);
    vector<vector<int> > Counter(n + 5);

    int e;
    int k;
    IO::read(e); // e nights
    bool hasBard;
    for (int i = 0; i < e; ++i) {
        hasBard = false;
        IO::read(k);
        vector<int> A(k);
        for (int j = 0; j < k; ++j) {
            IO::read(A.at(j));
            if (A.at(j) == 1) {
                hasBard = true;
            }
        }
        if (hasBard) {
            for (const auto &item : A) {
                Counter[item].emplace_back(songNumber);
            }
            ++songNumber;
        } else {
            // exchange all songs
            vector<vector<int> > temp;
            for (const auto &item : A) {
                temp.emplace_back(Counter.at(item));
            }
            vector<int> temp_vec = merge(temp);
            // update
            for (const auto &item : A) {
                Counter.at(item) = temp_vec;
            }
        }
    }
    // output
    vector<int> output;
    for (int i = 1; i <= n; ++i) {
        if (Counter[i].size() == Counter[1].size()) {
            output.emplace_back(i);
        }
    }
    for (const auto &i : output) {
        IO::writeln(i);
    }

    return 0;
}

