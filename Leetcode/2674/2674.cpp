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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        int length = 0;
        auto node = list;
        unordered_set<ListNode*> vis;
        while (true) {
            if (vis.count(node) > 0) {
                break;
            }
            else {
                vis.insert(node);
                node = node->next;
                ++length;
            }
        }
        int halfLength = (length % 2 == 0) ? (length / 2) : (length / 2 + 1);
        vector<ListNode*> ans;
        ans.emplace_back(list);
        node = list;
        for (int i = 1; i < halfLength; ++i) {
            node = node->next;
        }
        auto list2 = node->next;
        node->next = list;

        node = list2;
        while (node->next != list) {
            node = node->next;
        }
        node->next = list2;
        ans.emplace_back(list2);
        return ans;
    }
};