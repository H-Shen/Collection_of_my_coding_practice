// This is an example of Discretization
//
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<pair<int, int> > Merge(const vector<bool> &a) {
    int start_index = -1;
    int stop_index = -1;
    vector<pair<int, int> > result;
    int length = static_cast<int>(a.size());
    for (int i = 0; i < length; ++i) {
        if (a.at(i)) {
            if (start_index == -1) {
                start_index = i;
            }
            if (stop_index == -1) {
                stop_index = i;
            } else {
                ++stop_index;
            }
        } else {
            if (stop_index != -1) {
                result.emplace_back(make_pair(start_index, stop_index));
                start_index = -1;
                stop_index = -1;
            }
        }
    }
    if (stop_index != -1) {
        result.emplace_back(make_pair(start_index, stop_index));
    }
    return result;
}

int main() {

    int n;
    IO::read(n);
    set<ll> s;
    vector<pair<ll, ll> > A;
    ll l, r;
    for (int i = 0; i < n; ++i) {
        IO::read(l, r);
        if (l != r) {
            A.emplace_back(make_pair(l, r));
            s.insert(l);
            s.insert(r);
        }
    }
    unordered_map<ll, int, custom_hash> unmap;
    vector<ll> unmap_rev;
    int id = 0;
    for (const auto &i : s) {
        unmap[i] = id;
        unmap_rev.emplace_back(id) = i;
        ++id;
    }
    vector<pair<int, int> > A_after_discretization(A.size());
    for (size_t i = 0; i != A.size(); ++i) {
        A_after_discretization.at(i).first = unmap[A.at(i).first];
        A_after_discretization.at(i).second = unmap[A.at(i).second];
    }
    vector<bool> temp_vec(id + 5, false);
    for (const auto &i : A_after_discretization) {
        int length = i.second - i.first;
        int start = i.second;
        while (length > 0) {
            temp_vec.at(start) = true;
            --length;
            --start;
        }
    }
    // merge
    auto p = Merge(temp_vec);
    // restore and calculate
    ll sum = 0;
    for (const auto &[k, v] : p) {
        int right = v;
        int left = k - 1;
        sum += abs(unmap_rev[right] - unmap_rev[left]);
    }
    IO::writeln(sum);
    return 0;
}
