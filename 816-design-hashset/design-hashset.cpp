class MyHashSet {
private:
    static const int SIZE = 1000;
    vector<vector<int>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(SIZE);
    }

    void add(int key) {
        int idx = hash(key);
        for (int x : buckets[idx])
            if (x == key) return;  // already present
        buckets[idx].push_back(key);
    }

    void remove(int key) {
        int idx = hash(key);
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int idx = hash(key);
        for (int x : buckets[idx])
            if (x == key) return true;
        return false;
    }
};
