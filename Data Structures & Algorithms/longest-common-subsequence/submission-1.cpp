class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        vector<int> dp(n+1, 0);
        for(int i=1;i<=m;i++){
            vector<int> ndp(n+1, 0);
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]) ndp[j] = dp[j-1] +1;
                else ndp[j] = max(ndp[j-1], dp[j]);
            }
            dp = ndp;
        }
        return dp[n];
    }
};
