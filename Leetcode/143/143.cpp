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
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        auto node(head);
        while (node) {
            dq.push_back(node);
            node = node->next;
        }
        ListNode* dummy = new ListNode();
        node = dummy;
        while (true) {
            if (dq.empty()) {
                node->next = nullptr;
                break;
            } else {
                node->next = dq.front();
                node = node->next;
                dq.pop_front();
            }
            if (dq.empty()) {
                node->next = nullptr;
                break;
            } else {
                node->next = dq.back();
                node = node->next;
                dq.pop_back();
            }
        }
    }
};