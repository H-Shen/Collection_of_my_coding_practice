// https://open.kattis.com/problems/fastfood
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using RBTree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Trie = trie<T, null_type, less<>, pat_trie_tag, trie_prefix_search_node_update>;

// Usage: int a, b, c; read<int>(a, b, c);
template <typename T>
inline
void read(T& t) {
    int n = 0; int c = getchar(); t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (n) t = -t;
}
template <typename T, typename... Args>
inline
void read(T& t, Args&... args) {
    read(t); read(args...);
}
// Usage: int a = 1231; writeln(a);
template <typename T>
inline void write(T x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x) {
    write(x);
    puts("");
}

struct Prize {
    ll val;
    vector<ll> stickers_needed;
};

int main() {

    int t, n, m, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        vector<Prize> A(n);
        for (int i = 0; i < n; ++i) {
            Prize prize{};
            scanf("%d", &k);
            prize.stickers_needed.resize(k);
            for (int j = 0; j < k; ++j) {
                scanf("%lld", &prize.stickers_needed.at(j));
            }
            scanf("%lld", &prize.val);
            A.at(i) = prize;
        }
        vector<ll> stickers(m + 1);
        stickers.emplace_back(0);
        for (int i = 1; i < m + 1; ++i) {
            scanf("%lld", &stickers.at(i));
        }
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            ll min_val = numeric_limits<ll>::max();
            for (const auto &j : A.at(i).stickers_needed) {
                min_val = min(min_val, stickers.at(j));
            }
            sum += min_val * A.at(i).val;
        }
        printf("%lld\n", sum);
    }

    return 0;
}
