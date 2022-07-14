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
private:
    vector<int> vec;
public:
    Solution(ListNode* head) {
        srand(time(nullptr));
        auto node = head;
        while (node) {
            vec.emplace_back(node->val);
            node = node->next;
        }
    }
    
    int getRandom() {
        return vec[rand() % (int)vec.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */