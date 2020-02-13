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

constexpr int MAXN = 10;

int main() {

    vector<int> A;
    int val;
    for (int i = 0; i < MAXN; ++i) {
        read<int>(val);
        A.emplace_back(val);
    }
    int height;
    read<int>(height);
    height += 30;

    int counter = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (height >= A.at(i)) {
            ++counter;
        }
    }
    writeln<int>(counter);

    return 0;
}
