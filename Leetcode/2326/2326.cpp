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
    vector<vector<int>> generateMatrix(int n, int m, vector<int>& vals) {
        vector<vector<int> > result(n, vector<int>(m, -1));
        int pos = 0;
        int dir = 0;    // right:0 down:1 left:2 up:3
        int total = n*m;
        int i = 0, j = 0;
        int length = (int)vals.size();
        while (pos < length) {
            result.at(i).at(j) = vals.at(pos);
            ++pos;
            if (dir == 0) {
                if (j==m-1 || result.at(i).at(j+1) != -1) {
                    dir = 1;
                    ++i;
                }
                else {
                    ++j;
                }
            }
            else if (dir == 1) {
                if (i==n-1 || result.at(i+1).at(j) != -1) {
                    dir = 2;
                    --j;
                }
                else {
                    ++i;
                }
            }
            else if (dir == 2) {
                if (j==0 || result.at(i).at(j-1) != -1) {
                    dir = 3;
                    --i;
                }
                else {
                    --j;
                }
            }
            else {
                if (i==0 || result.at(i-1).at(j) != -1) {
                    dir = 0;
                    ++j;
                }
                else {
                    --i;
                }
            }
        }
        return result;
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> vals;
        auto node = head;
        while (node) {
            vals.emplace_back(node->val);
            node = node->next;
        }
        return generateMatrix(m, n, vals);
    }
};