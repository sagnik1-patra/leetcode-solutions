class Solution {
public:
    vector<vector<int>> res;
    vector<int> disc, low;
    vector<vector<int>> graph;
    int time = 0;

    void dfs(int u, int parent){
        disc[u] = low[u] = time++;

        for(int v : graph[u]){

            if(v == parent) continue;

            if(disc[v] == -1){
                dfs(v, u);

                low[u] = min(low[u], low[v]);

                if(low[v] > disc[u])
                    res.push_back({u,v});
            }
            else{
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        graph.resize(n);
        disc.assign(n, -1);
        low.resize(n);

        for(auto &e : connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs(0, -1);

        return res;
    }
};