class Solution {
    public:
        long long minOperations(vector<vector<int>>& queries) {
            long long ans=0;
            int n= queries.size();
            for(int i=0;i<n;i++){
                int a= queries[i][0];
                int b= queries[i][1];
                double a1= a*1.0;
                double b1= b*1.0;
                int l= floor(log(a1)/log(4));
                int r= floor(log(b1)/log(4));
                l++;
                r++;
                long long ct=0;
                int prev= a;
                for(int k=l;k<=r;k++){
                    int curr= pow(4,k);
                    if(curr<=b){
                       
                       int diff= curr-prev;
                       ct += 1LL*diff*k;
                    }else{
                        curr= b;
                        int diff= curr-prev+1;
                        ct+= 1LL*diff*k;
    
                    }
                    prev= curr;
    
                }
                ct= ct/2 + (ct%2);
                ans= ans + 1LL*ct;
    
                
            }
            return ans;
        }
    };