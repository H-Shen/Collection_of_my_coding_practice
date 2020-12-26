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
    ListNode* middleNode(ListNode* head) {
        auto ptr = head;
        int length = 0;
        while (ptr) {
            ++length;
            ptr = ptr->next;
        }
        int half = length / 2 + 1;
        ptr = head;
        while (--half) {
            ptr = ptr -> next;
        }
        return ptr;
    }
};