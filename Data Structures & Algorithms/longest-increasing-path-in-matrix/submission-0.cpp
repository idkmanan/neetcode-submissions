class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int dfs(int i, int j, vector<vector<int>>& mat){
        if(dp[i][j] != -1) return dp[i][j];

        int res = 1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && (mat[ni][nj] > mat[i][j])){
                res = max(res, 1+dfs(ni,nj,mat));
            }
        }
        return dp[i][j] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(),n=matrix[0].size();
        dp.resize(m, vector<int>(n, -1));
        
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dfs(i,j,matrix));
            }
        }

        return ans;
    }
};
