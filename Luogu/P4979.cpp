#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    inline void read_letters(char &t) {
        t = getchar_unlocked();
        while (!isalpha(t)) {
            t = getchar_unlocked();
        }
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

namespace ChthollyTree {

    // Definition of a node in the tree
    struct Node {
        int left;
        int right;
        mutable char weight;

        Node() = delete;

        explicit Node(int left, int right = 0, char weight = 0) : left(left),
                                                                  right(right),
                                                                  weight(weight) {}

        bool operator<(const Node &other) const {
            return left < other.left;
        }
    };

    // Define the tree
    set<Node> A;
    // Operations associated with the tree

    // Split: split the interval [l, r] to [l, position-1] and [position, r]
    // Precondition: the tree is not empty
    // and returns the iterator points to the second interval
    set<Node>::iterator split(int position) {
        // Check the node that its left is the first one such that left >= position
        auto iter = A.lower_bound(Node(position));
        // If the iterator does not point to the end of the set and its left == position,
        // just return it
        if (iter != A.end() && iter->left == position) {
            return iter;
        }
        --iter;
        int l = iter->left;
        int r = iter->right;
        char w = iter->weight;
        A.erase(iter);
        A.insert(Node(l, position - 1, w));
        auto temp = A.insert(Node(position, r, w));
        return temp.first;
    }

    // Assign: assign the weight of all nodes that cover the interal [l, r] to assigned value
    void assign(int left, int right, char new_weight) {
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        A.erase(iter_left, iter_right);
        A.insert(Node(left, right, new_weight));
    }

    bool unique_check(int left, int right) {
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        unordered_set<char> temp_unset;
        for (; iter_left != iter_right; ++iter_left) {
            temp_unset.insert(iter_left->weight);
            if (temp_unset.size() > 1) {
                return false;
            }
        }
        return true;
    }
}

constexpr int MAXN = 500005;
char s[MAXN];
int n, m, x, y;
char op, replacement;

int main() {

    IO::read(n);
    scanf("%s", s);
    
    // init
    int start_index{};
    int end_index{};
    char ch = 0;
    for (int i = 0;; ++i) {
        if (s[i] != 'A' && s[i] != 'B' && s[i] != 'C') {
            break;
        }
        if (ch == 0) {
            ch = s[i];
            start_index = 1;
            end_index = 1;
        } else if (ch == s[i]) {
            ++end_index;
        } else {
            ChthollyTree::A.insert(
                    ChthollyTree::Node(start_index, end_index, ch));
            ch = s[i];
            start_index = i + 1;
            end_index = start_index;
        }
    }
    ChthollyTree::A.insert(ChthollyTree::Node(start_index, end_index, ch));

    // process
    IO::read(m);
    while (m--) {
        IO::read_letters(op);
        if (op == 'A') {
            IO::read(x, y);
            IO::read_letters(replacement);
            ChthollyTree::assign(x, y, replacement);
        } else {
            IO::read(x, y);
            if (x == 1 || y == n) {
                if (ChthollyTree::unique_check(x, y)) {
                    fputs_unlocked("Yes\n", stdout);
                } else {
                    fputs_unlocked("No\n", stdout);
                }
            } else {
                ChthollyTree::split(x - 1);
                ChthollyTree::split(y + 1);
                if (!ChthollyTree::unique_check(x, y) ||
                    ChthollyTree::A.lower_bound(
                            ChthollyTree::Node(x - 1, 0, 0))->weight ==
                    ChthollyTree::A.lower_bound(
                            ChthollyTree::Node(y + 1, 0, 0))->weight) {
                    fputs_unlocked("No\n", stdout);
                } else {
                    fputs_unlocked("Yes\n", stdout);
                }
            }
        }
    }

    return 0;
}
