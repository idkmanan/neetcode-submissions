class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                string subs = s.substr(i, j-i+1);
                if(st.count(subs)) dp[i] = dp[i] || dp[j+1];
            }
        }
        return dp[0];
    }
};
