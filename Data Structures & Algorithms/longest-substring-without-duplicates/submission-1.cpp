class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 1) return 1;
        int maxSize = 0;
        vector<int> freq(128, 0);
        int l = 0; int r = 1;
        freq[0]++;
        while (l < n)
        {
            while (freq[s[r]] > 0)
            {
                freq[s[l]]--;
                l++;
            }
            if (r < n)
            {
                freq[s[r]]++;
                r++;
            }
            maxSize = max(maxSize, r-l+1);
        }
        return maxSize;
    }
};
