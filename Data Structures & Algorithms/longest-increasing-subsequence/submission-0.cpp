class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;

        for(int i=0;i<n;i++){
            int l = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if(dp[l-1]<nums[i] && nums[i]<dp[l]){
                dp[l] = nums[i];
            }
        }

        int ans = 0;
        for(int l=0;l<=n;l++){
            if(dp[l]<INT_MAX) ans = l;
        }
        return ans;
    }
};
