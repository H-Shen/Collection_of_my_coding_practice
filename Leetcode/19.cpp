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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto ptr0 = head;
        auto ptr1 = head;
        int nCopy(n);
        while (nCopy > 0) {
            ptr1 = ptr1->next;
            --nCopy;
        }
        if (!ptr1) {
            if (!ptr0->next) {
                return nullptr;
            }
            return head->next;
        }
        while (ptr1->next) {
            ptr0 = ptr0->next;
            ptr1 = ptr1->next;
        }
        ptr0->next = ptr0->next->next;
        return head;
    }
};