/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node* node = head;
        vector<Node*> nodes;
        do {
            nodes.emplace_back(node);
            node = node->next;
        } while (node != head);
        int n = (int)nodes.size();
        // find the lower bound of insertVal
        bool hasLowerBound = false;
        int diff = numeric_limits<int>::max();
        int lowerBoundPos = -1;
        for (int i = 0; i < n; ++i) {
            if (nodes[i]->val >= insertVal) {
                hasLowerBound = true;
                if (nodes[i]->val - insertVal < diff) {
                    diff = nodes[i]->val - insertVal;
                    lowerBoundPos = i;
                }
            }
        }
        if (hasLowerBound) {
            Node* newNode = new Node(insertVal);
            newNode->next = nodes[lowerBoundPos];
            if (lowerBoundPos == 0) {
                nodes[n-1]->next = newNode;
            }
            else {
                nodes[lowerBoundPos-1]->next = newNode;
            }
        }
        // if no lower bound is found, insertVal will be inserted after the LAST max element
        else {
            int maxValPos = -1;
            int maxVal = numeric_limits<int>::min();
            for (int i = 0; i < n; ++i) {
                if (nodes[i]->val >= maxVal) {
                    maxVal = nodes[i]->val;
                    maxValPos = i;
                }
            }
            Node* newNode = new Node(insertVal);
            nodes[maxValPos]->next = newNode;
            if (maxValPos == n-1) {
                newNode->next = nodes[0];
            }
            else {
                newNode->next = nodes[maxValPos+1];
            }
        }
        return head;
    }
};