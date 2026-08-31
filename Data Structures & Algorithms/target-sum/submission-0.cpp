class Solution {
public:
    map<pair<int,int>, int> dp;
    int f(int i, vector<int>& nums, int t, int sum){
        if(i==nums.size()){
            return sum==t;
        }

        if(dp.count({i,sum})) return dp[{i,sum}];

        return dp[{i,sum}] = f(i+1, nums, t, sum+nums[i]) + f(i+1, nums, t, sum-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(0, nums, target, 0);
    }
};
