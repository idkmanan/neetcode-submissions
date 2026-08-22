class Solution {
public:
    using pii = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for(int& x : nums) cnt[x]++;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto& [x, freq] : cnt){
            pq.push({freq, x});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            auto [freq, x] = pq.top(); pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};
