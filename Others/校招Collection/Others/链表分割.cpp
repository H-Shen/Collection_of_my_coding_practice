// https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode *partition(ListNode *pHead, int x) {

        if (pHead) {
            vector<int> lessThanX;
            vector<int> notLessThanX;
            auto currentNode = pHead;
            while (currentNode) {
                if (currentNode->val < x) {
                    lessThanX.emplace_back(currentNode->val);
                } else {
                    notLessThanX.emplace_back(currentNode->val);
                }
                currentNode = currentNode->next;
            }
            currentNode = pHead;
            for (const int &i : lessThanX) {
                currentNode->val = i;
                currentNode = currentNode->next;
            }
            for (const int &i : notLessThanX) {
                currentNode->val = i;
                currentNode = currentNode->next;
            }
        }
        return pHead;
    }
};