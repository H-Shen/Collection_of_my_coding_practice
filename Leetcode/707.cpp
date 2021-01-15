class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
        Node() : Node(0) {}
    };
    Node* head;
    int length;
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(nullptr), length(0) {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= length) return -1;
        auto ptr = head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto newHead = new Node(val);
        newHead->next = head;
        head = newHead;
        ++length;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!head) {
            addAtHead(val);
        } else {
            auto newTail = new Node(val);
            auto ptr = head;
            while (ptr->next) {
                ptr = ptr->next;
            }
            ptr->next = newTail;
            ++length;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == length) {
            addAtTail(val);
        } else if (index > length) {
            return;
        } else if (index == 0) {
            addAtHead(val);
        } else {
            auto newNode = new Node(val);
            auto ptr = head;
            int currentIndex = 0;
            while (currentIndex + 1 < index) {
                ++currentIndex;
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            ++length;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) {
            auto ptr = head;
            ptr = ptr->next;
            delete head;
            head = ptr;
            --length;
        } else if (index == length - 1) {
            auto ptr = head;
            while (ptr->next->next) {
                ptr = ptr->next;
            }
            auto tempNode = ptr->next;
            delete tempNode;
            ptr->next = nullptr;
            --length;
        } else {
            auto ptr = head;
            int currentIndex = 0;
            while (currentIndex + 1 < index) {
                ++currentIndex;
                ptr = ptr->next;
            }
            auto tempNode = ptr->next;
            ptr->next = ptr->next->next;
            delete tempNode;
            --length;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */