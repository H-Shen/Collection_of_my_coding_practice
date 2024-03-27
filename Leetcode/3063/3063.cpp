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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int,int> freq;
        auto p = head;
        while (p) {
            ++freq[p->val];
            p = p->next;
        }
        int k = (int)freq.size();
        vector<ListNode*> vec(k);
        auto it = freq.cbegin();
        for (int i = 0; i < k; ++i, ++it) {
            vec[i] = new ListNode(it->second);
        }
        for (int i = 0; i < k-1; ++i) {
            vec[i]->next = vec[i+1];
        }
        return vec.front();
    }
};