#include "ListNode.h"
#include <mutex>
#include <thread>

class ThreadSafeLinkedList {
private:
    mutex mu;
    ListNode* list = nullptr;
public:
    void appendLeft(int element) {
        // write your code
        lock_guard<mutex> guard(mu);
        if (list) {
            ListNode* newHead = new ListNode(element);
            newHead->setNext(list);
            list = newHead;
        }
        else {
            list = new ListNode(element);
            list->setNext(nullptr);
        }
    }

    void appendRight(int element) {
        // write your code
        lock_guard<mutex> guard(mu);
        if (list) {
            ListNode* node = list;
            while (true) {
                ListNode* temp = node;
                if (!temp->getNext()) {
                    break;
                }
                node = node->getNext();
            }
            ListNode* newTail = new ListNode(element);
            newTail->setNext(nullptr);
            node->setNext(newTail);
        }
        else {
            list = new ListNode(element);
            list->setNext(nullptr);
        }
    }

    ListNode* getLinkedList() {
        // write your code
        // return the first node of the linked list
        return list;
    }
};