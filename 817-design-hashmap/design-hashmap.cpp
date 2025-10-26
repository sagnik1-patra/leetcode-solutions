class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<vector<pair<int, int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(SIZE);
    }

    void put(int key, int value) {
        int idx = hash(key);
        for (auto &p : buckets[idx]) {
            if (p.first == key) {   // key already exists → update
                p.second = value;
                return;
            }
        }
        buckets[idx].push_back({key, value}); // insert new
    }

    int get(int key) {
        int idx = hash(key);
        for (auto &p : buckets[idx]) {
            if (p.first == key)
                return p.second;
        }
        return -1; // not found
    }

    void remove(int key) {
        int idx = hash(key);
        auto &bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};
