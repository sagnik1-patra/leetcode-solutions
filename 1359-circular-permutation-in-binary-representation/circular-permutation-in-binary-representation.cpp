class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        
        int size = 1 << n;
        vector<int> result;
        
        for(int i = 0; i < size; i++){
            int gray = i ^ (i >> 1);
            result.push_back(start ^ gray);
        }
        
        return result;
    }
};