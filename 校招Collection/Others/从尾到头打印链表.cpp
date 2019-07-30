// https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> result;
        auto currentNode = head;
        while (currentNode) {
            result.emplace_back(currentNode->val);
            currentNode = currentNode->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};