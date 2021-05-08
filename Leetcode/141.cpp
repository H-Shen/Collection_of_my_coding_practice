/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        // Floyd check
        auto slow(head);
        auto fast(head);
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        } while (slow != fast && fast);
        return fast;
    }
};