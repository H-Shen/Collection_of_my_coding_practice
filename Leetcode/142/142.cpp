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
    ListNode *detectCycle(ListNode *head) {
        // Floyd cycle detection
        if (!head || !head->next || !head->next->next) return nullptr;
        auto slowPtr = head->next;
        auto fastPtr = slowPtr->next;
        while (slowPtr != fastPtr) {
            slowPtr = slowPtr->next;
            if (!slowPtr) return nullptr;
            fastPtr = fastPtr->next;
            if (!fastPtr) return nullptr;
            fastPtr = fastPtr->next;;
            if (!fastPtr) return nullptr;
        }
        slowPtr = head;
        while (slowPtr != fastPtr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr;
    }
};