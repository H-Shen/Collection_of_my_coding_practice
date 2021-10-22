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
    ListNode* sortLinkedList(ListNode* head) {
        constexpr int DIFF = 5000;
        constexpr int MAXN = 10001;
        int stats[MAXN]{};
        auto p = head;
        int length = 0;
        while (p) {
            ++stats[p->val + DIFF];
            ++length;
            p = p->next;
        }
        vector<ListNode*> vec(length);
        int index = 0;
        for (int i = 0; i < MAXN; ++i) {
            while (stats[i] > 0) {
                vec[index] = new ListNode(i - DIFF);
                ++index;
                --stats[i];
            }
        }
        for (int i = 0; i < length-1; ++i) {
            vec[i]->next = vec[i+1];
        }
        return vec[0];
    }
};