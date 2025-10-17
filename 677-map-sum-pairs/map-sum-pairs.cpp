class MapSum {
private:
    unordered_map<string, int> mp; // stores the values for exact keys

public:
    MapSum() {}

    void insert(string key, int val) {
        mp[key] = val; // insert or update
    }

    int sum(string prefix) {
        int total = 0;
        for (auto& [key, val] : mp) {
            if (key.rfind(prefix, 0) == 0) // prefix match at position 0
                total += val;
        }
        return total;
    }
};
