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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto node1(list1);
        int counter = 0;
        while (counter != a - 1) {
            node1 = node1->next;
            ++counter;
        }
        auto node2(list1);
        counter = 0;
        while (counter != b) {
            node2 = node2->next;
            ++counter;
        }
        auto node3(list2);
        while (node3->next) {
            node3 = node3->next;
        }
        node1->next = list2;
        node3->next = node2->next;
        return list1;
    }
};