class Solution {
public:
    using pii = pair<int,int>;
    int n,m;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void bfs(vector<vector<int>>& v, vector<vector<int>>& h){
        queue<pii> q;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(v[i][j]==1) q.push({i,j});

        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dx[k], nj=j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && h[ni][nj]>=h[i][j] && v[ni][nj] == 0){
                    q.push({ni,nj});
                    v[ni][nj] = 1;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size(); m=heights[0].size();
        vector<vector<int>> p(n, vector<int>(m, 0));
        vector<vector<int>> a(n, vector<int>(m, 0));
        for(int i=0;i<m;i++) p[0][i] = 1;
        for(int i=0;i<n;i++) p[i][0] = 1;
        for(int i=0;i<m;i++) a[n-1][i] = 1;
        for(int i=0;i<n;i++) a[i][m-1] = 1;

        bfs(p, heights);
        bfs(a, heights);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] && p[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
