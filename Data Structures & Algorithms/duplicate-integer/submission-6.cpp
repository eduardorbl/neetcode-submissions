class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> setNums;
        for (int i : nums) if (setNums.contains(i)) {return true;} else setNums.insert(i);
        return false;
    }
};