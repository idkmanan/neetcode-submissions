class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(vector<int>& prices, int i, bool buy, int price){
        if(i >= prices.size()) return 0;
        if(dp[i][buy][price] != -1) return dp[i][buy][price];

        if(buy){
            return dp[i][buy][price] = max(f(prices, i+1, 0, prices[i]), f(prices, i+1, 1, 0));
        }
        return dp[i][buy][price] = max(f(prices, i+2, 1, 0)+prices[i]-price, f(prices, i+1, 0, price));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        dp.resize(n, vector<vector<int>>(2, vector<int>(1001, -1)));

        return f(prices, 0, 1, 0);
    }
};
