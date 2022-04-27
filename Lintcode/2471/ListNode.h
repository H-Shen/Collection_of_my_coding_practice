#include <iostream>
#include <string>

using namespace std;

class ListNode {
private:
    int val;
    ListNode* next;
public:
    ListNode(int val, ListNode* next = NULL) {
        this->val = val;
        this->next = next;
    }
    int getData() {
        return val;
    }
    ListNode* getNext() {
        return next;
    }
    void setNext(ListNode* next) {
        this->next = next;
    }
    string static toString(ListNode* node) {
        string vals = "";
        while (node != NULL) {
            vals += to_string(node->getData());
            vals += "->";
            node = node->next;
        }
        vals += "null";
        return vals;
    }
};