class RandomizedSet {
    vector<int> a;
    unordered_map<int, int> pos; // val -> index in a
    mt19937 rng;
public:
    RandomizedSet() : rng(random_device{}()) {}

    bool insert(int val) {
        if (pos.count(val)) return false;
        pos[val] = (int)a.size();
        a.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = pos.find(val);
        if (it == pos.end()) return false;
        int i = it->second;
        int lastVal = a.back();

        // move last to i
        a[i] = lastVal;
        pos[lastVal] = i;

        a.pop_back();
        pos.erase(it);
        return true;
    }

    int getRandom() {
        uniform_int_distribution<int> dist(0, (int)a.size() - 1);
        return a[dist(rng)];
    }
};
