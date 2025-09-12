Problem link: https://leetcode.com/problems/vowels-game-in-a-string/submissions/1768314220/?envType=daily-question&envId=2025-09-12
class Solution {
public:
    bool doesAliceWin(string s) {
        int ct=0;
        for(int i=0;i<s.length();i++){
             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                 ct++;
             }
        }
        if(ct==0) return 0;
        
        return 1;
    }
};
