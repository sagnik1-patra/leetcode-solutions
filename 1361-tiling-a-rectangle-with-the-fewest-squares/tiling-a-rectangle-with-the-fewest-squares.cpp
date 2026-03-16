class Solution {
public:
    
    int res;
    
    void dfs(vector<int>& h, int used, int n, int m){
        
        if(used >= res) return;
        
        int minH = INT_MAX, pos = -1;
        
        for(int i=0;i<m;i++){
            if(h[i] < minH){
                minH = h[i];
                pos = i;
            }
        }
        
        if(minH == n){
            res = min(res, used);
            return;
        }
        
        int end = pos;
        
        while(end < m && h[end] == minH)
            end++;
        
        int width = end - pos;
        
        for(int size = min(n - minH, width); size >= 1; size--){
            
            vector<int> next = h;
            
            for(int k=pos;k<pos+size;k++)
                next[k] += size;
            
            dfs(next, used+1, n, m);
        }
    }
    
    int tilingRectangle(int n, int m) {
        
        if(n > m) swap(n,m);
        
        res = n*m;
        
        vector<int> height(m,0);
        
        dfs(height,0,n,m);
        
        return res;
    }
};