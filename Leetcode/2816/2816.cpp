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
ListNode* add(vector<int>&a, vector<int>&b) {
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int lenA = (int)a.size();
    int lenB = (int)b.size();
    int lenC = max(lenA, lenB)+1;
    while ((int)a.size() < lenC) {
        a.emplace_back(0);
    }
    while ((int)b.size() < lenC) {
        b.emplace_back(0);
    }
    vector<int> c(lenC);
    for (int i = 0; i < lenC; ++i) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            c[i] -= 10;
            ++c[i+1];
        }
    }
    while ((int)c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }
    ListNode* node = nullptr;
    for (const auto &i : c) {
        auto newNode = new ListNode(i);
        newNode->next = node;
        node = newNode;
    }
    return node;
}
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> a;
        auto node = head;
        while (node) {
            a.emplace_back(node->val);
            node = node->next;
        }
        vector<int> b(a);
        return add(a, b);
    }
};