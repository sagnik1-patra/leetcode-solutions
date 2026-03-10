class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        map<int,int> dp;
        dp[-1] = 0;

        for(int a : arr1){
            map<int,int> newdp;

            for(auto [prev, ops] : dp){

                // Option 1: keep arr1[i]
                if(a > prev){
                    if(!newdp.count(a) || newdp[a] > ops)
                        newdp[a] = ops;
                }

                // Option 2: replace with arr2
                auto it = upper_bound(arr2.begin(), arr2.end(), prev);

                if(it != arr2.end()){
                    int b = *it;
                    if(!newdp.count(b) || newdp[b] > ops + 1)
                        newdp[b] = ops + 1;
                }
            }

            dp = newdp;
            if(dp.empty()) return -1;
        }

        int ans = INT_MAX;
        for(auto [v,ops] : dp)
            ans = min(ans, ops);

        return ans;
    }
};