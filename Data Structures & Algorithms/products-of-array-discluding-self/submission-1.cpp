class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prodLeft = 1;
        int prodRight = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i]=prodLeft;
            nums[nums.size()-1-i]*=prodRight;
            prodLeft *= nums[i];
            prodRight *= nums[nums.size()-1-i];
        }
        return nums;
    }
};
