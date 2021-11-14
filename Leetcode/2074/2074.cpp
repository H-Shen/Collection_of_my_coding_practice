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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        vector<ListNode*> vec;
        auto node = head;
        while (node) {
            vec.emplace_back(node);
            node = node->next;
        }
        int n = (int)vec.size();
        int group = 1;
        int sum = 0;
        vector<int> groups;
        while (true) {
            if (sum + group > n) {
                groups.emplace_back(n - sum);
                break;
            }
            sum += group;
            groups.emplace_back(group);
            if (sum == n) {
                break;
            }
            group += 1;
        }
        int l = 0, r = 0;
        int g = (int)groups.size();
        int length;
        for (int i = 1; i < g; ++i) {
            l = r+1;
            r = l+groups[i]-1;
            length = r-l+1;
            if (!(length & 1)) {
                reverse(vec.begin()+l,vec.begin()+r+1);
            }
        }
        for (int i = 0; i < n-1; ++i) {
            vec[i]->next = vec[i+1];
        }
        vec.back()->next = nullptr;
        return vec.front();
    }
};