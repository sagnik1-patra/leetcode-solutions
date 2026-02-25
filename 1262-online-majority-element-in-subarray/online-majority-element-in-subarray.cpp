class MajorityChecker {
private:
    vector<int> arr;
    vector<pair<int,int>> seg; 
    // {candidate, count}
    unordered_map<int, vector<int>> positions;
    int n;
    
    // Build segment tree
    void build(int idx, int left, int right) {
        if (left == right) {
            seg[idx] = {arr[left], 1};
            return;
        }
        
        int mid = (left + right) / 2;
        build(2*idx, left, mid);
        build(2*idx+1, mid+1, right);
        
        auto L = seg[2*idx];
        auto R = seg[2*idx+1];
        
        if (L.first == R.first)
            seg[idx] = {L.first, L.second + R.second};
        else if (L.second > R.second)
            seg[idx] = {L.first, L.second - R.second};
        else
            seg[idx] = {R.first, R.second - L.second};
    }
    
    // Query segment tree
    pair<int,int> queryTree(int idx, int left, int right, int ql, int qr) {
        if (ql > right || qr < left)
            return {0, 0};
        
        if (ql <= left && right <= qr)
            return seg[idx];
        
        int mid = (left + right) / 2;
        auto L = queryTree(2*idx, left, mid, ql, qr);
        auto R = queryTree(2*idx+1, mid+1, right, ql, qr);
        
        if (L.first == R.first)
            return {L.first, L.second + R.second};
        else if (L.second > R.second)
            return {L.first, L.second - R.second};
        else
            return {R.first, R.second - L.second};
    }

public:
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        n = arr.size();
        seg.resize(4*n);
        
        build(1, 0, n-1);
        
        // Store positions for frequency check
        for (int i = 0; i < n; i++)
            positions[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) {
        auto candidate = queryTree(1, 0, n-1, left, right).first;
        
        if (candidate == 0) return -1;
        
        auto &vec = positions[candidate];
        
        // Count occurrences using binary search
        int l = lower_bound(vec.begin(), vec.end(), left) - vec.begin();
        int r = upper_bound(vec.begin(), vec.end(), right) - vec.begin();
        
        if (r - l >= threshold)
            return candidate;
        
        return -1;
    }
};