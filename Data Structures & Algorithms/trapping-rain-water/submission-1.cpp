class Solution {
public:
    int trap(vector<int>& height) {
        // maximum value = min (max left, max right)
        // level = max(0, value)
        int max_left = 0;
        int n = height.size();
        vector<int> vectorMaxLeft(n, 0);
        int max_right = 0;
        vector<int> vectorMaxRight(n, 0);
        for (int i = 0; i < n; i++)
        {
            vectorMaxLeft[i] = max_left;
            vectorMaxRight[n-i-1] = max_right;

            max_left = max(max_left, height[i]);
            max_right = max(max_right, height[n-i-1]);
        }
        vector<int> area(n, 0);
        for (int i = 0; i < n; i++)
        {
            area[i] = max(0, min(vectorMaxLeft[i], vectorMaxRight[i])-height[i]);
        }
        int sum = 0;
        for (int i : area)
        {
            sum += i;
        }
        return sum;
    }
};
