// https://www.nowcoder.com/practice/b033062d346c4e42a7191b94164c1cd7

#include <bits/stdc++.h>

using namespace std;
constexpr int GAP = 3;

template <typename T>
class ListNode {
private:
    T val;
public:
    explicit ListNode(T val_) : val(val_), next(nullptr) {}
    ListNode* next;
    auto getVal() const {
        return val;
    }
};

template <typename T>
class circularLinkedList {
private:
    size_t size;
    ListNode<T>* head;
    ListNode<T>* tail;
public:
    circularLinkedList() : head(nullptr), tail(head), size(0){}
    auto insert(T data) {
        auto newNode = new ListNode<T>(data);
        // Case 1: the list is empty
        if (!head) {
            head = newNode;
            tail = head;
            ++size;
        }
        // Case 2: the list is not empty
        else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
            ++size;
        }
    }
    auto display(const int &gap) {
        auto currentNode = head;
        int counter = 1;
        bool firstItem = true;
        while (size > 0) {
            currentNode = currentNode->next;
            ++counter;
            if (counter == gap - 1) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << " ";
                }
                cout << currentNode->next->getVal();
                currentNode->next = currentNode->next->next;
                --size;
                counter = 0;
            }
        }
        cout << endl;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    int m, N;
    cin >> m;
    while (m--) {
        cin >> N;
        if (N == 1) {
            cout << 1 << endl;
        } else {
            auto obj = new circularLinkedList<int>();
            for (int i = 1; i <= N; ++i) {
                obj->insert(i);
            }
            obj->display(GAP);
            delete obj;
        }
    }

    return 0;
}