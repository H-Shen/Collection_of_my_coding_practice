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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        constexpr int MAXN = 100005;
        bitset<MAXN> bs1, bs2;
        auto node(head);
        while (node) {
            if (!bs1[node->val]) {
                bs1[node->val] = true;
            }
            else if (!bs2[node->val]) {
                bs2[node->val] = true;
            }
            node = node->next;
        }
        ListNode* dummy = new ListNode(0, head);
        node = dummy;
        while (node->next) {
            if (bs1[node->next->val] && bs2[node->next->val]) {
                node->next = node->next->next;
            } else {
                node = node->next;
            }
        }
        return dummy->next;
    }
};