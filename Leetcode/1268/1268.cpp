#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using Trie =
        trie<string,
        null_type,
        trie_string_access_traits<>,
                pat_trie_tag,
                trie_prefix_search_node_update>;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        for (auto&i : products) t.insert(i);
        vector<vector<string>> result(searchWord.size());
        string prefix;
        int index = 0;
        for (auto&i : searchWord) {
            prefix.push_back(i);
            vector<string> temp;
            auto range = t.prefix_range(prefix);
            int counter = 0;
            for (auto it = range.first; counter < 3 && it != range.second; ++it, ++counter) {
                temp.emplace_back(*it);
            }
            result[index++] = temp;
        }
        return result;
    }
};