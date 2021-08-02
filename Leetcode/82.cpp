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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* node = head;
        int counter = 0;
        int lastVal;
        vector<ListNode*> vec;
        ListNode* p;
        while (node) {
            if (counter == 0) {
                counter = 1;
                p = node;
                lastVal = node->val;
                node = node->next;
                continue;
            }
            if (lastVal == node->val) {
                ++counter;
            }
            else {
                if (counter == 1) {
                    vec.emplace_back(p);
                }
                lastVal = node->val;
                counter = 1;
                p = node;
            } 
            node = node->next;
        }
        if (counter == 1) {
            vec.emplace_back(p);
        }
        if (vec.empty()) {
            return nullptr;
        }
        int n = (int)vec.size();
        for (int i = 1; i < n; ++i) {
            vec[i-1]->next = vec[i];
        }
        vec.back()->next = nullptr;
        return vec[0];
    }
};