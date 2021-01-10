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
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        auto ptr0 = head;
        while (ptr0) {
            ++length;
            ptr0 = ptr0->next;
        }
        ptr0 = head;
        int counter = 1;
        while (counter < k) {
            ptr0 = ptr0->next;
            ++counter;
        }
        auto ptr1 = head;
        counter = 1;
        while (counter < length + 1 - k) {
            ptr1 = ptr1->next;
            ++counter;
        }
        int val = ptr0->val;
        ptr0->val = ptr1->val;
        ptr1->val = val;
        return head;
    }
};