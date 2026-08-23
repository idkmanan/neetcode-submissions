class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);

        int total = n+m;
        int half = (total+1)/2;

        int s=0,e=n;
        while(s<=e){
            int i = s + (e-s)/2;
            int j=half-i;
            int l1 = i<=0?INT_MIN:nums1[i-1], r1 = i>=n? INT_MAX : nums1[i];
            int l2 = j<=0? INT_MIN : nums2[j-1], r2 = j>=m? INT_MAX:nums2[j];

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 != 0) {
                    return max(l1, l2);
                }
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                e = i - 1;
            } else {
                s = i + 1;
            }
        }
        return 0.0;
    }
};
