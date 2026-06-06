class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setOfNums;
        for (int num : nums) setOfNums.insert(num);
        int max = 0;
        for (int num : nums)
        {
            if (setOfNums.contains(num-1)) continue;
            int n = num; int size = 1;
            while (setOfNums.contains(n+1)) {size++; n++;} 
            max = max(max, size);
        }
        return max;
    }
};
