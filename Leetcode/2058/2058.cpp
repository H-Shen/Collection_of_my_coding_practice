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
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vec;
        auto node = head;
        while (node) {
            vec.emplace_back(node->val);
            node = node->next;
        }
        int n = (int)vec.size();
        vector<int> A;
        for (int i = 1; i < n-1; ++i) {
            if ( (vec[i] > vec[i-1] && vec[i] > vec[i+1]) || (vec[i] < vec[i-1] && vec[i] < vec[i+1]) ) {
                A.emplace_back(i);
            }
        }
        if (A.size() < 2) {
            return vector<int>{-1,-1};
        }
        sort(A.begin(),A.end());
        int maxDist = -1;
        int minDist = INF;
        int length = (int)A.size();
        if (length >= 2) {
            maxDist = max(maxDist, A.back() - A.front());
        }
        for (int i = 0; i < length-1; ++i) {
            minDist = min(minDist, A[i+1]-A[i]);
        }
        return vector<int>{minDist, maxDist};
    }
};