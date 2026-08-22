class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for(int& x : nums) s.insert(x);

        for(int num : nums){
            if(!s.count(num-1)){
                int len = 1;
                while(s.count(num+len)) len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
