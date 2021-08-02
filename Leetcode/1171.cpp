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
    bool f(const vector<pair<ListNode*, int> > v, int &s, int &e) {
        unordered_map<int, int> unmap;
        int n = (int)v.size();
        vector<int> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + v[i-1].second;
            if (pre[i] == 0) {
                s = 0;
                e = i-1;
                return true;
            }
            else if (unmap.find(pre[i]) != unmap.end()) {
                s = unmap[pre[i]];
                e = i-1;
                return true;
            }
            else {
                unmap[pre[i]] = i;
            }
        }
        return false;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<pair<ListNode*, int> > v;
        ListNode* node = head;
        while (node) {
            v.emplace_back(node, node->val);
            node = node->next;
        }
        int s, e;
        while (f(v, s, e)) {
            v.erase(v.begin()+s,v.begin()+e+1);
        }
        if (v.empty()) {
            return nullptr;
        }
        int n = (int)v.size();
        for (int i = 1; i < n; ++i) {
            v[i-1].first->next = v[i].first;
        }
        v.back().first->next = nullptr;
        return v[0].first;
    }
};