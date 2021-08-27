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
    int getLength(ListNode *l) {
        int length = 0;
        auto ptr = l;
        while (ptr) {
            ptr = ptr->next;
            ++length;
        }
        return length;
    }
    ListNode* paddingZeroes(ListNode* l, int newLength, int currentLength) {
        ListNode* tail = l;
        while (tail->next) {
            tail = tail->next;
        }
        while (currentLength != newLength) {
            tail->next = new ListNode();
            tail = tail->next;
            ++currentLength;
        }
        return l;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1 = getLength(l1);
        int length2 = getLength(l2);
        int length3 = max(length1, length2);
        l1 = paddingZeroes(l1, length3, length1);
        l2 = paddingZeroes(l2, length3, length2);
        ListNode* sumhead = new ListNode();
        sumhead = paddingZeroes(sumhead, length3 + 1, 1);
        ListNode* ptr0 = l1;
        ListNode* ptr1 = l2;
        ListNode* ptrsum = sumhead;
        while (ptr0) {
            ptrsum->val += ptr0->val + ptr1->val;
            if (ptrsum->val >= 10) {
                ++ptrsum->next->val;
                ptrsum->val -= 10;
            }
            ptr0 = ptr0->next;
            ptr1 = ptr1->next;
            ptrsum = ptrsum->next;
        }
        ListNode* temp = sumhead;
        while (temp->next->next) {
            temp = temp->next;
        }
        if (temp->next->val == 0) {
            delete temp->next;
            temp->next = nullptr;
        }
        return sumhead;
    }
};