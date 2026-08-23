class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],x=nums[0];
        for(int i=1;i<n;i++){
            x = max(x+nums[i], nums[i]);
            ans=max(ans,x);
        }
        return ans;
    }
};
