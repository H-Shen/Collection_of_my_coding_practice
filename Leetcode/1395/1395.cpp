#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using RBTree = __gnu_pbds::tree<int,__gnu_pbds::null_type,less<>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

class Solution {
public:
    // O(nlogn)
    int numTeams(vector<int>& rating) {
        int n = (int)rating.size();
        if (n < 3) {
            return 0;
        }
        int ans = 0;
        RBTree left, right;
        left.insert(rating[0]);
        for (int i = 2; i < n; ++i) {
            right.insert(rating[i]);
        }
        int l, r;
        for (int j = 1; j <= n-2; ++j) {
            // rating[i] < rating[j] < rating[k]
            l = left.order_of_key(rating[j]);
            r = (int)right.size() - right.order_of_key(rating[j]);
            ans += l*r;
            // rating[i] > rating[j] > rating[k]
            l = (int)left.size() - left.order_of_key(rating[j]);
            r = right.order_of_key(rating[j]);
            ans += l*r;
            left.insert(rating[j]);
            right.erase(rating[j+1]);
        }
        return ans;
    }
};