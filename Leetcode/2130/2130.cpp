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
constexpr int MAXN = 1e5+5;
int vec[MAXN];

class Solution {
public:
    int pairSum(ListNode* head) {
        auto node = head;
        int n = 0;
        while (node) {
            vec[n++] = node->val;
            node = node->next;
        }
        int maxSum = 0;
        for (int i = 0, j = n-1; i <= j; ++i, --j) {
            maxSum = max(maxSum, vec[i] + vec[j]);
        }
        return maxSum;
    }
};