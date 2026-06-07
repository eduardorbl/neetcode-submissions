class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size()-2; i++)
        {
            int start = i + 1; int end = nums.size()-1;
            while (start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == 0) 
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    end--; start++;
                } else if (sum < 0) start++;
                else end--;
            }
        }
        return ans;
    }
};
