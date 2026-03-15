class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        
        const int MOD = 1e9+7;
        
        long dp[5001][6][16] = {0};
        
        for(int j=0;j<6;j++)
            dp[1][j][1] = 1;
        
        for(int i=1;i<n;i++){
            
            for(int last=0; last<6; last++){
                
                for(int cnt=1; cnt<=rollMax[last]; cnt++){
                    
                    if(dp[i][last][cnt]==0) continue;
                    
                    for(int nxt=0;nxt<6;nxt++){
                        
                        if(nxt==last){
                            
                            if(cnt+1<=rollMax[last]){
                                dp[i+1][nxt][cnt+1] =
                                (dp[i+1][nxt][cnt+1] + dp[i][last][cnt]) % MOD;
                            }
                        }
                        else{
                            
                            dp[i+1][nxt][1] =
                            (dp[i+1][nxt][1] + dp[i][last][cnt]) % MOD;
                        }
                    }
                }
            }
        }
        
        long ans=0;
        
        for(int j=0;j<6;j++)
            for(int k=1;k<=rollMax[j];k++)
                ans=(ans+dp[n][j][k])%MOD;
        
        return ans;
    }
};