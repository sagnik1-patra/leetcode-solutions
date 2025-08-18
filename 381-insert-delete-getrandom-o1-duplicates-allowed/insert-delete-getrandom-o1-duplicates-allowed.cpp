class RandomizedCollection {
    vector<int> a;                                      // stores all values (with duplicates)
    unordered_map<int, unordered_set<int>> pos;         // val -> indices in 'a'
    mt19937 rng;

public:
    RandomizedCollection() : rng(random_device{}()) {}

    bool insert(int val) {
        bool isNew = (pos.find(val) == pos.end() || pos[val].empty());
        pos[val].insert((int)a.size());
        a.push_back(val);
        return isNew; // true if val wasn't present before
    }

    bool remove(int val) {
        auto it = pos.find(val);
        if (it == pos.end() || it->second.empty()) return false;

        // take any index of 'val' (amortized O(1))
        int i = *it->second.begin();
        it->second.erase(i);

        int lastIdx = (int)a.size() - 1;
        int lastVal = a.back();

        if (i != lastIdx) {
            // Move last element to position i
            a[i] = lastVal;

            // Update index set for lastVal: remove old position, add new
            auto &sLast = pos[lastVal];
            sLast.erase(lastIdx);
            sLast.insert(i);
        } else {
            // removing the last element; just update its index set
            pos[lastVal].erase(lastIdx);
        }

        a.pop_back();

        // Optional cleanup to keep map small
        if (it->second.empty()) pos.erase(it);

        return true;
    }

    int getRandom() {
        uniform_int_distribution<int> dist(0, (int)a.size() - 1);
        return a[dist(rng)];
    }
};
