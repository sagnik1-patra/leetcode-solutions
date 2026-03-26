class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        unordered_map<char,int> letter_count;
        for(char c : letters) letter_count[c]++;
        
        vector<unordered_map<char,int>> word_counters(n);
        vector<int> word_scores(n,0);
        
        for(int i=0;i<n;i++){
            for(char c : words[i]){
                word_counters[i][c]++;
                word_scores[i] += score[c - 'a'];
            }
        }
        
        function<int(int, unordered_map<char,int>&)> dfs = [&](int idx, unordered_map<char,int>& available){
            if(idx == n) return 0;
            
            int max_score = dfs(idx + 1, available); // skip
            
            bool can_take = true;
            for(auto &p : word_counters[idx]){
                if(available[p.first] < p.second){
                    can_take = false;
                    break;
                }
            }
            
            if(can_take){
                for(auto &p : word_counters[idx]) available[p.first] -= p.second;
                max_score = max(max_score, word_scores[idx] + dfs(idx + 1, available));
                for(auto &p : word_counters[idx]) available[p.first] += p.second; // backtrack
            }
            
            return max_score;
        };
        
        return dfs(0, letter_count);
    }
};