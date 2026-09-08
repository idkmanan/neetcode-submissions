class Solution {
public:
    int m, n;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    
    void dfs(int i, int j, vector<vector<char>>& board){
        board[i][j] = '#';
        for(int k=0;k<4;k++){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && board[ni][nj]=='O'){
                dfs(ni,nj, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m=board.size(); n=board[0].size();

        for(int i=0;i<m;i++){
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][n-1] == 'O') dfs(i, n-1, board);
        }

        for(int j=0;j<n;j++){
            if(board[0][j] == 'O') dfs(0, j, board);
            if(board[m-1][j] == 'O') dfs(m-1, j, board);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
