class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        if (nums.size() < k) return nums;
        int maxFreq = 0;
        for (int num : nums) {freq[num]++; maxFreq = max(maxFreq, freq[num]);}
        unordered_map<int, vector<int>> freqToNums;
        for (const auto& [number, frequency] : freq)
        {
            freqToNums[frequency].push_back(number);
        }
        vector<int> ans;
        int n = 0;
        for (int f = maxFreq; n < k; f--)
        {
            if (!freqToNums.contain()) continue;
            vector<int> numsWithF = freqToNums[f];
            for (int i = 0; i + n < k; i++) ans.push_back(numsWithF[i]); 
        }
        return ans;
    }
};
