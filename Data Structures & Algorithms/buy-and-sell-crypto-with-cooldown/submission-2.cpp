class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n <= 1) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1;i>=0;i--){
            dp[i][1] = max(dp[i+1][0]-prices[i], dp[i+1][1]);
            dp[i][0] = max((i+2<=n?dp[i+2][1] : 0)+prices[i], dp[i+1][0]);
        }
        return dp[0][1];
    }
};
