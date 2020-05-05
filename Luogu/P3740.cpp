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

namespace ChthollyTree {
    constexpr ll NOT_FOUND = numeric_limits<ll>::min();

    // Definition of a node in the tree
    struct Node {
        int left;   // each Node in the set s has unique left values
        int right;
        mutable ll weight;

        Node() = delete;

        explicit Node(int left, int right = 0, ll weight = 0) : left(left),
                                                                right(right),
                                                                weight(weight) {}

        bool operator<(const Node &other) const {
            return left < other.left;
        }
    };

    // Define the tree
    set<Node> A;
    // Operations associated the tree

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
        ll w = iter->weight;
        A.erase(iter);
        A.insert(Node(l, position - 1, w));
        auto temp = A.insert(Node(position, r, w));
        return temp.first;
    }

    // Assign: assign the weight of all nodes that cover the interal [l, r] to assigned value
    void assign(int left, int right, ll new_weight) {
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        A.erase(iter_left, iter_right);
        A.insert(Node(left, right, new_weight));
    }

    // Update: update the weight of all nodes that cover the interal [l, r]
    void update(int left, int right, ll update_weight) {
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        for (; iter_left != iter_right; ++iter_left) {
            iter_left->weight += update_weight;
        }
    }

    // Sum: Range-sum the weight of all nodes that cover the interal [l, r] and mod m
    ll sum(int left, int right, ll mod) {
        ll result = 0;
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        ll freq;
        for (; iter_left != iter_right; ++iter_left) {
            freq = iter_left->right - iter_left->left + 1;
            result = (result + freq * iter_left->weight) % mod;
        }
        return result;
    }

    // Obtain the nth number in the interval [l, r] in non-decreasing order.
    // If non_decreasing is false, return the kth number in non-increasing order.
    // return NOT_FOUND if such nth number does not exist
    ll nth(int left, int right, int n, bool non_decreasing = true) {
        if (!non_decreasing) {
            n = right - left + 2 - n;
        }
        vector<pair<ll, int> > temp_vec;
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        int length;
        for (; iter_left != iter_right; ++iter_left) {
            length = iter_left->right - iter_left->left + 1;
            temp_vec.emplace_back(make_pair(iter_left->weight, length));
        }
        sort(temp_vec.begin(), temp_vec.end(),
             [](const pair<ll, int> &lhs, const pair<ll, int> &rhs) {
                 if (lhs.first == rhs.first) {
                     return (lhs.second < rhs.second);
                 }
                 return (lhs.first < rhs.first);
             });
        for (const auto &i : temp_vec) {
            n -= i.second;
            if (n <= 0) {
                return i.first;
            }
        }
        return NOT_FOUND;
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

gp_hash_table<int, null_type, custom_hash> uniq_levels;

int n, m, a, b;

int main() {

    IO::read(n, m);
    // init
    ChthollyTree::A.insert(ChthollyTree::Node(1, n, 0));
    // process
    int current_level = 1;
    while (m--) {
        IO::read(a, b);
        ChthollyTree::assign(a, b, current_level);
        ++current_level;
    }
    // stats
    auto iter_right = ChthollyTree::split(n + 1);
    auto iter_left = ChthollyTree::split(1);
    for (; iter_left != iter_right; ++iter_left) {
        if (iter_left->weight > 0 &&
            uniq_levels.find(iter_left->weight) == uniq_levels.end()) {
            uniq_levels.insert(iter_left->weight);
        }
    }
    IO::writeln(uniq_levels.size());
    return 0;
}