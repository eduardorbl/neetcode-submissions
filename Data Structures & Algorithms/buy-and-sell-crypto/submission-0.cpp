class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // min until index i -> retorna o minimo valor até o index i
        // max after index i -> retorna o maior valor depois do indice i
        // meu profit será max_vector[i] - min_vector[i]
        int min_v = prices[0]; int max_v = 1e9;
        int n = prices.size();
        vector<int> min_vector(n, 0);
        vector<int> max_vector(n, 0);
        for (int i = 0; i < n; i++)
        {
            min_vector[i] = min(min_v, min_vector[i]);
            max_vector[n-i-1] = max(max_v, max_vector[n-i-1]);
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
