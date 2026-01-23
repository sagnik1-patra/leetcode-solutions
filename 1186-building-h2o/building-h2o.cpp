class H2O {
private:
    sem_t hSem, oSem;
    std::mutex mtx;
    int count = 0;

public:
    H2O() {
        sem_init(&hSem, 0, 2); // allow 2 hydrogens
        sem_init(&oSem, 0, 1); // allow 1 oxygen
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&hSem);          // wait for hydrogen slot
        releaseHydrogen();        // print "H"
        bond();
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&oSem);          // wait for oxygen slot
        releaseOxygen();          // print "O"
        bond();
    }

private:
    void bond() {
        std::lock_guard<std::mutex> lock(mtx);
        count++;

        if (count == 3) {
            // reset for next molecule
            count = 0;
            sem_post(&hSem);
            sem_post(&hSem);
            sem_post(&oSem);
        }
    }
};