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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto node1 = list1;
        auto node2 = list2;
        auto head = new ListNode();
        ListNode* curr = nullptr;
        while (node1 && node2) {
            if (node1->val < node2->val) {
                auto node = new ListNode(node1->val);
                if (curr) {
                    curr->next = node;
                    curr = curr->next;
                }
                else {
                    curr = node;
                    head->next = curr;
                }
                node1 = node1->next;
            }
            else {
                auto node = new ListNode(node2->val);
                if (curr) {
                    curr->next = node;
                    curr = curr->next;
                }
                else {
                    curr = node;
                    head->next = curr;
                }
                node2 = node2->next;
            }
        }
        while (node1) {
            auto node = new ListNode(node1->val);
            if (curr) {
                curr->next = node;
                curr = curr->next;
            }
            else {
                curr = node;
                head->next = curr;
            }
            node1 = node1->next;
        }
        while (node2) {
            auto node = new ListNode(node2->val);
            if (curr) {
                curr->next = node;
                curr = curr->next;
            }
            else {
                curr = node;
                head->next = curr;
            }
            node2 = node2->next;
        }
        return head->next;
    }
};