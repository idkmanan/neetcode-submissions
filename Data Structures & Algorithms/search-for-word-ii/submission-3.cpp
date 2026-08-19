class TrieNode{
public:
    unordered_map<char, TrieNode*> ch;
    bool endOfWord = false;

    void addWord(const string& word){
        TrieNode* cur = this;
        for(char c : word){
            if(!cur->ch.count(c)) cur->ch[c] = new TrieNode();
            cur = cur->ch[c];
        }
        cur->endOfWord = true;
    }
};

class Solution {
public:
    unordered_set<string> ans;
    vector<vector<int>> vis;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int n,m;
    void dfs(vector<vector<char>>& b, int r, int c, TrieNode* node, string word){
        if(r<0 || r>=n || c<0 || c>=m || vis[r][c] || !node->ch.count(b[r][c])) return;

        vis[r][c] = 1;
        node = node->ch[b[r][c]];
        word += b[r][c];
        if(node->endOfWord) {ans.insert(word);}

        for(int k=0;k<4;k++) dfs(b, r+dx[k], c+dy[k],node, word);

        vis[r][c] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(); m=board[0].size();
        TrieNode* root = new TrieNode();
        for(const string& word : words) root->addWord(word);

        vis.resize(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board, i, j, root, "");
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
