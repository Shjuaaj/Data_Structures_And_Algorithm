Prob Link: https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=daily-question&envId=2025-09-15

class Solution {
public:
    int canBeTypedWords(string text, string broken){
        unordered_set<char> brokenKeys;
        int count = 0;

        for (auto& c : broken){
            brokenKeys.insert(c);
        }

        stringstream ss(text);
        string word;
        vector<string> words;

        while (ss >> word){
            words.push_back(word);
        }

        for (auto w : words)
        {
            for (char c : w)
            {
                if (brokenKeys.find(c) != brokenKeys.end())
                {
                    count++;
                    break;
                }
            }
        }

        return words.size() - count;
    }
};