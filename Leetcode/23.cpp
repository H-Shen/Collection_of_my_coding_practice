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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> vec;
        vector<int> lengths;
        int length;
        for (auto &i : lists) {
            if (i) {
                ListNode* ptr = i;
                length = 0;
                while (ptr) {
                    vec.emplace_back(ptr);
                    ptr = ptr->next;
                    ++length;
                }
                lengths.emplace_back(length);
            }
        }
        if (lengths.empty()) {
            return nullptr;
        }
        if (lengths.size() == 1) {
            return vec.front();
        }
        partial_sum(lengths.begin(), lengths.end(), lengths.begin());
        int n = (int)lengths.size();
        for (int i = 0; i < n - 1; ++i) {
            inplace_merge(
                vec.begin(), 
                vec.begin() + lengths.at(i), 
                vec.begin() + lengths.at(i + 1), 
                [](const auto &l, const auto &r) { return l->val < r->val; });
        }
        int nodes = (int)vec.size();
        for (int i = 0; i < nodes - 1; ++i) {
            vec.at(i)->next = vec.at(i + 1);
        }
        vec.at(nodes - 1)->next = nullptr;
        return vec.front();
    }
};