class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> ans;

        for (string name : names) {
            if (mp.find(name) == mp.end()) {
                ans.push_back(name);
                mp[name] = 1;
            } else {
                int k = mp[name];

                string newName;
                while (true) {
                    newName = name + "(" + to_string(k) + ")";

                    if (mp.find(newName) == mp.end()) {
                        break;
                    }

                    k++;
                }

                ans.push_back(newName);

                mp[name] = k + 1;
                mp[newName] = 1;
            }
        }

        return ans;
    }
};