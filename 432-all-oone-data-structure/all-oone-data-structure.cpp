class AllOne {
    struct Bucket {
        int cnt;
        unordered_set<string> keys;
        Bucket(int c = 0) : cnt(c) {}
    };

    list<Bucket> buckets;                        // counts in ascending order
    unordered_map<string, list<Bucket>::iterator> where; // key -> bucket

public:
    AllOne() {}

    void inc(string key) {
        if (!where.count(key)) {
            // new key with count = 1
            if (buckets.empty() || buckets.begin()->cnt != 1) {
                buckets.insert(buckets.begin(), Bucket(1));
            }
            buckets.begin()->keys.insert(key);
            where[key] = buckets.begin();
        } else {
            auto it = where[key];
            int c = it->cnt;
            auto nextIt = next(it);
            if (nextIt == buckets.end() || nextIt->cnt != c + 1) {
                nextIt = buckets.insert(nextIt, Bucket(c + 1));
            }
            nextIt->keys.insert(key);
            it->keys.erase(key);
            where[key] = nextIt;
            if (it->keys.empty()) buckets.erase(it);
        }
    }

    void dec(string key) {
        auto it = where[key];
        int c = it->cnt;

        if (c == 1) {
            // remove the key entirely
            it->keys.erase(key);
            where.erase(key);
            if (it->keys.empty()) buckets.erase(it);
        } else {
            auto prevIt = (it == buckets.begin()) ? buckets.end() : prev(it);
            if (it == buckets.begin() || prevIt->cnt != c - 1) {
                prevIt = buckets.insert(it, Bucket(c - 1));
            }
            prevIt->keys.insert(key);
            it->keys.erase(key);
            where[key] = prevIt;
            if (it->keys.empty()) buckets.erase(it);
        }
    }

    string getMaxKey() {
        if (buckets.empty()) return "";
        auto it = prev(buckets.end());
        return it->keys.empty() ? "" : *it->keys.begin();
    }

    string getMinKey() {
        if (buckets.empty()) return "";
        auto it = buckets.begin();
        return it->keys.empty() ? "" : *it->keys.begin();
    }
};