class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> min_vector(n);
        min_vector[0] = prices[0];
        vector<int> max_vector(n);
        max_vector[n-1] = 0;
        for (int i = 1; i < n; i++)
        {
            min_vector[i] = min(min_vector[i-1], prices[i]);
            max_vector[n-i-1] = max(max_vector[n-i], prices[n-i]);
        }
        int max_profit = 0;
        for (int i = 0; i < n; i++)
        {
            int profit = max_vector[i] - min_vector[i];
            max_profit = max(max_profit, profit);
        }
        return max_profit;
    }
};
