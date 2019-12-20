/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

// https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa

class PalindromeList {
public:
    bool chkPalindrome(ListNode *A) {
        // write code here
        ListNode *curr = A;
        int length = 0;
        while (curr) {
            ++length;
            curr = curr->next;
        }

        // Exception
        if (length <= 1) {
            return true;
        }

        // a lambda function to reverse a linked list
        auto reverseList = [=](ListNode *head) -> ListNode * {

            if (!head || !head->next) {
                return head;
            }

            ListNode *prev = head;
            ListNode *curr = head->next;
            ListNode *temp;

            while (curr) {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            head->next = nullptr;
            return prev;
        };

        int reversePosition;
        if (length % 2 == 0) {
            reversePosition = length / 2 - 1;
        } else {
            reversePosition = length / 2;
        }

        ListNode *reverseNode = A;
        int counter = 0;
        while (counter <= reversePosition) {
            reverseNode = reverseNode->next;
            ++counter;
        }

        ListNode *p = reverseList(reverseNode);
        curr = A;
        while (p) {
            if (curr->val != p->val) {
                return false;
            }
            curr = curr->next;
            p = p->next;
        }
        return true;
    }
};
