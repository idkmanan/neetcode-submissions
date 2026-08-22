class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({position[i],speed[i]});
        sort(v.rbegin(), v.rend());

        stack<double> st;
        for(int i=0;i<n;i++){
            double val = (double)(target-v[i].first)/v[i].second;
            if(st.empty()) st.push(val);
            else {
                if(st.top() >= val) continue;
                else st.push(val);
            }
        }
        return st.size();
    }
};
