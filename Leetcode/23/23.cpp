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

struct Node {
    int val;
    int pos;
    Node() = default;
    Node(int val, int pos) : val(val), pos(pos) {}
    bool operator > (const Node& node) const {
        return val > node.val;
    }
};

class Solution {
public:
    // k-way merge with minHeap in O(k) + O(nlogk)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        priority_queue<Node, vector<Node>, greater<>> pq;
        int n = (int)lists.size();
        for (int i = 0; i < n; ++i) {
            if (lists[i]) {
                pq.push(Node(lists[i]->val,i));
            }
        }
        ListNode* head = new ListNode();
        ListNode* currentNode = nullptr;
        Node node;
        while (!pq.empty()) {
            node = pq.top();
            pq.pop();
            if (currentNode) {
                auto temp = new ListNode(node.val);
                currentNode->next = temp;
                currentNode = temp;
            }
            else {
                currentNode = new ListNode(node.val);
                head->next = currentNode;
            }
            if (lists[node.pos]->next) {
                lists[node.pos] = lists[node.pos]->next;
                pq.push(Node(lists[node.pos]->val, node.pos));
            } 
        }
        return head->next;
    }
};