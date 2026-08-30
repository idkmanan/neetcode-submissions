class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<int>& prices, int i, int buy) {
        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {
            // Buy today OR skip
            return dp[i][buy] = max(
                -prices[i] + f(prices, i + 1, 0),
                f(prices, i + 1, 1)
            );
        }

        // Sell today OR hold
        return dp[i][buy] = max(
            prices[i] + f(prices, i + 2, 1),
            f(prices, i + 1, 0)
        );
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.assign(n, vector<int>(2, -1));

        return f(prices, 0, 1);
    }
};