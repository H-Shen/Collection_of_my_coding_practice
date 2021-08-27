class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        int n = (int)order.size();
        int maxDepth = 1;
        map<int,int> node2depth;
        node2depth[order[0]] = 1;
        for (int i = 1; i < n; ++i) {
            int key = order[i];
            auto iter0 = node2depth.lower_bound(key);
            int leftDepth = 0;
            int rightDepth = 0;
            if (iter0 != node2depth.end()) {
                leftDepth = iter0->second;
            }
            if (iter0 != node2depth.begin()) {
                --iter0;
                rightDepth = iter0->second;
            }
            int depth = max(leftDepth,rightDepth)+1;
            node2depth[key] = depth;
            maxDepth = max(maxDepth, depth);
        }
        return maxDepth;
    }
};