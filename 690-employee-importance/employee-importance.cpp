class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // Step 1: Build a map from id -> Employee pointer
        unordered_map<int, Employee*> mp;
        for (auto e : employees)
            mp[e->id] = e;

        // Step 2: DFS to calculate total importance
        return dfs(mp, id);
    }

private:
    int dfs(unordered_map<int, Employee*>& mp, int id) {
        Employee* emp = mp[id];
        int total = emp->importance;
        for (int sub : emp->subordinates)
            total += dfs(mp, sub);
        return total;
    }
};