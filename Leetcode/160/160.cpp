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
    int getLength(ListNode* head) {
        auto ptr = head;
        int length = 0;
        while (ptr) {
            ptr = ptr->next;
            ++length;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        auto ptrA = headA;
        auto ptrB = headB;
        while (lengthA < lengthB) {
            ptrB = ptrB->next;
            --lengthB;
        }
        while (lengthA > lengthB) {
            ptrA = ptrA->next;
            --lengthA;
        }
        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
};