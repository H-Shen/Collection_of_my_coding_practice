#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 100005;

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

// Define a node for a doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    explicit Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};
vector<Node *> A(MAXN);
bitset<MAXN> filter;

int main() {

    for (int i = 0; i < MAXN; ++i) {
        A.at(i) = nullptr;
    }
    A.at(1) = new Node(1);
    int n, k, p;
    IO::read(n);
    for (int i = 2; i <= n; ++i) {
        A.at(i) = new Node(i);
        IO::read(k, p);
        if (A.at(k) == nullptr) {
            A.at(k) = new Node(k);
        }
        if (p == 0) {
            A.at(i)->next = A.at(k);
            if (A.at(k)->prev == nullptr) {
                A.at(k)->prev = A.at(i);
            } else {
                auto temp_node_id = A.at(k)->prev->data;
                A.at(k)->prev = A.at(i);
                A.at(temp_node_id)->next = A.at(i);
                A.at(i)->prev = A.at(temp_node_id);
            }
        } else {
            A.at(i)->prev = A.at(k);
            if (A.at(k)->next == nullptr) {
                A.at(k)->next = A.at(i);
            } else {
                auto temp_node_id = A.at(k)->next->data;
                A.at(k)->next = A.at(i);
                A.at(temp_node_id)->prev = A.at(i);
                A.at(i)->next = A.at(temp_node_id);
            }
        }
    }
    int m, val;
    IO::read(m);
    while (m--) {
        IO::read(val);
        filter[val] = true;
    }
    int head_id = 1;
    for (int i = 1; i <= n; ++i) {
        if (A.at(i)) {
            if (A.at(i)->prev == nullptr) {
                head_id = i;
                break;
            }
        }
    }
    // traversal
    bool first_item = true;
    while (true) {
        // output
        if (!filter[A.at(head_id)->data]) {
            if (first_item) {
                first_item = false;
            } else {
                putchar_unlocked(' ');
            }
            IO::write(A.at(head_id)->data);
        }
        if (A.at(head_id)->next == nullptr) {
            break;
        }
        head_id = A.at(head_id)->next->data;
    }
    if (!first_item) {
        putchar_unlocked('\n');
    }

    return 0;
}