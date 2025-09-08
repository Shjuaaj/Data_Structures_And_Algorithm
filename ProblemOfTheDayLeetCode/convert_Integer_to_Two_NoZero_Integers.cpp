Link: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/submissions/1763671015/?envType=daily-question&envId=2025-09-08


class Solution {
    public:
        vector<int> getNoZeroIntegers(int n) {
            int pos=1;
            int a= 0;
            int b=0;
    
            while(n>0){
                int rem= n%10;
                if(rem==0){
                  a+= pos*1;
                  b += pos*9;
                  n-=10;
                }else if(rem==1&&n>=10){
                 a+= pos*2;
                 b+= pos*9;
                 n -=10;
                }else{
                 a+= pos*(rem-1);
                 b+= pos*(1);
                }
                n =n/10;
                pos *=10;
            }
            return {a,b};
        }
    };