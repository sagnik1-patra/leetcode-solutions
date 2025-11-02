class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Max heap: pair<frequency, character>
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, f] : freq)
            pq.push({f, ch});

        string result = "";
        pair<int, char> prev = {0, '#'}; // store previous char (cooldown)

        while (!pq.empty()) {
            auto [count, ch] = pq.top(); pq.pop();
            result += ch;
            count--;

            // Push back the previous char if it still has remaining count
            if (prev.first > 0)
                pq.push(prev);

            prev = {count, ch};
        }

        // If rearrangement failed (adjacent duplicates), result length < s length
        return result.size() == s.size() ? result : "";
    }
};
