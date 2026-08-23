class Solution {
public:
    using pii = pair<int,pair<int,int>>;
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()){
            auto [t, p] = pq.top(); pq.pop();
            auto [i,j] = p;
            if(dist[i][j] != t) continue;
            if(i==n-1 && j==n-1) return t;
            for(int k=0;k<4;k++){
                int ni=i+dx[k], nj=j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n && dist[ni][nj]==INT_MAX){
                    dist[ni][nj] = max({t,grid[i][j],grid[ni][nj]});
                    pq.push({dist[ni][nj], {ni,nj}});
                }
            }
        }
        return INT_MAX;
    }
};
