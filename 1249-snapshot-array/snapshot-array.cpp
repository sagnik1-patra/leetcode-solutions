class SnapshotArray {
private:
    int snap_id;
    vector<vector<pair<int,int>>> history;

public:
    SnapshotArray(int length) {
        snap_id = 0;
        history.resize(length);
        
        // Initialize each index with snap 0, value 0
        for (int i = 0; i < length; i++) {
            history[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        // If last entry has same snap_id, overwrite
        if (history[index].back().first == snap_id) {
            history[index].back().second = val;
        } else {
            history[index].push_back({snap_id, val});
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id_query) {
        auto &vec = history[index];
        
        int left = 0, right = vec.size() - 1;
        
        // Binary search largest snap_id <= snap_id_query
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (vec[mid].first <= snap_id_query)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return vec[right].second;
    }
};
