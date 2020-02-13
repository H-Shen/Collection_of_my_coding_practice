// https://open.kattis.com/problems/cokolada
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


int main() {

    while (powerOfTwo.back() <= 10000000) {
        powerOfTwo.emplace_back(powerOfTwo.back() * 2);
    }
    ll k;
    scanf("%lld", &k);
    ll smallest_to_buy = *lower_bound(powerOfTwo.begin(), powerOfTwo.end(), k);

    // k | (smallest_to_buy * 2^n)
    ll Lcm = (ll)std::lcm(smallest_to_buy, k);
    int counter = 0;
    while (true) {
        if (Lcm == k) {
            break;
        }
        Lcm /= 2;
        ++counter;
    }
    printf("%lld %d\n", smallest_to_buy, counter);

    return 0;
}
