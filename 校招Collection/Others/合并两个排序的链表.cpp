// https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode *Merge(ListNode *head1, ListNode *head2) {
        if (!head1) {
            return head2;
        } else if (!head2) {
            return head1;
        }

        int n1 = 0;
        auto tempNode1 = head1;
        while (tempNode1) {
            ++n1;
            tempNode1 = tempNode1->next;
        }

        int n2 = 0;
        auto tempNode2 = head2;
        while (tempNode2) {
            ++n2;
            tempNode2 = tempNode2->next;
        }

        int i1 = 0;
        int i2 = 0;
        int j = 0;
        tempNode1 = head1;
        tempNode2 = head2;
        auto newHead = new ListNode(0);
        auto tempNode3 = newHead;

        while ((i1 < n1) && (i2 < n2)) {
            if (tempNode1->val <= tempNode2->val) {
                tempNode3->val = tempNode1->val;
                tempNode1 = tempNode1->next;
                ++i1;
            } else {
                tempNode3->val = tempNode2->val;
                tempNode2 = tempNode2->next;
                ++i2;
            }
            ++j;
            tempNode3->next = new ListNode(0);
            tempNode3 = tempNode3->next;
        }

        while (i1 < n1) {
            tempNode3->val = tempNode1->val;
            if (i1 < n1 - 1) {
                tempNode3->next = new ListNode(0);
            }
            tempNode3 = tempNode3->next;
            ++i1;
            tempNode1 = tempNode1->next;
            ++j;
        }

        while (i2 < n2) {
            tempNode3->val = tempNode2->val;
            if (i2 < n2 - 1) {
                tempNode3->next = new ListNode(0);
            }
            tempNode3 = tempNode3->next;
            ++i2;
            tempNode2 = tempNode2->next;
            ++j;
        }
        return newHead;
    }
};