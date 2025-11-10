class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> countMap;

        for (string &cp : cpdomains) {
            int spacePos = cp.find(' ');
            int count = stoi(cp.substr(0, spacePos));
            string domain = cp.substr(spacePos + 1);

            // Split domain into subdomains
            countMap[domain] += count;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    string sub = domain.substr(i + 1);
                    countMap[sub] += count;
                }
            }
        }

        vector<string> result;
        for (auto &entry : countMap) {
            result.push_back(to_string(entry.second) + " " + entry.first);
        }

        return result;
    }
};