class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                  int veganFriendly,
                                  int maxPrice,
                                  int maxDistance) {
        
        vector<vector<int>> filtered;
        
        // Step 1: filter
        for (auto &r : restaurants) {
            int id = r[0], rating = r[1], vegan = r[2], price = r[3], dist = r[4];
            
            if (veganFriendly == 1 && vegan != 1) continue;
            if (price > maxPrice) continue;
            if (dist > maxDistance) continue;
            
            filtered.push_back(r);
        }
        
        // Step 2: sort
        sort(filtered.begin(), filtered.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) 
                return a[0] > b[0]; // higher id first
            return a[1] > b[1];     // higher rating first
        });
        
        // Step 3: extract ids
        vector<int> result;
        for (auto &r : filtered) {
            result.push_back(r[0]);
        }
        
        return result;
    }
};