class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int s=0,e=n-1,res=0;
        while(s<e){
            int mid = s+(e-s)/2;
            if(nums[mid] < nums[e]){
                e = mid;
            } else {
                s = mid+1;
            }
        }
        return nums[s];
    }
};
