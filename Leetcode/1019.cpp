/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        auto node(head);
        while (node) {
            v.emplace_back(node->val);
            node = node->next;
        }
        int n = (int)v.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= v[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = s.top();
            }
            s.push(v[i]);
        }
        return ans;
    }
};