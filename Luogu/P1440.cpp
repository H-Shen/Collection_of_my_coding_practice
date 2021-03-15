#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
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

struct MonoQueue {
    deque<int> dq;

    void push(int val) {
        while (!dq.empty() && dq.back() > val) {
            dq.pop_back();
        }
        dq.push_back(val);
    }
    int min() {
        return dq.front();
    }
    void pop_front_if(int val) {
        if (!dq.empty() && dq.front() == val) {
            dq.pop_front();
        }
    }
};

int main() {

    int n, k;
    IO::read(n, k);
    vector<int> nums(n);
    for (auto &i : nums) IO::read(i);

    MonoQueue window;
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (i < k - 1) {
            window.push(nums.at(i));
        } else {
            window.push(nums.at(i));
            result.emplace_back(window.min());
            window.pop_front_if(nums[i - (k - 1)]);
        }
    }
    IO::writeln(0);
    int minVal;
    for (int i = 1; i < k; ++i) {
        if (i == 1) {
            IO::writeln(nums.at(i - 1));
            minVal = nums.at(i - 1);
        } else {
            minVal = min(minVal, nums.at(i - 1));
            IO::writeln(minVal);
        }
    }
    int length = (int)result.size();
    for (int i = 0; i < length - 1; ++i) {
        IO::writeln(result.at(i));
    }

    return 0;
}