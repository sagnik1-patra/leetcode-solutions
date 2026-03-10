class FizzBuzz {
private:
    int n;
    int i = 1;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return i > n || (i%3==0 && i%5!=0); });

            if(i > n) return;

            printFizz();
            i++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return i > n || (i%5==0 && i%3!=0); });

            if(i > n) return;

            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return i > n || (i%3==0 && i%5==0); });

            if(i > n) return;

            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return i > n || (i%3!=0 && i%5!=0); });

            if(i > n) return;

            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};