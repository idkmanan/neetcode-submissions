class TimeMap {
public:
    unordered_map<string, vector<int>> mp;
    unordered_map<int, string> val;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(timestamp);
        val[timestamp] = value;    
    }
    
    string get(string key, int timestamp) {
        vector<int> v = mp[key];
        if(v.empty()) return "";

        auto idx = upper_bound(v.begin(), v.end(), timestamp) -v.begin() - 1;
        if(idx<0) return "";
        return val[v[idx]];
    }
};
