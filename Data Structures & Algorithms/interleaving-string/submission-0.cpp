class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size();
        if(m+n != s3.size()) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[n][m] = 1;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i < n && s1[i] == s3[i+j] && dp[i+1][j]) dp[i][j] = 1;
                if(j < m && s2[j]==s3[j+i] && dp[i][j+1]) dp[i][j] = 1;
            }
        }
        return dp[0][0];
    }
};
