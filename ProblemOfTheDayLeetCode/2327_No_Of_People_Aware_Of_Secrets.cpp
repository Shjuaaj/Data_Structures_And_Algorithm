Prob Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-09

class Solution {
    int mod= 1e9+7;
public:
    int peopleAwareOfSecret(int n, int d, int f) {
        vector<int> del(n+1,0);
        vector<int> frgt(n+1,0);
      if(d+1<=n)  del[d+1]=1;
       if(f+1<=n) frgt[f+1]=1;
        int day=2;
        int ans=1;
        while(day<=n){
           int curr= (del[day]+ del[day-1])%mod;
           del[day] = (mod+ (del[day]+ del[day-1])%mod - frgt[day])%mod;
            curr =( mod+ curr- frgt[day])%mod;
            ans = (mod+ ans- frgt[day])%mod;
            if(curr>0){
               ans  = (ans+ curr)%mod;
               if(f+day<=n){
                  frgt[f+day]= curr%mod; 
               }
               if(d+day<=n){
                   del[d+day]= curr%mod;
               }
            }
            day++;
        }
        return ans%mod;
        
    }
};


