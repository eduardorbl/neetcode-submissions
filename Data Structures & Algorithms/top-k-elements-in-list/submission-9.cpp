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
            if (!freqToNums.contains(f)) continue;
            for (int num : freqToNums[f])
            {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};
