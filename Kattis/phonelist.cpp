// https://open.kattis.com/problems/phonelist

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int MAXN = 15;
char str[MAXN];

typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> prefix_trie;

int main() {

    int kase;
    scanf("%d", &kase);

    while (kase--) {

        prefix_trie Trie;
        vector<string> temp;
        bool haveAns = true;
        int n;
        scanf("%d", &n);
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
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
