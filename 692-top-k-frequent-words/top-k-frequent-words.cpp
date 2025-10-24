class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto &w : words)
            freq[w]++;

        // Custom comparator for priority queue (min-heap)
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second)
                return a.first < b.first; // lexicographically larger first → lower priority
            return a.second > b.second;   // smaller frequency → higher priority for removal
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);

        // Keep top k elements in heap
        for (auto &it : freq) {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(), result.end()); // because min-heap gives smallest first
        return result;
    }
};