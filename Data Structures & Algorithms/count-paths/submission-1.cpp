class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=1;i<=m;i++){
            vector<int> ndp(n+1, 0);
            for(int j=1;j<=n;j++){
                ndp[j] = ndp[j-1]+dp[j];
            }
            dp = ndp;
        }
        return dp[n];
    }
};
