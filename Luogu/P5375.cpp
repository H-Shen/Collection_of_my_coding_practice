#include <bits/extc++.h>

using namespace std;

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

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<> > minHeap;
queue<int> q;
stack<int> s;

bool isMaxHeap = true;
bool isMinHeap = true;
bool isQueue = true;
bool isStack = true;

int main() {

    int n, opt, val;
    IO::read(n);
    while (n--) {
        IO::read(opt);
        if (opt == 1) {
            IO::read(val);
            if (isMaxHeap) {
                maxHeap.push(val);
            }
            if (isMinHeap) {
                minHeap.push(val);
            }
            if (isStack) {
                s.push(val);
            }
            if (isQueue) {
                q.push(val);
            }
        } else {
            IO::read(val);
            if (isMaxHeap) {
                if (maxHeap.empty() || maxHeap.top() != val) {
                    isMaxHeap = false;
                } else {
                    maxHeap.pop();
                }
            }
            if (isMinHeap) {
                if (minHeap.empty() || minHeap.top() != val) {
                    isMinHeap = false;
                } else {
                    minHeap.pop();
                }
            }
            if (isQueue) {
                if (q.empty() || q.front() != val) {
                    isQueue = false;
                } else {
                    q.pop();
                }
            }
            if (isStack) {
                if (s.empty() || s.top() != val) {
                    isStack = false;
                } else {
                    s.pop();
                }
            }
        }
    }
    printf(isQueue ? "Yes\n" : "No\n");
    printf(isStack ? "Yes\n" : "No\n");
    printf(isMaxHeap ? "Yes\n" : "No\n");
    printf(isMinHeap ? "Yes\n" : "No\n");

    return 0;
}