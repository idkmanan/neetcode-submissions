class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int maxhl = height[l], maxhr = height[r];
        int ans = 0;
        while(l < r){
            if(maxhl < maxhr){
                ans += maxhl-height[l];
                l++;
                maxhl = max(maxhl, height[l]);
            } else {
                ans += maxhr-height[r];
                r--;
                maxhr = max(maxhr, height[r]);
            }
        }
        return ans;
    }
};
