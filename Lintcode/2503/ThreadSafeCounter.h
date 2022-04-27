#include <iostream>
#include <mutex>

using namespace std;

class ThreadSafeCounter {
private:
    int i;
    // write your code
    mutex mu;
public:
    ThreadSafeCounter() {
        i = 0;
        // write your code

    }

    void incr(int increase(int)) {
        // write your code
        lock_guard<mutex> guard(mu);
        i = increase(i);
    }

    void decr(int decrease(int)) {
        // write your code
        lock_guard<mutex> guard(mu);
        i = decrease(i);
    }

    int getCount() {
        return i;
    }
};