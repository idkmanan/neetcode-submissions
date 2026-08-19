class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(int r, int c, vector<string>& v){
        for(int i=r-1;i>=0;i--){
            if(v[i][c]=='Q') return false;
        }
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) if(v[i][j]=='Q') return false;
        for(int i=r-1,j=c+1;i>=0&&j<v.size();i--,j++) if(v[i][j]=='Q') return false;

        return true;
    }
    void solve(int i,int n, vector<string>& v){
        if(i==n){
            ans.push_back(v);
            return;
        }

        for(int c=0;c<n;c++){
            if(isSafe(i,c,v)){
                v[i][c] = 'Q';
                solve(i+1, n, v);
                v[i][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) temp[i] += '.';
        solve(0, n, temp);
        return ans;
    }
};
