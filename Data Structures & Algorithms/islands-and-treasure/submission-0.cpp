class Solution {
public:
    using pii = pair<int,int>;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int INF = INT_MAX;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pii> q;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]==0) q.push({i,j});

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i, j] = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+dx[k], nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==INF){
                        q.push({ni,nj});
                        grid[ni][nj] = 1+grid[i][j];
                    }
                }
            }
        }
    }
};
