class Solution {
public:
    int numberOfReplacements(vector<int> freq)
    {
        int sumTotal = 0;
        int maxFreq = 0;
        for (int i : freq)
        {
            sumTotal += i;
            maxFreq = max(maxFreq, i);
        }
        return sumTotal - maxFreq;
    }
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int n = s.size();
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++)
        {       
            freq[s[r] - 'A']++;   
            while (numberOfReplacements(freq) > k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
