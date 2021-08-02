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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* node = head;
        while (node) {
            ++n;
            node = node->next;
        }
        vector<ListNode*> ans;
        if (n < k) {
            int index = 0;
            node = head;
            for (; index < n; ++index) {
                ans.emplace_back(node);
                node = node->next;
            }
            while (index < k) {
                ans.emplace_back(nullptr);
                ++index;
            }
            for (auto &i : ans) {
                if (i) {
                    i->next = nullptr;
                }
            }
        }
        else {
            int length2 = n / k;
            int length1 = length2+1;
            int firstParts = n % k;
            int secondParts = k - firstParts;
            node = head;
            for (int i = 0; i < firstParts; ++i) {
                vector<ListNode*> temp;
                for (int j = 0; j < length1; ++j) {
                    temp.emplace_back(node);
                    node = node->next;
                }
                temp.back()->next = nullptr;
                ans.emplace_back(temp[0]);
            }
            for (int i = 0; i < secondParts; ++i) {
                vector<ListNode*> temp;
                for (int j = 0; j < length2; ++j) {
                    temp.emplace_back(node);
                    node = node->next;
                }
                temp.back()->next = nullptr;
                ans.emplace_back(temp[0]);
            }
        }
        return ans;
    }
};