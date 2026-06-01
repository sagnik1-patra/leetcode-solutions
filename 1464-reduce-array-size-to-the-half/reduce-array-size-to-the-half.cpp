class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Step 1: count frequencies
        for (int x : arr) {
            freq[x]++;
        }
        
        // Step 2: store frequencies
        vector<int> counts;
        for (auto &p : freq) {
            counts.push_back(p.second);
        }
        
        // Step 3: sort descending
        sort(counts.begin(), counts.end(), greater<int>());
        
        int removed = 0, setSize = 0;
        int target = arr.size() / 2;
        
        // Step 4: greedy pick
        for (int c : counts) {
            removed += c;
            setSize++;
            
            if (removed >= target) break;
        }
        
        return setSize;
    }
};