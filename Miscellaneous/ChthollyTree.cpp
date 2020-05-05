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

ll mod_pow(ll a, ll p, ll m) {
    if (m == 1) return 0;
    ll r;
    for (r = 1, a %= m; p; a = (a * a) % m, p >>= 1) if (p % 2) r = (r * a) % m;
    return r % m;
}

namespace ChthollyTree {

    constexpr ll NOT_FOUND = numeric_limits<ll>::min();

    // Definition of a node in the tree
    struct Node {
        int left;   // each Node in the set A has unique 'left'
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

    // Sum: Range-sum the weight of all nodes that cover the interal [l, r]
    ll sum(int left, int right) {
        ll result = 0;
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        ll freq;
        for (; iter_left != iter_right; ++iter_left) {
            freq = iter_left->right - iter_left->left + 1;
            result += freq * iter_left->weight;
        }
        return result;
    }

    ll pow_sum(int left, int right, ll pow, ll mod) {
        ll result = 0;
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        ll freq;
        for (; iter_left != iter_right; ++iter_left) {
            freq = iter_left->right - iter_left->left + 1;
            result = (result + freq * mod_pow(iter_left->weight, pow, mod)) %
                     mod;
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

    // Check if the interval [left, right] has unique weights
    bool unique_check(int left, int right) {
        auto iter_right = split(right + 1);
        auto iter_left = split(left);
        unordered_set<ll> temp_unset;
        for (; iter_left != iter_right; ++iter_left) {
            temp_unset.insert(iter_left->weight);
            if (temp_unset.size() > 1) {
                return false;
            }
        }
        return true;
    }
}

ll n, m, seed, v_max, l, r, x, op, y;

ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

// An example of ChthollyTree:
// given an array L of n elements, a Chtholly Tree supports 4 operations:
// 1 l r x:
// For each $i$ such that $l \leq i \leq r$, update L[i] by $L[i] = L[i] + x$
// 2 l r x:
// For each $i$ such that $l \leq i \leq r$, assign $L[i] = x$
// 3 l r x:
// Print the kth-smallest number in from L[l] to L[r], duplicated values are also considered
// 4 l r x y
// Print $(\sum\limits_{i=l}^{r} L_{i}^{x}) \mod y$
//
// If the data sample and the operations are strictly randomly generated,
// the time complexity is $\mathcal{O}(n \log( \log(n)))$ when using std::set
//

int main() {

    IO::read(n, m, seed, v_max);
    // init
    for (int i = 1; i <= n; ++i) {
        ChthollyTree::A.insert(ChthollyTree::Node(i, i, (rnd() % v_max) + 1));
    }
    for (int i = 1; i <= m; ++i) {
        op = (rnd() % 4) + 1;
        l = (rnd() % n) + 1;
        r = (rnd() % n) + 1;
        if (l > r) {
            swap(l, r);
        }
        if (op == 3) {
            x = (rnd() % (r - l + 1)) + 1;
        } else {
            x = (rnd() % v_max) + 1;
        }
        if (op == 4) {
            y = (rnd() % v_max) + 1;
        }
        // process
        switch (op) {
            case 1:
                ChthollyTree::update(l, r, x);
                break;
            case 2:
                ChthollyTree::assign(l, r, x);
                break;
            case 3:
                IO::writeln(ChthollyTree::nth(l, r, x));
                break;
            case 4:
                IO::writeln(ChthollyTree::pow_sum(l, r, x, y));
                break;
        }
    }

    return 0;
}
