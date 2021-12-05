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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        auto p = head;
        while (p) {
            ++n;
            p = p->next;
        }
        if (n == 1) {
            return nullptr;
        }
        auto node = new ListNode();
        node->next = head;
        int counter = n >> 1;
        while (counter > 0) {
            node = node->next;
            --counter;
        }
        node->next = node->next->next;
        return head;
    }
};