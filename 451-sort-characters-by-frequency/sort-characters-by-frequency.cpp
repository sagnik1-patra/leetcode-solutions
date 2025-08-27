class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        freq.reserve(s.size());
        for (char c : s) ++freq[c];

        vector<pair<char,int>> items;
        items.reserve(freq.size());
        for (auto &kv : freq) items.push_back(kv);

        sort(items.begin(), items.end(),
             [](const auto& a, const auto& b){
                 return a.second > b.second; // higher frequency first
             });

        string res;
        res.reserve(s.size());
        for (auto &p : items) res.append(p.second, p.first);
        return res;
    }
};
