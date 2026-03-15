class Solution {
public:
    int countVowelPermutation(int n) {
        
        const long MOD = 1e9 + 7;
        
        long a=1, e=1, i=1, o=1, u=1;
        
        for(int step=2; step<=n; step++){
            
            long na = (e + i + u) % MOD;
            long ne = (a + i) % MOD;
            long ni = (e + o) % MOD;
            long no = i % MOD;
            long nu = (i + o) % MOD;
            
            a = na;
            e = ne;
            i = ni;
            o = no;
            u = nu;
        }
        
        return (a+e+i+o+u) % MOD;
    }
};