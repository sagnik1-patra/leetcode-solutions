class DiningPhilosophers {
private:
    mutex forks[5];
    counting_semaphore<4> room{4};

public:
    DiningPhilosophers() {}

    void wantsToEat(
        int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        room.acquire();

        forks[left].lock();
        forks[right].lock();

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

        forks[left].unlock();
        forks[right].unlock();

        room.release();
    }
};