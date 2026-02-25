class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        
        struct Tx {
            string name, city, original;
            int time, amount;
        };
        
        vector<Tx> arr;
        
        // Parse transactions
        for (string &t : transactions) {
            stringstream ss(t);
            string name, time, amount, city;
            
            getline(ss, name, ',');
            getline(ss, time, ',');
            getline(ss, amount, ',');
            getline(ss, city, ',');
            
            arr.push_back({
                name,
                city,
                t,
                stoi(time),
                stoi(amount)
            });
        }
        
        vector<bool> invalid(n, false);
        
        for (int i = 0; i < n; i++) {
            
            // Rule 1: amount > 1000
            if (arr[i].amount > 1000) {
                invalid[i] = true;
            }
            
            // Rule 2: check other transactions
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                if (arr[i].name == arr[j].name &&
                    arr[i].city != arr[j].city &&
                    abs(arr[i].time - arr[j].time) <= 60) {
                    
                    invalid[i] = true;
                }
            }
        }
        
        vector<string> result;
        for (int i = 0; i < n; i++) {
            if (invalid[i])
                result.push_back(arr[i].original);
        }
        
        return result;
    }
};