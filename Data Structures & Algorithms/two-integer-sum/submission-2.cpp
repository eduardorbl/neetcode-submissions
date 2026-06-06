class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> numToIndex;
        for (int i = 0; i < nums.size(); i++) 
        {
            numToIndex[nums[i]].push_back(i);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (numToIndex.contains(target - nums[i]))
            {
                vector<int> targetIndex = numToIndex[target-nums[i]];
                for (int j : targetIndex) if (i!=j) return {i, j}; 
                
            }
        }
        return {}; 
    }
};
