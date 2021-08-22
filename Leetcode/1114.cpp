class Foo {
private:
    atomic<int> flag;
public:
    Foo() : flag(0) {

    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag.fetch_add(1);
    }

    void second(function<void()> printSecond) {
        while (flag.load() != 1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag.fetch_add(1);
    }

    void third(function<void()> printThird) {
        while (flag.load() != 2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};