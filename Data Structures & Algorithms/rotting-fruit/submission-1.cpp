class Solution {
public:
    using pii = pair<int,int>;
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        int time = 0;
        queue<pii> q;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]==2) q.push({i,j});

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+dx[k], nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                        q.push({ni,nj});
                        grid[ni][nj] = 2;
                    }
                }
            }
            time++;
        }

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]==1) return -1;

        return time-1<0? 0 : time-1;
    }
};
