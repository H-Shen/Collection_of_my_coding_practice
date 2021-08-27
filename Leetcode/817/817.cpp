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
    int numComponents(ListNode* head, vector<int>& G) {
        constexpr int MAXN = 10005;
        bitset<MAXN> vis;
        for (const auto &i : G) vis[i] = true;
        int cc = 0;
        auto ptr = head;
        int counter = 0;
        while (ptr) {
            if (!vis[ptr->val]) {
                if (counter > 0) {
                    ++cc;
                    counter = 0;
                }
            } else {
                ++counter;
            }
            ptr = ptr->next;
        }
        if (counter > 0) {
            ++cc;
        }
        return cc;
    }
};