class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> listOfAnagrams;
        for (string s : strs) 
        {
            vector<int> freq(26,0);
            for (char c : s) freq[c-'a']++;
            string sortedS = "";
            for (int i : freq) sortedS = static_cast<char>(i+'a');
            listOfAnagrams[sortedS].push_back(s);
        }
        vector<vector<string>> ans;
        index = 0;
        for (auto& pair p: listOfAnagrams)
        {
            for (string s : p.second) ans[index].push_back(s);
            index++;
        }
        return ans;
    }
};
