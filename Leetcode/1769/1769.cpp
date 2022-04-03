class Solution {
public:
    // Prefix + Binarysearch O(nlogn)
    vector<int> minOperations(string boxes) {
        int n = (int)boxes.size();
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '1') {
                vec.emplace_back(i);
            }
        }
        vector<int> ans(n);
        if (vec.empty()) {
            return ans;
        }
        int m = (int)vec.size();
        vector<int> preLeft(m);
        preLeft[0] = vec[0];
        for (int i = 1; i < m; ++i) {
            preLeft[i] = preLeft[i-1] + vec[i];
        }
        vector<int> preRight(m);
        preRight[m-1] = vec[m-1];
        for (int i = m-2; i >= 0; --i) {
            preRight[i] = preRight[i+1] + vec[i];
        }
        int left_items, right_items;
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '0') {
                if (i < vec[0]) {
                    ans[i] = preRight[0] - i*m;
                }
                else if (i > vec[m-1]) {
                    ans[i] = i*m - preLeft[m-1];
                }
                else {
                    auto iter = --lower_bound(vec.begin(),vec.end(),i);
                    left_items = (int)(iter - vec.begin()) + 1;
                    right_items = m - left_items;
                    ans[i] = i*left_items - preLeft[left_items-1] + preRight[left_items] - i*right_items;
                }
            }
            else {
                auto iter = lower_bound(vec.begin(),vec.end(),i);
                left_items = (int)(iter - vec.begin());
                right_items = m - (left_items + 1);
                if (left_items > 0) {
                    ans[i] += i*left_items - preLeft[left_items-1];
                }
                if (right_items > 0) {
                    ans[i] += preRight[left_items+1] - i*right_items;
                }
                
            }
        }
        return ans;
    }
};