class Solution {
public:
    int n,m;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void dfs(int i,int j, vector<vector<char>>& grid){
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj] == '1'){
                dfs(ni,nj,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1') {ans++;dfs(i, j, grid);}
            }
        }
        return ans;
    }
};
