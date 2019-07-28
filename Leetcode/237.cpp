/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        if (node == nullptr || node->next == nullptr) {
            return;
        }

        // Since accessing the head of the linked list is not allowed,
        // a way to solve it is iteratively replacing the value of the current node with the value of next node, which takes O(n) steps.
        auto currentNode = node;
        while (currentNode->next->next != nullptr) {
            currentNode->val = currentNode->next->val;
            currentNode = currentNode->next;
        }
        currentNode->val = currentNode->next->val;
        currentNode->next = nullptr;
    }
};