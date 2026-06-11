class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 1) return 1;
        int maxSize = 1;
        vector<int> freq(128, 0);
        int l = 0;
        freq[s[0]]++;
        // freqz = 0, freqx = 1, freqy = 1, maxsize = 3
        for (int r = 1; r < n; r++)
        {
            while (freq[s[r]] > 0)
            {
                freq[s[l]]--;
                l++;
            }
            freq[s[r]]++;
            maxSize = max(maxSize, r-l+1);
        }
        return maxSize;
    }
};
