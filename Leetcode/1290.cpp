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
    int getDecimalValue(ListNode* head) {
        auto cur = head;
        string s;
        while (cur) {
            if (cur->val == 1) {
                s.push_back('1');
            } else {
                s.push_back('0');
            }
            cur = cur->next;
        }
        return stoll(s, nullptr, 2);
    }
};