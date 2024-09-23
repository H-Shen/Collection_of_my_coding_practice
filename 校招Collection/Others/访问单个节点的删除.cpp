// https://www.nowcoder.com/practice/6a668a3960e24d3ea04bba89109c6451

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode *pNode) {
        // write code here
        bool result{pNode && pNode->next};
        if (result) {
            auto currentNode{pNode};
            while (currentNode->next->next) {
                currentNode->val = currentNode->next->val;
                currentNode = currentNode->next;
            }
            currentNode->val = currentNode->next->val;
            currentNode->next = nullptr;
        }
        return result;
    }
};