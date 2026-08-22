class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int> r(10, 0), c(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    if(r[board[i][j]-'0'] > 0) return false;
                    else r[board[i][j]-'0']++;
                }

                if(board[j][i] != '.'){
                    if(c[board[j][i]-'0'] > 0) return false;
                    else c[board[j][i]-'0']++;
                }
            }
        }

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int> cnt(10,0);
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y] == '.') continue;
                        if(cnt[board[x][y]-'0'] > 0) return false;
                        cnt[board[x][y]-'0']++;
                    }
                }
            }
        }
        return true;
    }
};
