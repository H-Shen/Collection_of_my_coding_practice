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

constexpr int MAXN = 2*1e5+5;

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int index = 0;
        vector<ListNode*> vec(MAXN);
        auto node = head;
        int val = -1;
        while (node) {
            if (node->val != 0) {
                if (val == -1) {
                    val = node->val;
                } else {
                    val += node->val;
                }
            }
            else {
                if (val != -1) {
                    vec[index++] = new ListNode(val);
                    val = -1;
                }
            }
            node = node->next;
        }
        if (val != -1) {
            vec[index++] = new ListNode(val);
        }
        if (index == 0) return nullptr;
        if (index == 1) return vec.front();
        for (int i = 0; i < index-1; ++i) {
            vec[i]->next = vec[i+1];
        }
        return vec[0];
    }
};