class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return nums[0];
        int a = nums[0], b=max(nums[0], nums[1]), ans1=b;
        for(int i=2;i<n-1;i++){
            ans1 = max(a+nums[i], b);
            a = b;
            b = ans1;
        }
        if(n < 3) return ans1;
        
        a = nums[1]; b=max(nums[1], nums[2]);
        int ans2 = b;
        for(int i=3;i<n;i++){
            ans2 = max(b, a+nums[i]);
            a = b;
            b = ans2;
        }

        return max(ans1, ans2);
    }
};
