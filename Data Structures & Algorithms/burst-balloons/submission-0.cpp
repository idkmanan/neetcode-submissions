class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> num;
        num.push_back(1);
        for(int x : nums){
            num.push_back(x);
        }
        num.push_back(1);
        int n=num.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int l=n-2;l>=1;l--){
            for(int r=l;r<=n-2;r++){
                for(int i=l;i<=r;i++){
                    int coins = num[l-1] * num[i] * num[r+1];
                    coins += dp[l][i-1] + dp[i+1][r];
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        return dp[1][n-2];
    }
};
