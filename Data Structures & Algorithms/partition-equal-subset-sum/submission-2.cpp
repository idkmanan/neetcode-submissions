class Solution {
public:
    using ll = long long;
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0ll);
        if(sum%2) return 0;

        ll val = sum/2;
        vector<int> dp(val+1, 0);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            vector<int> ndp = dp;
            for(int j=1;j<=val;j++){
                if(j >= nums[i]) ndp[j] = (ndp[j] || dp[j-nums[i]]);
            }
            dp = ndp;
        }
        return dp[val];
    }
};
