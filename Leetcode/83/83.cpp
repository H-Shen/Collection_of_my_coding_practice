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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !(head->next)) {
            return head;
        }
        auto currentPtr = head;
        auto lastPtr = head;
        while (true) {
            if (!(currentPtr->next)) {
                if (lastPtr->val == currentPtr->val) {
                    lastPtr->next = nullptr;
                } else {
                    lastPtr->next = currentPtr;
                }
                break;
            } else if (lastPtr->val != currentPtr->val) {
                lastPtr->next = currentPtr;
                lastPtr = currentPtr;
            }
            currentPtr = currentPtr->next;
        }
        return head;
    }
};