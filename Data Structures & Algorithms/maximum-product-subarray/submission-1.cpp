class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int maxsf = nums[0];
        int minp = 1, maxp = 1;
        for(int i=0;i<n;i++){
            int temp = maxp*nums[i];
            maxp = max({maxp*nums[i], minp*nums[i], nums[i]});
            minp = min({nums[i], temp, minp*nums[i]});
            maxsf = max(maxsf, maxp);
        }
        return maxsf;
    }
};
