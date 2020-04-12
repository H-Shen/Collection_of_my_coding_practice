#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using Trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;

constexpr int MAXN = 105;
char s[MAXN];
Trie T;
unordered_map<string, int> stats;

int main() {
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        T.insert(s);
        ++stats[s];
    }
    scanf("%s", s);
    auto p = T.prefix_range(s);
    auto iter = p.first;
    if (iter != T.end()) {
        for (; iter != p.second; ++iter) {
            for (int i = 0; i < stats[*iter]; ++i) {
                printf("%s\n", iter->c_str());
            }
        }
    }

    return 0;
}