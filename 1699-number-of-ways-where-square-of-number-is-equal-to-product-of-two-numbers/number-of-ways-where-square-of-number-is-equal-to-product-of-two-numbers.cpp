class Solution {
public:
    long long countPairs(vector<int>& A, vector<int>& B) {
        unordered_map<long long, long long> freq;
        long long count = 0;
        
        for (long long y : B) {
            freq[y]++;
        }
        
        for (long long x : A) {
            long long target = x * x;
            
            unordered_map<long long, long long> seen;
            
            for (long long y : B) {
                if (target % y == 0) {
                    long long need = target / y;
                    
                    if (seen.count(need)) {
                        count += seen[need];
                    }
                }
                seen[y]++;
            }
        }
        
        return count;
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return countPairs(nums1, nums2) + countPairs(nums2, nums1);
    }
};