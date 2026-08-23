class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> ms;
        vector<int> ans;
        int j=0,i=0;
        while(j<n){
            ms.insert(nums[j++]);
            if(ms.size() == k){
                ans.push_back(*ms.rbegin());
                ms.erase(ms.find(nums[i++]));
            }
        }
        return ans;
    }
};
