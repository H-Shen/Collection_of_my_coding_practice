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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }
        int n = 0;
        auto node(head);
        while (node) {
            ++n;
            node = node->next;
        }
        k %= n;
        auto dummy = new ListNode();
        dummy->next = head;
        node = dummy;
        for (int i = 0; i < n - k; ++i) {
            node = node->next;
        }
        auto node2(head);
        while (node2->next) {
            node2 = node2->next;
        }
        node2->next = dummy->next;
        dummy->next = node->next;
        node->next = nullptr;
        return dummy->next;
    }
};