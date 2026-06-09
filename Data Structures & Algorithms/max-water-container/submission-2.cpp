class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int ans = min(heights[l], heights[r])*(r-l);
        while (l < r)
        {   
            while (l < r && heights[l] < heights[r])
            {
                l++; int value = min(heights[l], heights[r])*(r-l);
                ans = max(ans, value);
            }
            while (l < r && heights[l] >= heights[r])
            {
                r--; int value = min(heights[l], heights[r])*(r-l);
                ans = max(ans, value);
            }
        }
        return ans;
    }
};
