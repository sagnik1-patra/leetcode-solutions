class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooTurn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]{ return fooTurn; });
            printFoo();          // prints "foo"
            fooTurn = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]{ return !fooTurn; });
            printBar();          // prints "bar"
            fooTurn = true;
            cv.notify_all();
        }
    }
};