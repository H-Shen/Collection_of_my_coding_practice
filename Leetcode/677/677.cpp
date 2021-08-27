#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using Trie =
        trie<string,
        int,
        trie_string_access_traits<>,
                pat_trie_tag,
                trie_prefix_search_node_update>;

class MapSum {
private:
    Trie t;
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        t[key] = val;
    }

    int sum(string prefix) {
        auto range = t.prefix_range(prefix);
        int result = 0;
        for (auto it = range.first; it != range.second; ++it) {
            result += it->second;
        }
        return result;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */