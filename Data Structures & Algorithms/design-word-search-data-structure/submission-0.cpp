class TrieNode{
public:
    unordered_map<char, TrieNode*> mp;
    bool endOfWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(!cur->mp.count(c)) cur->mp[c] = new TrieNode();
            cur = cur->mp[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* cur = root;
        for(int i=j;i<word.size();i++){
            char c = word[i];
            if(c == '.'){
                for(auto child : cur->mp){
                    if(dfs(word, i+1, child.second)) return true;
                }
                return false;
            } else {
                if(!cur->mp.count(c)) return false;
                cur = cur->mp[c];
            }
        }
        return cur->endOfWord;
    }
};
