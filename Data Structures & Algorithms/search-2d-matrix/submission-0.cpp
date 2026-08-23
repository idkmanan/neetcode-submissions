class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int s=0,e=m-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                return matrix[mid][lower_bound(matrix[mid].begin(), matrix[mid].end(), target)-matrix[mid].begin()] == target;
            } else {
                if(target < matrix[mid][0]) e = mid-1;
                else if(target > matrix[mid][n-1]) s = mid+1;
            }
        }
        return false;
    }
};
