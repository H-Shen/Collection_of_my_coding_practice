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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;
        vector<ListNode*> vec;
        auto node = head;
        vec.emplace_back(node);
        while (node->next) {
            vec.emplace_back(node);
            vec.emplace_back(new ListNode(gcd(node->val, node->next->val)));
            vec.emplace_back(node->next);
            node = node->next;
        }
        int n = (int)vec.size();
        for (int i = 0; i < n-1; ++i) {
            vec[i]->next = vec[i+1];
        }
        vec[n-1]->next = nullptr;
        return vec[0];
    }
};