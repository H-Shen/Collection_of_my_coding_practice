// https://www.nowcoder.com/practice/0cff324157a24a7a8de3da7934458e34

#include <iostream>

using namespace std;

struct ListNode {
    int m_nKey;
    ListNode *next = nullptr;

    ListNode(int key) : m_nKey(key) {}

    ListNode() {}
};

int main() {

    // create
    ListNode *head = new ListNode();
    ListNode *temp = head;
    for (int i = 1; i <= 7; ++i) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    // get length
    int length = 0;
    temp = head;
    while (temp->next) {
        ++length;
        temp = temp->next;
    }

    int k, pos;
    cin >> k;
    if (k >= 1 && k <= length) {
        pos = length - k + 1;
        temp = head;
        while (pos > 0) {
            temp = temp->next;
            --pos;
        }
        cout << temp->m_nKey << endl;
    }

    // release
    while (head) {
        temp = head;
        head = head->next;
        delete (temp);
    }

    return 0;
}
