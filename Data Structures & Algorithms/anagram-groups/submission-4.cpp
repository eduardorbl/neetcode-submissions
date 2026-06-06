class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> listOfAnagrams;
        for (string s : strs) 
        {
            vector<int> freq(26,0);
            for (char c : s) freq[c-'a']++;
            string sortedS = "";
            for (int i = 0; i<26; i++) 
            {
                if (freq[i]>0) sortedS += static_cast<char>(i+'a');
            }
            listOfAnagrams[sortedS].push_back(s);
        }
        vector<vector<string>> ans;
        for (const auto& [_, strings]: listOfAnagrams)
        {
            vector<string> anagrams;
            for (string s : strings) anagrams.push_back(s);
            ans.push_back(anagrams);
        }
        return ans;
    }
};
