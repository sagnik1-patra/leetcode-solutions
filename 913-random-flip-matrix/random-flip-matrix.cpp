class Solution {
public:
    int rows, cols;
    int remaining; 
    unordered_map<int, int> mapping; // maps chosen index to last available
    mt19937 rng;

    Solution(int m, int n) {
        rows = m;
        cols = n;
        remaining = m * n;
        mapping.clear();
        rng.seed(random_device{}()); // better randomness
    }
    
    vector<int> flip() {
        // pick a random index in [0, remaining-1]
        uniform_int_distribution<int> dist(0, remaining - 1);
        int r = dist(rng);

        // check if r was already remapped
        int idx = (mapping.count(r) ? mapping[r] : r);

        // update mapping: replace r with last available (remaining-1)
        int last = remaining - 1;
        mapping[r] = (mapping.count(last) ? mapping[last] : last);

        remaining--;

        return {idx / cols, idx % cols};
    }
    
    void reset() {
        remaining = rows * cols;
        mapping.clear();
    }
};
