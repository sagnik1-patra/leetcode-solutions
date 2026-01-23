class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int step = 1;

public:
    Foo() {}

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        printFirst();          // prints "first"
        step = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{ return step >= 2; });
        printSecond();         // prints "second"
        step = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{ return step >= 3; });
        printThird();          // prints "third"
    }
};