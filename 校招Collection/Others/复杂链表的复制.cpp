// https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode *Clone(RandomListNode *pHead) {
        auto p = pHead;
        auto t = pHead;
        while (p) {
            auto q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        while (t) {
            auto q = t->next;
            if (t->random) {
                q->random = t->random->next;
            }
            t = q->next;
        }
        auto s = new RandomListNode(0);
        auto s1 = s;
        while (pHead) {
            auto q = pHead->next;
            pHead->next = q->next;
            q->next = s->next;
            s->next = q;
            s = s->next;
            pHead = pHead->next;
        }
        return s1->next;
    }
};