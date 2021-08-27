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
    ListNode* plusOne(ListNode* head) {
        vector<int> v;
        auto node(head);
        while (node) {
            v.emplace_back(node->val);
            node = node->next;
        }
        reverse(v.begin(), v.end());
        int n = (int)v.size();
        vector<int> v_adder(n);
        v_adder[0] = 1;
        vector<int> v_sum(n + 1);
        for (int i = 0; i < n; ++i) {
            v_sum[i] += v_adder[i] + v[i];  //
            if (v_sum[i] >= 10) {
                v_sum[i] -= 10;
                ++v_sum[i+1];
            }
        }
        if (v_sum.back() == 0) {
            v_sum.pop_back();
        }
        reverse(v_sum.begin(), v_sum.end());
        if (v.size() == v_sum.size()) {
            node = head;
            auto iter = v_sum.begin();
            while (node) {
                node->val = *iter;
                ++iter;
                node = node->next;
            }
        } else {
            node = head;
            while (node->next) {
                node = node->next;
            }
            node->next = new ListNode();
            node = head;
            auto iter = v_sum.begin();
            while (node) {
                node->val = *iter;
                ++iter;
                node = node->next;
            }
        }
        return head;
    }
};