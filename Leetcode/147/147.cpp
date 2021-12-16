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
    ListNode* insertionSortList(ListNode* head) {
        int n = 0;
        auto node = head;
        while (node) {
            ++n;
            node = node->next;
        }
        if (n <= 1) return head;
        auto curr = head->next;
        auto prev = head;
        int maxVal = head->val;
        for (int i = 1; i < n; ++i) {
            if (curr->val <= maxVal) {
                prev->next = curr->next;
                if (head->val >= curr->val) {
                    curr->next = head;
                    head = curr;
                }
                else {
                    auto tempPrev = new ListNode();
                    auto temp = head;
                    tempPrev->next = temp;
                    while (curr->val > temp->val) {
                        temp = temp->next;
                        tempPrev = tempPrev->next;
                    }
                    tempPrev->next = curr;
                    curr->next = temp;
                }
                curr = prev->next;
            }
            else {
                maxVal = max(maxVal, curr->val);
                curr = curr->next;
                prev = prev->next;
            }
        }
        return head;
    }
};