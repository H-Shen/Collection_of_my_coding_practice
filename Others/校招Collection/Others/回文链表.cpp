// https://www.nowcoder.com/practice/baefd05def524a92bcfa6e1f113ed4f0

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode *pHead) {
        // write code here
        auto curr = pHead;
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

        auto reverseNode = pHead;
        int counter = 0;
        while (counter <= reversePosition) {
            reverseNode = reverseNode->next;
            ++counter;
        }

        auto p = reverseList(reverseNode);
        curr = pHead;
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