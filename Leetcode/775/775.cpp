#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

template<typename T>
using RBTree = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using ll = long long;

class Solution {
public:
    // O(n) : global inversion = local inversion + non-local inversion, thus if any non-local inversion exists, return false
    bool isIdealPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) {
            return true;
        }
        vector<int> minFromRight(n);
        minFromRight[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            minFromRight[i] = min(minFromRight[i+1], nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            // check if any non-local inversion exists
            if (i+2 < n && nums[i] > minFromRight[i+2]) {
                return false;
            }
        }
        return true;
    }
    // O(nlogn) TLE
    bool isIdealPermutation2(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) {
            return true;
        }
        RBTree<int> rbt;
        for (int i = 1; i < n; ++i) {
            rbt.insert(nums[i]);
        }
        ll globalInv = 0;
        for (int i = 0; i < n-1; ++i) {
            globalInv += (ll)rbt.order_of_key(nums[i]);
            rbt.erase(nums[i+1]);
        }
        
        ll localInv = 0;
        for (int i = 0; i < n-1; ++i) {
            if (nums[i] > nums[i+1]) {
                ++localInv;
            }
        }
        return globalInv == localInv;
    }
};