class ZeroEvenOdd {
private:
    int n;
    int turn = 0;   // 0 = zero, 1 = odd, 2 = even
    int curr = 1;
    std::mutex mtx;
    std::condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return turn == 0; });

            printNumber(0);

            if (curr % 2 == 1)
                turn = 1;   // odd
            else
                turn = 2;   // even

            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return turn == 1 || curr > n; });

            if (curr > n) break;

            printNumber(curr);
            curr++;
            turn = 0;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&]{ return turn == 2 || curr > n; });

            if (curr > n) break;

            printNumber(curr);
            curr++;
            turn = 0;
            cv.notify_all();
        }
    }
};