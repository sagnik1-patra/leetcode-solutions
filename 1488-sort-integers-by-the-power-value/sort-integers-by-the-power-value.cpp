class Solution {
public:
    unordered_map<int, int> memo;
    
    int power(int x) {
        if (x == 1) return 0;
        if (memo.count(x)) return memo[x];
        
        if (x % 2 == 0) {
            return memo[x] = 1 + power(x / 2);
        } else {
            return memo[x] = 1 + power(3 * x + 1);
        }
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> arr; // {power, value}
        
        for (int i = lo; i <= hi; i++) {
            arr.push_back({power(i), i});
        }
        
        sort(arr.begin(), arr.end());
        
        return arr[k - 1].second;
    }
};