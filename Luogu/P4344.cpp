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
        int left;
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

    int get_max_freq_of_0s(int l, int r) {
        auto iter_right = split(r + 1);
        auto iter_left = split(l);
        int result = 0;
        int zero_continuous_seq_length = 0;
        for (; iter_left != iter_right; ++iter_left) {
            if (iter_left->weight == 0) {
                zero_continuous_seq_length += (iter_left->right -
                                               iter_left->left + 1);
            } else {
                result = max(result, zero_continuous_seq_length);
                zero_continuous_seq_length = 0;
            }
        }
        if (zero_continuous_seq_length > 0) {
            result = max(result, zero_continuous_seq_length);
        }
        return result;
    }

    int count_and_reset(int l, int r) {
        // Calculate the number of 1s in [l, r]
        auto iter_right = split(r + 1);
        auto iter_left = split(l);
        int count_of_ones = 0;
        for (; iter_left != iter_right; ++iter_left) {
            // Check if this interval contains any 1s
            if (iter_left->weight > 0) {
                count_of_ones += (iter_left->right - iter_left->left + 1);
            }
        }
        // re-assign the values from [l, r] to 0
        ChthollyTree::assign(l, r, 0);
        return count_of_ones;
    }

    void fix(int l0, int r0, int l1, int r1) {
        int count_of_ones = count_and_reset(l0, r0);
        // Case 1: no symbols of 1 is found on [l0, r0]
        if (count_of_ones == 0) {
            return;
        }
        auto iter_right = split(r1 + 1);
        auto iter_left = split(l1);
        // Case 2: the symbols of 1 in [l0, r0] <= the length of [l1, r1],
        // we re-assign all intervals in [l1, r1] one by one with the 1 as their weight
        // until all symbols of 1 are allocated
        int cost;
        if (r1 - l1 + 1 > count_of_ones) {
            for (; iter_left != iter_right; ++iter_left) {
                // Check if the current interval has the weight 0
                if (iter_left->weight == 0) {
                    cost = iter_left->right - iter_left->left + 1;
                    // Subcase 1: we still have enough 1s for this interval
                    if (cost <= count_of_ones) {
                        iter_left->weight = 1;
                        count_of_ones -= cost;
                    }
                        // Subcase 2: no enough 1s to fill this interval
                    else {
                        count_of_ones -= cost;
                        assign(iter_left->left,
                               iter_left->right + count_of_ones, 1);
                        break;
                    }
                }
            }
        }
            // Case 3: the symbols of 1 in [l0, r0] > the length of [l1, r1]
            // we re-assign all weights in [l1, r1] to 1
        else {
            assign(l1, r1, 1);
        }
    }
}

int n, m, op, l1, r1, l, r;

int main() {

    IO::read(n, m);
    // init
    ChthollyTree::A.insert(ChthollyTree::Node(1, n, 1));
    while (m--) {
        IO::read(op);
        switch (op) {
            case 0:
                IO::read(l, r);
                ChthollyTree::assign(l, r, 0);
                break;
            case 1:
                IO::read(l, r, l1, r1);
                ChthollyTree::fix(l, r, l1, r1);
                break;
            case 2:
                IO::read(l, r);
                IO::writeln(ChthollyTree::get_max_freq_of_0s(l, r));
                break;
        }
    }

    return 0;
}
