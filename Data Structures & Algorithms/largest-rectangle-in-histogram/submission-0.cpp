class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n), left(n);
        stack<int> sr, sl;
        for(int i=n-1;i>=0;i--){
            while(!sr.empty() && heights[sr.top()]>=heights[i]) sr.pop();
            if(sr.empty()) right[i] = n;
            else right[i] = sr.top();

            sr.push(i);
        }
        for(int i=0;i<n;i++){
            while(!sl.empty() && heights[sl.top()]>=heights[i]) sl.pop();
            if(sl.empty()) left[i] = -1;
            else left[i] = sl.top();

            sl.push(i);
        }

        int ans= 0;
        for(int i=0;i<n;i++){
            ans = max(ans, heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};
