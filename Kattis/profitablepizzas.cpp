// https://open.kattis.com/problems/profitablepizzas
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 2000005;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        puts("");
    }
}

vector<vector<int> > A(MAXN);
int t_max = -1;

struct Node {
    int t, d;
    bool operator < (const Node &obj) const {
        if (d == obj.d) {
            return t < obj.t;
        }
        return d < obj.d;
    }
    explicit Node(int t, int d) : t(t), d(d) {}
};

int main() {

    int n, t, d;
    IO::read(n);
    while (n--) {
        IO::read(t, d);
        A.at(t).emplace_back(d);
        t_max = max(t_max, t);
    }
    int cost = 0;
    if (t_max > 1) {
        priority_queue<Node> pq;
        for (int current_deadline = t_max; current_deadline >= 1; --current_deadline) {
            for (const int &value : A.at(current_deadline)) {
                pq.push(Node(current_deadline, value));
            }
            if (!pq.empty()) {
                cost += pq.top().d;
                pq.pop();
            }
        }
    }
    else {
        cost = *max_element(A.at(t_max).begin(), A.at(t_max).end());
    }
    IO::writeln(cost);
    return 0;
}
