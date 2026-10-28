class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (mp.find(value) == mp.end()) {
            return 0;
        }

        vector<int>& indices = mp[value];

        auto l = lower_bound(indices.begin(), indices.end(), left);
        auto r = upper_bound(indices.begin(), indices.end(), right);

        return r - l;
    }
};