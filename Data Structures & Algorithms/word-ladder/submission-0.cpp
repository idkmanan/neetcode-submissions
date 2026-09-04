class Solution {
public:
    bool check(string& a, string& b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]) cnt++;
        }
        return cnt==1;
    }
    unordered_map<string, vector<string>> adj;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        bool flag = 1;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            if(wordList[i] == endWord) flag = 0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(check(wordList[i], wordList[j])) adj[wordList[i]].push_back(wordList[j]);
            }
        }

        if(flag) return 0;

        unordered_set<string> st;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.insert(beginWord);

        while(!q.empty()){
            auto [u, d] = q.front();
            q.pop();
            if(u == endWord) return d;

            for(string& v : adj[u]){
                if(st.count(v)) continue;
                q.push({v, d+1});
                st.insert(v);
            }
        }

        return 0;
    }
};
