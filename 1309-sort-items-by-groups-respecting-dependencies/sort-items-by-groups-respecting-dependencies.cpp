class Solution {
public:

    vector<int> topoSort(vector<vector<int>>& graph, vector<int>& indeg){
        queue<int> q;
        vector<int> res;

        for(int i = 0; i < indeg.size(); i++)
            if(indeg[i] == 0) q.push(i);

        while(!q.empty()){
            int u = q.front(); q.pop();
            res.push_back(u);

            for(int v : graph[u]){
                if(--indeg[v] == 0)
                    q.push(v);
            }
        }

        if(res.size() != graph.size()) return {};
        return res;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        // Assign groups to -1 items
        for(int i = 0; i < n; i++){
            if(group[i] == -1)
                group[i] = m++;
        }

        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(m);

        vector<int> itemIndeg(n,0);
        vector<int> groupIndeg(m,0);

        // Build graphs
        for(int i = 0; i < n; i++){
            for(int prev : beforeItems[i]){

                itemGraph[prev].push_back(i);
                itemIndeg[i]++;

                if(group[i] != group[prev]){
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndeg[group[i]]++;
                }
            }
        }

        // Topo sort groups
        vector<int> groupOrder = topoSort(groupGraph, groupIndeg);
        if(groupOrder.empty()) return {};

        // Topo sort items
        vector<int> itemOrder = topoSort(itemGraph, itemIndeg);
        if(itemOrder.empty()) return {};

        // Put items into groups
        unordered_map<int, vector<int>> groupItems;

        for(int item : itemOrder)
            groupItems[group[item]].push_back(item);

        vector<int> result;

        for(int g : groupOrder)
            for(int item : groupItems[g])
                result.push_back(item);

        return result;
    }
};