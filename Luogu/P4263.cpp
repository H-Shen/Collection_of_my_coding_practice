#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

int main() {

    int t, n, question_id, max_votes;
    bool have_ans, first_item;
    IO::read(t);
    while (t--) {
        have_ans = false;
        unordered_map<int, int, custom_hash> freq;
        IO::read(n);
        while (n--) {
            IO::read(question_id);
            ++freq[question_id];
        }
        unordered_set<int, custom_hash> uniq_votes;
        for (const auto &[k, v] : freq) {
            uniq_votes.insert(v);
            if (uniq_votes.size() > 1) {
                have_ans = true;
                break;
            }
        }
        if (!have_ans) {
            IO::writeln(-1);
        } else {
            max_votes = -1;
            for (const auto &[k, v] : freq) {
                max_votes = max(max_votes, v);
            }
            vector<int> question_lists;
            for (const auto &[k, v] : freq) {
                if (v == max_votes) {
                    question_lists.emplace_back(k);
                }
            }
            sort(question_lists.begin(), question_lists.end());
            IO::writeln(question_lists.size());
            first_item = true;
            for (const auto &i : question_lists) {
                if (first_item) {
                    first_item = false;
                } else {
                    putchar_unlocked(' ');
                }
                IO::write(i);
            }
            putchar_unlocked('\n');
        }
    }

    return 0;
}