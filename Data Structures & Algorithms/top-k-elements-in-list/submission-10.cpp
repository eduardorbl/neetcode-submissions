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
        for (int f = maxFreq; f>0 && ans.size() < k; f--)
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
