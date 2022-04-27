#include "AbstractArrayList.h"
#include <mutex>

class ThreadSafeArrayList : public AbstractArrayList {
private:
    mutex mu;
public:
    ThreadSafeArrayList() : AbstractArrayList() {}

    virtual ~ThreadSafeArrayList() {}

    void append(int element) {
        // write your code
        lock_guard<mutex> guard(mu);
        AbstractArrayList::append(element);
    }

    int get(int index) {
        // write your code
        lock_guard<mutex> guard(mu);
        return AbstractArrayList::get(index);
    }
};