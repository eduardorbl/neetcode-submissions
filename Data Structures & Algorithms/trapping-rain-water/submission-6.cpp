class Solution {
public:
    int trap(vector<int>& height) {
        // maximum value = min (max left, max right)
        // level = max(0, value)
        int n = height.size();
        if (n == 0) return 0;

        vector<int> vectorMaxLeft(n); vectorMaxLeft[0] = height[0];
        vector<int> vectorMaxRight(n); vectorMaxRight[n-1] = height[n-1];

        for (int i = 1; i < n; i++)
        {
            vectorMaxLeft[i] = max(vectorMaxLeft[i-1], height[i]);
            vectorMaxRight[n-i-1] = max(vectorMaxRight[n-i], height[n-i-1]);
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += min(vectorMaxLeft[i], vectorMaxRight[i]) - height[i];
        }
        return sum;
    }
};
