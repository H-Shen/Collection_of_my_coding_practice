// https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a

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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        auto ptr{pListHead};
        auto kth_ptr{pListHead};
        decltype(k) position{0};
        while (ptr) {
            if (position >= k) {
                kth_ptr = kth_ptr->next;
            }
            ptr = ptr->next;
            ++position;
        }
        return (position < k) ? nullptr : kth_ptr;
    }
};