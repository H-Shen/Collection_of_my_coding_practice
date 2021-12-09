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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        int counter = 0;
        auto node = head;
        while (node) {
            ++counter;
            node = node->next;
        }
        int cycle = counter / (m+n);
        int rest = counter % (m+n);
        auto beforeHead = new ListNode();
        beforeHead->next = head;
        node = beforeHead;
        for (int i = 0; i < cycle; ++i) {
            for (int j = 0; j < m; ++j) {
                node = node->next;
            }
            for (int j = 0; j < n; ++j) {
                node->next = node->next->next;
            }
        }
        if (rest <= m) {
            for (int i = 0; i < rest; ++i) {
                node = node->next;
            }
            node->next = nullptr;
        }
        else {
            for (int i = 0; i < m; ++i) {
                node = node->next;
            }
            node->next = nullptr;   
        }
        return head;
    }
};