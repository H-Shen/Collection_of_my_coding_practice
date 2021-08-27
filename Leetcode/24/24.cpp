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
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode();
        dummy->next = head;
        auto node = dummy;
        while (true) {
            if (node->next) {
                if (node->next->next) {
                    auto temp = node->next->next;
                    node->next->next = temp->next;
                    temp->next = node->next;
                    node->next = temp;
                    node = node->next->next;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }
        
        return dummy->next;
    }
};