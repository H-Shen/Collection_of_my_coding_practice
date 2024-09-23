// https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca

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
    ListNode *ReverseList(ListNode *head) {
        if (!head || !(head->next)) {
            return head;
        }

        auto prev = head;
        auto curr = head->next;
        decltype(prev) temp;

        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = nullptr;
        return prev;
    }
};