class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> indeg(numCourses, 0);
        for(auto& p : prerequisites){
            indeg[p[0]]++;
            mp[p[1]].push_back(p[0]);
        }

        queue<int> q;
        for(int i=0;i<numCourses; i++) if(indeg[i]==0) q.push(i);

        vector<int> ans;
        while(!q.empty()){
            int f = q.front(); q.pop();
            ans.push_back(f);
            for(auto& v : mp[f]){
                if(--indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        return (ans.size()==numCourses) ? ans : vector<int>();
    }
};
