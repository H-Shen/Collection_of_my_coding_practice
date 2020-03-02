// https://open.kattis.com/problems/phonelist
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int MAXN = 15;
char str[MAXN];

using prefix_trie = trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>;

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

    int kase;
    read(kase);

    while (kase--) {

        prefix_trie Trie;
        vector<string> temp;
        bool haveAns = true;
        int n;
        read(n);
        string s;
        while (n--) {
            scanf("%s", str);
            s = str;
            Trie.insert(s);
            temp.emplace_back(s);
        }
        sort(temp.begin(), temp.end());
        for (const string &i : temp) {
            auto range = Trie.prefix_range(i);
            int counter = 0;
            for (auto it = range.first; it != range.second; ++it) {
                ++counter;
                if (counter > 1) {
                    haveAns = false;
                    break;
                }
            }
            if (!haveAns) {
                break;
            }
        }

        if (!haveAns) {
            putchar('N');
            putchar('O');
            puts("");
        } else {
            putchar('Y');
            putchar('E');
            putchar('S');
            puts("");
        }
    }
    return 0;
}
