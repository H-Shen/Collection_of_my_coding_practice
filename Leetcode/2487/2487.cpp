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
    ListNode* removeNodes(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }
        vector<ListNode*> values;
        auto node = head;
        while (node) {
            values.emplace_back(node);
            node = node->next;
        }
        int n = (int)values.size();
        vector<int> maxFromRight(n);
        maxFromRight[n-1] = values[n-1]->val;
        for (int i = n-2; i >= 0; --i) {
            maxFromRight[i] = max(maxFromRight[i+1], values[i]->val);
        }
        vector<ListNode*> ans;
        for (int i = 0; i < n; ++i) {
            if (i == n-1) {
                ans.emplace_back(values[i]);
                continue;
            }
            if (values[i]->val >= maxFromRight[i+1]) {
                ans.emplace_back(values[i]);
            }
        }
        int m = (int)ans.size();
        for (int i = 0; i < m; ++i) {
            if (i == m-1) {
                ans[i]->next = nullptr;
            } else {
                ans[i]->next = ans[i+1];
            }
        }
        return ans[0];
    }
};