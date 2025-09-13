Prob link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/submissions/1769043610/?envType=daily-question&envId=2025-09-13

class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26], maxVowel = 0, maxConso = 0;
        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            }
            else {
                maxConso = max(maxConso, freq[i]);
            }
        }
        return maxVowel + maxConso;
    }
};